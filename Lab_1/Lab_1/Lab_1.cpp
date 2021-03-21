#pragma comment(linker,"\"/manifestdependency:type='win32' \
name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#include <Windows.h>
#include <tchar.h>
#include <chrono>
#include <thread>


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


RECT clientRect;
int x1 = 200, x2 = 600, cl = 0, n = 0, l = 4, com = 0;

TCHAR WinName[] = _T("MainFrame");

// точка входа
int WINAPI _tWinMain(HINSTANCE This,		 // Дескриптор текущего приложения 
	HINSTANCE Prev, 	// В современных системах всегда 0 
	LPTSTR cmd, 		// Командная строка 
	int mode) 		// Режим отображения окна
{
	HWND hWnd;		// Дескриптор главного окна программы 
	MSG msg; 		// Структура для хранения сообщения 
	WNDCLASS wc; 	// Класс окна
	// Определение класса окна 
	wc.hInstance = This;
	wc.lpszClassName = WinName; 				// Имя класса окна 
	wc.lpfnWndProc = WndProc; 					// Функция окна 
	wc.style = CS_HREDRAW | CS_VREDRAW; 			// Стиль окна 
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); 		// Стандартная иконка 
	wc.hCursor = LoadCursor(NULL, IDC_ARROW); 		// Стандартный курсор 
	wc.lpszMenuName = NULL; 					// Нет меню 
	wc.cbClsExtra = 0; 						// Нет дополнительных данных класса 
	wc.cbWndExtra = 0; 						// Нет дополнительных данных окна 
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); 	// Заполнение окна белым цветом 


	// Регистрация класса окна
	if (!RegisterClass(&wc)) return 0;

	// Создание окна 
	hWnd = CreateWindow(WinName,			// Имя класса окна 
		_T("Лабараторные работы Алиев Тимур РТ5-41Б"), 		// Заголовок окна 
		WS_OVERLAPPEDWINDOW, 		// Стиль окна 
		CW_USEDEFAULT,				// x 
		CW_USEDEFAULT, 				// y	 Размеры окна 
		800, 				// width 
		500, 				// Height 
		HWND_DESKTOP, 				// Дескриптор родительского окна 
		NULL, 						// Нет меню 
		This, 						// Дескриптор приложения 
		NULL); 					// Дополнительной информации нет 

	ShowWindow(hWnd, mode); 				// Показать окно
	UpdateWindow(hWnd);

	// Цикл обработки сообщений 
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg); 		// Функция трансляции кодов нажатой клавиши 
		DispatchMessage(&msg); 		// Посылает сообщение функции WndProc() 
	}
	return 0;
}

// Оконная функция вызывается операционной системой
// и получает сообщения из очереди для данного приложения

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HBRUSH brush;
	HPEN pen;
	switch (message)		 // Обработчик сообщений
	{
	case WM_CREATE:
	{
		brush = CreateSolidBrush(RGB(0, 0, 20));
		SetClassLong(hWnd, GCL_HBRBACKGROUND, (LONG)brush);
		/*
		HWND ButtonLab1 = CreateWindow(
			L"BUTTON",
			L"Лабораторная работа № 1",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			50, 30, 300, 30, hWnd, reinterpret_cast<HMENU>(1), nullptr, nullptr
			);
		HWND ButtonLab2 = CreateWindow(
			L"BUTTON",
			L"Лабораторная работа № 2",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			50, 65, 300, 30, hWnd, reinterpret_cast<HMENU>(2), nullptr, nullptr
		);
		HWND ButtonLab3 = CreateWindow(
			L"BUTTON",
			L"Лабораторная работа № 3",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			50, 100, 300, 30, hWnd, reinterpret_cast<HMENU>(3), nullptr, nullptr
		);
		HWND ButtonLab4 = CreateWindow(
			L"BUTTON",
			L"Лабораторная работа № 4",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			50, 135, 300, 30, hWnd, reinterpret_cast<HMENU>(4), nullptr, nullptr
		);
		*/
	}
	break;

	case WM_PAINT:
	{
		GetClientRect(hWnd, &clientRect);
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		// цвет контура
		pen = CreatePen(PS_NULL, 0, RGB(0, 0, 0));
		SelectObject(hdc, pen);

		// задний фон
		brush = CreateSolidBrush(RGB(0, 0, cl));
		FillRect(hdc, &clientRect, brush);

		// светлый круг
		brush = CreateSolidBrush(RGB(255, 200, 0));
		SelectObject(hdc, brush);
		RoundRect(hdc, 200, 10, 600, 410, 400, 400);

		// темный круг
		brush = CreateSolidBrush(RGB(0, 0, cl));
		SelectObject(hdc, brush);
		RoundRect(hdc, x1, 10, x2, 410, 400, 400);

		if (n == 0){
			brush = CreateSolidBrush(RGB(0, 0, 0));
			FillRect(hdc, &clientRect, brush);
		}

		if (com >= 1) {
			brush = CreateSolidBrush(RGB(0, 0, cl));
			SelectObject(hdc, brush);
			pen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
			SelectObject(hdc, pen);
			Rectangle(hdc, 310, 420, 535, 455);
			SetTextColor(hdc, RGB(255, 0, 0));
			TextOut(hdc, 320, 430, L"Алиев Тимур РТ5-41Б Лаб. №1", lstrlen(L"Алиев Тимур РТ5-41Б Лаб. №1"));

			InvalidateRect(hWnd, NULL, true);

			SetTimer(hWnd, 1, 3000, NULL);
		}

		DeleteObject(brush);

		EndPaint(hWnd, &ps);
	}
	break;

	case WM_TIMER:
		PostQuitMessage(0);
		return true;

	case WM_LBUTTONDOWN:
	{
		x1 += 20;
		x2 += 20;
		cl += l;
		n += 1;
		if (n == 21) {
			x1 = -200; x2 = 200; l = -4;
		}
		if (n == 42) {
			x1 = 200; x2 = 600; l = 4; n = 0;
		}
		InvalidateRect(hWnd, NULL, true);
		//MessageBox(hWnd, L"lab", L"Имя окна", MB_ICONINFORMATION);
	}
	break;

	case WM_RBUTTONDOWN:
	{
		com += 1;
		InvalidateRect(hWnd, NULL, true);

		//MessageBox(hWnd, L"lab", L"Имя окна", MB_ICONINFORMATION);
	}
	break;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		/*
		case 1: 
		{
			MessageBox(hWnd, L"lab1", L"lab_1_1", MB_ICONINFORMATION);
		}
		break;
		case 2:
		{
			MessageBox(hWnd, L"lab2", L"lab_2_2", MB_ICONINFORMATION);
		}
		break;
		case 3:
		{
			MessageBox(hWnd, L"lab3", L"lab_3_3", MB_ICONINFORMATION);
		}
		break;
		case 4:
		{
			MessageBox(hWnd, L"lab4", L"lab_4_4", MB_ICONINFORMATION);
		}
		break;

		*/

		default:
			break;
		}
	}
	break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break; 			// Завершение программы 

	default: 			// Обработка сообщения по умолчанию 
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
