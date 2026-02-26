// WinProject1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "WinProject1.h"

#define MAX_LOADSTRING 100

// char : 1바이트 정수형
// wchar_t : 각국의 문자를 표현하기 위해 2byte로 확장한 정수형(문자형) 타입



// 전역 변수: 
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.
BOOL bShowText = FALSE;
BOOL bShowRect = FALSE;
BOOL bDrag = FALSE;
int xStartPos, yStartPos;
int xPos, yPos, xPrevPos, yPrevPos;
int cx, cy; // window의 넓이와 높이

// 깜박임 현상을 방지하기 위해 전역변수로 처리함
HDC g_hMemDC = NULL;
HBITMAP g_hBmp = NULL;
HBITMAP g_hOldBmp = NULL;

DRAW_MODE dm = FREE;



// 이 코드 모듈에 포함된 함수의 선언을 전달합니다
// 함수들의 원형 선언으로써 뒤에 이 함수들이 나옴
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    // 윈도우 타이틀을 스트링 리소스 테이블로부터 가져온다
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    // 윈도우 클래스 이름을 스트링 리소스 테이블로부터 가져온다
    LoadStringW(hInstance, IDC_WINPROJECT1, szWindowClass, MAX_LOADSTRING);

    // 윈도우 클래스 등록
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

        

    // 단축키 설정을 로딩해둔다.
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINPROJECT1));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 윈도우 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;  // 윈도우 메시지 처리하는 콜백 함수의 포인터
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINPROJECT1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINPROJECT1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    // 위에 구조체를 채우고 RegisterClassExW()함수를 호출하면 윈도우 클래스 등록완료!
    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}


void UpdateCheckMenu(HWND hWnd, UINT id)
{
    HMENU hSubMenu = ::GetMenu(hWnd);

    // 기본적으로 모두 언체크
    ::CheckMenuItem(hSubMenu, IDM_DRAW_CIRCLE, MF_UNCHECKED);
    ::CheckMenuItem(hSubMenu, IDM_DRAW_RECT, MF_UNCHECKED);
    ::CheckMenuItem(hSubMenu, IDM_DRAW_LINE, MF_UNCHECKED);
    ::CheckMenuItem(hSubMenu, IDM_DRAW_FREE, MF_UNCHECKED);

    // 선택된 메뉴만 체크
    ::CheckMenuItem(hSubMenu, id, MF_CHECKED);
}



//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        UpdateCheckMenu(hWnd, IDM_DRAW_FREE);
        break;

    case WM_COMMAND:    // 메뉴가 클릭되었을때 발생되는 메시지
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;

            case IDM_TEXT_SAY1:
                bShowText = TRUE;                
                ::InvalidateRect(hWnd, NULL, TRUE); // 클라이언트 영역을 강제로 다시 그리게한다.
                break;

            case IDM_DRAW_RECT:        
                UpdateCheckMenu(hWnd, IDM_DRAW_RECT);
                dm = RECTANGLE;
                break;

            case IDM_DRAW_CIRCLE:
                UpdateCheckMenu(hWnd, IDM_DRAW_CIRCLE);
                dm = CIRCLE;
                break;

            case IDM_DRAW_LINE:
                UpdateCheckMenu(hWnd, IDM_DRAW_LINE);
                dm = LINE;
                break;

            case IDM_DRAW_FREE:
                UpdateCheckMenu(hWnd, IDM_DRAW_FREE);
                dm = FREE;
                break;

            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_SIZE:   // 윈도우의 크기가 변결될때마다 메시지가 전달됨
        DestroyGlobalMemDC();
        CreateGlobalMemDC(hWnd);
        break;

    case WM_PAINT:  // 윈도우 내부가 다시 그려져야 할 필요가 있을때 OS에의해 전달됨
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            
            /*if (bShowText) ShowHello(hWnd, hdc);
            if (bShowRect) ShowRectangle(hWnd, hdc);*/
            // ShowMouseLocation(hWnd, hdc, xPos, yPos);
            if (g_hMemDC)
                ::BitBlt(hdc, 0, 0, cx, cy, g_hMemDC, 0, 0, SRCCOPY);

            EndPaint(hWnd, &ps);
        }
        break;

    case WM_LBUTTONDOWN:    // 클라이언트 영역안에서 마우스 왼쪽버튼을 누르면 발생되는 메시지
        xStartPos = GET_X_LPARAM(lParam);
        yStartPos = GET_Y_LPARAM(lParam);
        xPrevPos = xStartPos;
        yPrevPos = yStartPos;
        bDrag = TRUE;   // 드래그 중임을 알리는 전역변수
        break;


    case WM_MOUSEMOVE:  // 클라이언트 영역안에서 마우스를 움직이면 발생되는 메시지
    {
        xPos = GET_X_LPARAM(lParam);
        yPos = GET_Y_LPARAM(lParam);
        ShowMouseLocation(hWnd, xPos, yPos);
        ::InvalidateRect(hWnd, NULL, FALSE);
    }        
    break;

    case WM_LBUTTONUP:
        bDrag = FALSE;
        break;

    case WM_DESTROY:
        DestroyGlobalMemDC();
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
