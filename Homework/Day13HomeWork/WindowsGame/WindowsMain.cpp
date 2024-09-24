#include "pch.h"
#include "CommonFunction.h"

//전역변수:
HINSTANCE   _hInstance;
HWND      _hWnd;

ATOM      MyRegisterClass(HINSTANCE hInstance);
BOOL      InitInstance(HINSTANCE instance, int nCmdShow);
LRESULT      WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);

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

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

int keyDownNum; // 누른 키 값을 저장할 변수
LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        keyDownNum = 10; // 변수 초기화
        break;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case '0':
        case VK_NUMPAD0: // 0번 입력
            keyDownNum = 0; // keyDownNum에 0의 값을 넣어주어 아래 조건에 사용
            printf("1단부터 9단까지 출력.\n"); // 0이 눌렸을때 콘솔창에서 출력될 문구
            ::InvalidateRect(hWnd, nullptr, true); //InvalidateRect 함수로 한 번더 호출해주기
            break;
        case '1': // 위 주석과 동일
        case VK_NUMPAD1:
            keyDownNum = 1;
            printf("1단 출력.\n");
            ::InvalidateRect(hWnd, nullptr, true);
            break;

        case '2':
        case VK_NUMPAD2:
            keyDownNum = 2;
            printf("2단 출력.\n");
            ::InvalidateRect(hWnd, nullptr, true);
            break;
        case '3':
        case VK_NUMPAD3:
            keyDownNum = 3;
            printf("3단 출력.\n");
            ::InvalidateRect(hWnd, nullptr, true);
            break;
        case '4':
        case VK_NUMPAD4:
            keyDownNum = 4;
            printf("4단 출력.\n");
            ::InvalidateRect(hWnd, nullptr, true);
            break;
        case '5':
        case VK_NUMPAD5:
            keyDownNum = 5;
            printf("5단 출력.\n");
            ::InvalidateRect(hWnd, nullptr, true);
            break;
        case '6':
        case VK_NUMPAD6:
            keyDownNum = 6;
            printf("6단 출력.\n");
            ::InvalidateRect(hWnd, nullptr, true);
            break;
        case '7':
        case VK_NUMPAD7:
            keyDownNum = 7;
            printf("7단 출력.\n");
            ::InvalidateRect(hWnd, nullptr, true);
            break;
        case '8':
        case VK_NUMPAD8:
            keyDownNum = 8;
            printf("8단 출력.\n");
            ::InvalidateRect(hWnd, nullptr, true);
            break;
        case '9':
        case VK_NUMPAD9:
            keyDownNum = 9;
            printf("9단 출력.\n");
            ::InvalidateRect(hWnd, nullptr, true);
            break;
        default:
            break;
        }
        break;

    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = ::BeginPaint(hWnd, &ps);

        if (keyDownNum == 0) // 키보드의 0번 키가 눌렸을 때
        {
            // 1 ~ 9 단까지 출력
            for (int i = 1; i <= 9; i++)
            {
                for (int j = 1; j <= 9; j++)
                {
                    wstring str = format(L"{} x {} = {}", i, j, i * j); // cout과 동일
                    int x = 100 + ((i - 1) % 3) * 200; // 출력 될 x좌표 (100, 300, 500) 
                    int y = 20 + ((i - 1) / 3) * 250; // 출력 될 y좌표

                    y += j * 20;
                    ::TextOut(hdc, x, y, str.c_str(), str.length());
                }
            }
        }
        else if (keyDownNum >= 1 && keyDownNum <= 9) // 1~9 번을 누르면 각각의 단을 출력
        {
            for (int j = 1; j <= 9; j++)
            {
                wstring str = format(L"{} x {} = {}", keyDownNum, j, keyDownNum * j); // cout과 동일
                int x = 320; // 그려질 x 좌표
                int y = 320 + j * 20; // 그려질 y좌표 (j*20)은 글자가 겹치지 않기 위해서 추가
                ::TextOut(hdc, x, y, str.c_str(), str.length()); // 글자 화면에 출력
            }
        }
        ::EndPaint(hWnd, &ps); // 그리기 끝내기
        break;
    }

    case WM_DESTROY:
        // 윈도우 종료 메세지가 왔을때 발생되는 이벤트
        ::PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return DefWindowProc(hWnd, message, wParam, lParam);
}