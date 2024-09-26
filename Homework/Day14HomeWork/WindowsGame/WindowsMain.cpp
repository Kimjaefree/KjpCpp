#include "pch.h"


//전역변수:
HINSTANCE	_hInstance;
HWND		_hWnd;

ATOM		MyRegisterClass(HINSTANCE hInstance);
BOOL		InitInstance(HINSTANCE instance, int nCmdShow);
LRESULT		WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);
void		SetWindowSize(int x, int y, int width, int height);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	// 1. 윈도우클래스를 등록
	MyRegisterClass(hInstance);

	// 2. 윈도우를 생성
	if (false == InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	// 3. 윈도우 메세지 루프
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEXW);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOWFRAME);
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = _T("GameClient");
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	return ::RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	_hInstance = hInstance;

	HWND hWnd = CreateWindowW(_T("GameClient"), _T("GameClient"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	_hWnd = hWnd;

	if (!hWnd)
	{
		return FALSE;
	}

	SetWindowSize(WIN_START_X, WIN_START_Y, WIN_SIZE_X, WIN_SIZE_Y);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


void SetWindowSize(int x, int y, int width, int height)
{
	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	::AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, false);
	::SetWindowPos(_hWnd, nullptr, x, y, rc.right - rc.left, rc.bottom - rc.top, SWP_NOZORDER);
}

POINT mousePos = {};

class Enemy
{
public:
	RECT rc;
	bool isLive;

	void Die()
	{
		isLive = false;
	}
	void Draw(HDC hdc)
	{
		::Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}
	bool IsLive()
	{
		return isLive;
	}
};

vector<Enemy> enemies;
int killScore = 0;
LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int moleNum = 0;
	switch (message)
	{
	case WM_CREATE:
		// 윈도우가 생성되었을때 발생하는 이벤트
		// 여기에서 초기화 동작
		srand(time(NULL));

		//60프레임 -> 타이머호출주기
		SetTimer(hWnd, 1, 1000 / 60, NULL);

		//두더지 튀어나오기
		SetTimer(hWnd, 2, 1000, NULL);

		for (int i = 0; i < 9; i++)
		{
			Enemy mole;
			mole.isLive = false;
			mole.rc = {
				(i % 3) * 100 ,
				(i / 3) * 100,
				(i % 3) * 100 + 70,
				(i / 3) * 100 + 70
			};
			enemies.push_back(mole);
		}

		break;
		
	case WM_PAINT:
		{
			// 화면을 그리는 이벤트
			// 시작했을떄 호출한번되고, InvalidateRect라는 함수가 호출됐을때 한번 실행되고

			PAINTSTRUCT ps;
			HDC hdc = ::BeginPaint(hWnd, &ps);

			wstring killScoreStr = format(L"점수 : [{}]", killScore);
			Draw::Text(hdc, 1000, 0, killScoreStr);

			for (Enemy mole : enemies)
			{
				if (mole.IsLive())
				{
					mole.Draw(hdc);
				}
			}

			::EndPaint(hWnd, &ps);
		}
		break;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case 'A':
			for (Enemy& mole : enemies)
			{
				if (mole.rc.left <= mousePos.x && mousePos.x <= mole.rc.right)
				{
					if (mole.rc.top <= mousePos.y && mousePos.y <= mole.rc.bottom)
					{
						mole.Die();
						killScore++;
						printf("점수 : %d\n", killScore);
					}
				}
			}
			break;
		default:
			break;
		}
	}
		break;

	case WM_MOUSEMOVE:
	{
		mousePos.x = GET_X_LPARAM(lParam);
		mousePos.y = GET_Y_LPARAM(lParam);
	}
		break;

	case WM_TIMER:
		switch (wParam)
		{
		case 1:
			InvalidateRect(hWnd, NULL, true);
			break;

		case 2:
		{
			int rndIndex = rand() % 9; // 1번 두더지부터 9번 두더지 번호 매기기 위한 랜덤 인덱스
			if (!enemies[rndIndex].isLive) // enemies의 랜덤인덱스번호(두더지 번호)가 살아있지 않으면 
			{
				enemies[rndIndex].isLive = true; // 살아있다라고 만들어주기
				SetTimer(hWnd, (rndIndex + 1) * 100, 5000, NULL); // 5초 후에 들어가는 로직
			}

		}		
			break;

		case 100:
			moleNum = wParam / 100 - 1;
			enemies[moleNum].Die(); // 두더지 사망
			KillTimer(hWnd, wParam);
			break;
		case 200:
			moleNum = wParam / 100 - 1;
			enemies[moleNum].Die(); // 두더지 사망
			KillTimer(hWnd, wParam);
			break;
		case 300:
			moleNum = wParam / 100 - 1;
			enemies[moleNum].Die(); // 두더지 사망
			KillTimer(hWnd, wParam);
			break;
		case 400:
			moleNum = wParam / 100 - 1;
			enemies[moleNum].Die(); // 두더지 사망
			KillTimer(hWnd, wParam);
			break;
		case 500:
			moleNum = wParam / 100 - 1;
			enemies[moleNum].Die(); // 두더지 사망
			KillTimer(hWnd, wParam);
			break;
		case 600:
			moleNum = wParam / 100 - 1;
			enemies[moleNum].Die(); // 두더지 사망
			KillTimer(hWnd, wParam);
			break;
		case 700:
			moleNum = wParam / 100 - 1;
			enemies[moleNum].Die(); // 두더지 사망
			KillTimer(hWnd, wParam);
			break;
		case 800:
			moleNum = wParam / 100 - 1;
			enemies[moleNum].Die(); // 두더지 사망
			KillTimer(hWnd, wParam);
			break;
		case 900:
			moleNum = wParam / 100 - 1;
			enemies[moleNum].Die(); // 두더지 사망
			KillTimer(hWnd, wParam);
			break;
		default:
			break;
		}
		break;

	case WM_DESTROY:
		// 윈도우 종료 메세지가 왔을때 발생되는 이벤트
		::KillTimer(hWnd, 1);
		::PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}