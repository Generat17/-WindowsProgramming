// lab3.cpp : Определяет точку входа для приложения.
//

#include "framework.h"
#include "lab3.h"


#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
double resDouble;
char mathStr[100];
std::string resStr, str = "";
int n, count = 0;
char char_resStr[50];
wchar_t wcstring[50];
wchar_t wcstring1[100];
HBRUSH brush;
HPEN pen;


// Отправить объявления функций, включенных в этот модуль кода:
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

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB3));

    MSG msg;

    // Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB3);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

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

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
HWND hStatusWindow;
TCHAR czClassName[] = L"StatusBar";

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE: {
        hStatusWindow = CreateStatusWindow(
            WS_CHILD | WS_VISIBLE, // style
            czClassName, // name 
            hWnd,
            777); // id
        for (int j = 0; j < 100; j++)
            mathStr[j] = NULL;
        HWND hwndButton_1 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"1",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            20,         // x position 
            60,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(1),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_2 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"2",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            80,         // x position 
            60,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(2),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_3 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"3",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            140,         // x position 
            60,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(3),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_4 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"4",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            20,         // x position 
            120,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(4),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_5 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"5",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            80,         // x position 
            120,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(5),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_6 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"6",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            140,         // x position 
            120,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(6),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_7 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"7",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            20,         // x position 
            180,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(7),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_8 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"8",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            80,         // x position 
            180,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(8),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_9 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"9",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            140,         // x position 
            180,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(9),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_0 = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"0",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            20,         // x position 
            240,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(0),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_minus = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"-",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            200,         // x position 
            60,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(10),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_plus = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"+",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            200,         // x position 
            120,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(11),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_del = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"/",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            200,         // x position 
            180,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(12),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_umn = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"*",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            200,         // x position 
            240,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(13),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_lskob = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"(",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            80,         // x position 
            240,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(14),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_rskob = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L")",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            140,         // x position 
            240,         // y position 
            50,        // Button width
            50,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(15),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_ce = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"AC",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            260,         // x position 
            180,         // y position 
            50,        // Button width
            110,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(16),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.

        HWND hwndButton_ac = CreateWindow(
            L"BUTTON",  // Predefined class; Unicode assumed 
            L"CE",      // Button text 
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
            260,         // x position 
            60,         // y position 
            50,        // Button width
            110,        // Button height
            hWnd,     // Parent window
            reinterpret_cast<HMENU>(17),       // No menu.
            nullptr,
            nullptr);      // Pointer not needed.
    }break;
    case WM_SIZE:
        SendMessage(hStatusWindow, WM_SIZE, 0, 0);
        break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Разобрать выбор в меню:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case ID_32783:
            MoveWindow(hWnd, 0, 0, 370, 420, TRUE);
            break;
        case ID_32784:
            MoveWindow(hWnd, 0, 0, 600, 600, TRUE);
            break;
        case ID_32785:
            MoveWindow(hWnd, 0, 0, 800, 800, TRUE);
            break;
        case ID_32786:
            MoveWindow(hWnd, 0, 0, 1000, 1000, TRUE);
            break;
        case ID_32782:
            DestroyWindow(hWnd);
            break;

        case 1: {
            str += "1";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 2: {
            str += "2";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 3: {
            str += "3";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 4: {
            str += "4";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 5: {
            str += "5";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 6: {
            str += "6";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 7: {
            str += "7";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 8: {
            str += "8";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 9: {
            str += "9";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 10: {
            str += "-";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 11: {
            str += "+";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 12: {
            str += "/";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 13: {
            str += "*";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 14: {
            str += "(";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 15: {
            str += ")";
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 16: {
            str = "";
            resStr = "";
            for (int i = 0; i < 50; i++)
                char_resStr[i] = NULL;
            for (int i = 0; i < 100; i++)
                mathStr[i] = NULL;
            n = 0;
            count = 0;
            count++;
            InvalidateRect(hWnd, NULL, true);
        } break;

        case 17: {
            if (!str.empty())
                str.resize(str.size() - 1);
            mathStr[str.size() + 1] = NULL;

            count--;
            InvalidateRect(hWnd, NULL, true);

        } break;

        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        int pParts[2];
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);

        brush = CreateSolidBrush(RGB(255, 255, 255));
        SelectObject(hdc, brush);
        pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
        SelectObject(hdc, pen);
        Rectangle(hdc, 20, 20, 310, 45);
        Rectangle(hdc, 20, 300, 310, 325);

        // string::str - строка с выражением надо загнать в char_array mathStr

        for (int i = 0; i < str.length(); i++)
            mathStr[i] = str[i];

        str;

        resDouble = te_interp(mathStr, 0);
        resStr = std::to_string(resDouble);

        for (int i = 0; i < resStr.length(); i++)
            char_resStr[i] = resStr[i];

        size_t convertedChars = 0;
        mbstowcs_s(&convertedChars, wcstring, 50, char_resStr, _TRUNCATE);

        size_t convertedChars1 = 0;
        mbstowcs_s(&convertedChars1, wcstring1, 100, mathStr, _TRUNCATE);

        n = resStr.length();

        SetTextColor(hdc, RGB(0, 0, 0));
        TextOut(hdc, 25, 24, wcstring1, count);
        TextOut(hdc, 25, 305, wcstring, n);

        pParts[0] = 200;
        pParts[1] = 200 + 200;

        SendMessage(hStatusWindow, SB_SETPARTS, 2, (LPARAM)&pParts);
        TCHAR B1[] = L"Алиев Тимур РТ5-41Б";
        SendMessage(hStatusWindow, SB_SETTEXT, 0, (LPARAM)&B1);
        SendMessage(hStatusWindow, SB_SETTEXT, 1 | SBT_NOBORDERS, (LPARAM)wcstring);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
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
