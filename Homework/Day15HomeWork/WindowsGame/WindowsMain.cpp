#include "pch.h"
#include "CommonFunction.h"
#include <iostream>

//전역변수:
HINSTANCE   _hInstance;
HWND      _hWnd;

ATOM      MyRegisterClass(HINSTANCE hInstance);
BOOL      InitInstance(HINSTANCE instance, int nCmdShow);
LRESULT      WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lparam);
void      SetWindowSize(int x, int y, int width, int height);

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

RECT rc1; // 첫번째 사각형
RECT rc2; // 두번째 사각형
RECT player; // 세번째 사각형
bool isPlayerHit = Collision::RectInRect(player, rc1); // 충돌확인 숙제 1번
bool isRc1Hit = Collision::RectInRect(rc1, rc2); // 충돌확인 숙제 2번
bool isRc2Hit = Collision::RectInRect(player, rc2); // 충돌확인 숙제 3번
int gameMode;

// 숙제 1. 
//  - 플레이어의 RECT가 상하좌우 최대로 움직였을때, 그걸 감싸고있는 RECT를 벗어나려고하면 
//    같이 움직인다.


// 숙제 2.
//  - 큰네모랑 플레이어랑 같이 움직이다가 다른 큰네모랑 충돌하게되면
//    플레이어의 RECT가 다른 큰 네모의 가운데로 순간이동한다.

// 숙제 3.
//  - 다른 솔루션으로 진행하셔도되고, (숙제1,과 2랑은 같은화면에 하기힘들거같아요)
//  - 게임모드를 정해서 1번키 누르면 숙제 1,2 씬
//                    2번키 누르면 숙제 3번 씬



LRESULT WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        // 윈도우가 생성되었을때 발생하는 이벤트
        // 여기에서 초기화 동작
        srand(time(NULL));

        gameMode = 0;
        rc1 = { 100, 100, 600,  600 }; // 1번 사각형

        rc2 = { 900, 100, 1200,  400 }; // 2번 사각형

        player = { 200, 200, 250, 250 }; // 플레이어

        SetTimer(hWnd, 1, 1000 / 60, NULL); // 60 프래임 타이머

        break;

        // 화면 그리는 case
    case WM_PAINT:
    {
        // 화면을 그리는 이벤트
        // 시작했을떄 호출한번되고, InvalidateRect라는 함수가 호출됐을때 한번 실행되고

        PAINTSTRUCT ps;
        HDC hdc = ::BeginPaint(hWnd, &ps);

        // 게임모드 번호에 따라서 1, 2, 3번 숙제 씬 그리기
        if (gameMode == 1)
        {
            Draw::Rectangle(hdc, rc1);
            Draw::Rectangle(hdc, player);
        }
        else if (gameMode == 2)
        {
            Draw::Rectangle(hdc, rc1);
            Draw::Rectangle(hdc, rc2);
            Draw::Rectangle(hdc, player);
        }
        else if (gameMode == 3)
        {
            Draw::Rectangle(hdc, rc2);
            Draw::Rectangle(hdc, player);
        }

        ::EndPaint(hWnd, &ps);
    }
    break;

    // 키가 눌렸을때 case
    case WM_KEYDOWN:
        switch (wParam)
        {
         // 1번키가 눌렸을 때
        case '1' :
        case VK_NUMPAD1:
            // 게임모드 값을 1으로 설정 
            gameMode = 1;
            // 사용하지 않는 사각형 제거
            rc1 = { 100, 100, 600,  600 }; // 1번 사각형
            rc2 = { 0, 0, 0,  0}; // 2번 사각형
            player = { 200, 200, 250, 250 };
            // 1번숙제 씬 사각형들 출력
            InvalidateRect(hWnd, NULL, true);
            UpdateWindow(hWnd);
        break;

        case '2':
        case VK_NUMPAD2:
            gameMode = 2;
            printf("게임모드 2번\n");
            rc1 = { 100, 100, 600,  600 }; // 1번 사각형
            rc2 = { 900, 100, 1200,  400 }; // 2번 사각형
            player = { 200, 200, 250, 250 };
            InvalidateRect(hWnd, NULL, true);
            UpdateWindow(hWnd);
        break;

        case '3':
        case VK_NUMPAD3:
            gameMode = 3;
            rc1 = { 0, 0, 0,  0 };
            rc2 = { 900, 100, 1200,  400 }; // 2번 사각형
            player = { 200, 200, 250, 250 };
            printf("게임모드 3번\n");
            InvalidateRect(hWnd, NULL, true);
            UpdateWindow(hWnd);
        break;

        case VK_UP:
        {
            player.top -= 5;
            player.bottom -= 5;

            isPlayerHit = false;
            isRc1Hit = false;
            isRc2Hit = false;
            isPlayerHit = Collision::RectInRect(player, rc1);
            isRc1Hit = Collision::RectInRect(rc1, rc2);
            isRc2Hit = Collision::RectInRect(player, rc2);

            if (isPlayerHit)
            {
                // 1번숙제 로직 플레이어 사각형과 rc1 사각형이 충동했을때 플레이어와 rc1 사각형이 같이 움직이기
                if (player.top == rc1.top - 5)
                {
                    rc1.top -= 5;
                    rc1.bottom -= 5;
                }
                // 2번숙제 로직 플레이어와 rc1 사각형이 충돌해서 같이 움직이다가
                // rc1 사각형이 rc2 사각형이 충돌하면 rc2 사각형 정중앙으로 플레이어 사각형 이동
                if (isRc1Hit)
                {
                    player = { 1025, 225, 1075, 275 };
                }
            }
            else if (isRc2Hit) // 3번숙제 player 사각형이 rc2 사각형과 충돌하면 rc2 사각형 밀고다니기
            {
                if (player.top == rc2.bottom - 5)
                {
                    rc2.top -= 5;
                    rc2.bottom -= 5;
                }
            }
            InvalidateRect(hWnd, NULL, true);
        }
        break;
        case VK_RIGHT:
        {
            player.left += 5;
            player.right += 5;

            isPlayerHit = false;
            isRc1Hit = false;
            isRc2Hit = false;
            isPlayerHit = Collision::RectInRect(player, rc1);
            isRc1Hit = Collision::RectInRect(rc1, rc2);
            isRc2Hit = Collision::RectInRect(player, rc2);

            // 플레이어 사각형이 충돌했을 때
            if (isPlayerHit)
            {
                // 1번숙제 움직임 로직
                if (player.right == rc1.right + 5) // 5를 더해준 이유는 선이 완전히 맞닿았을때 움직여지게 만들어주는 로직 
                {
                    rc1.right += 5;
                    rc1.left += 5;
                }

                if (isRc1Hit)
                {
                    player = { 1025, 225, 1075, 275 };
                }
            }
            else if (isRc2Hit) // 3번숙제 player 사각형이 rc2 사각형과 충돌하면 rc2 사각형 밀고다니기
            {
                if (player.right == rc2.left + 5)
                {
                    rc2.right += 5;
                    rc2.left += 5;
                }
            }
            InvalidateRect(hWnd, NULL, true);
        }
        break;
        case VK_LEFT:
        {
            player.left -= 5;
            player.right -= 5;

            isPlayerHit = false;
            isRc1Hit = false;
            isRc2Hit = false;

            isPlayerHit = Collision::RectInRect(player, rc1);
            isRc1Hit = Collision::RectInRect(rc1, rc2);
            isRc2Hit = Collision::RectInRect(player, rc2);

            if (isPlayerHit)
            {
                if (player.left == rc1.left - 5)
                {
                    rc1.right -= 5;
                    rc1.left -= 5;
                }

                if (isRc1Hit)
                {
                    player = { 1025, 225, 1075, 275 };
                }
            }
            else if (isRc2Hit) // 3번숙제 player 사각형이 rc2 사각형과 충돌하면 rc2 사각형 밀고다니기
            {
                if (player.left == rc2.right - 5)
                {
                    rc2.right -= 5;
                    rc2.left -= 5;
                }
            }
            InvalidateRect(hWnd, NULL, true);
        }
        break;
        case VK_DOWN:
        {
            player.top += 5;
            player.bottom += 5;

            isPlayerHit = false;
            isRc1Hit = false;
            isRc2Hit = false;
            isPlayerHit = Collision::RectInRect(player, rc1);
            isRc1Hit = Collision::RectInRect(rc1, rc2);
            isRc2Hit = Collision::RectInRect(player, rc2);

            if (isPlayerHit)
            {
                if (player.bottom == rc1.bottom + 5)
                {
                    rc1.top += 5;
                    rc1.bottom += 5;
                }

                if (isRc1Hit)
                {
                    player = { 1025, 225, 1075, 275 };
                }
            }
            else if (isRc2Hit) // 3번숙제 player 사각형이 rc2 사각형과 충돌하면 rc2 사각형 밀고다니기
            {
                if (player.bottom == rc2.top + 5)
                {
                    rc2.top += 5;
                    rc2.bottom += 5;
                }
            }
            InvalidateRect(hWnd, NULL, true);
        }
        break;
        default:
            break;
        }

        break;

        // 마우스 움직임 감지 case
    case WM_MOUSEMOVE:
    {
        mousePos.x = GET_X_LPARAM(lParam);
        mousePos.y = GET_Y_LPARAM(lParam);
    }
    break;

    // 타이머 로직 적는 case
    case WM_TIMER:
        switch (wParam)
        {
        case 1:
            InvalidateRect(hWnd, NULL, true);
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