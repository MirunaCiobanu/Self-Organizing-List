// Win32Project4.cpp : Defines the entry point for the application.
//

//#include "stdio.h"
#include "stdafx.h"
#include "Win32Project4.h"
#include "SelfOrganizedList.h"

#define MAX_LOADSTRING 100
#define PROCESS_CASE 0x12f3

HWND zonaCuIntrebari;
HWND Abutton;
HWND Bbutton;
HWND Cbutton;
HWND Dbutton;
HWND Ebutton;
HWND Fbutton;
HWND butonDeOprire;


// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

FILE *file;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	Raspuns(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// initializam lista cu cele 6 raspunsuri:
	InsertFirst(A_INDEX);
	InsertLast(B_INDEX);
	InsertLast(C_INDEX);
	InsertLast(D_INDEX);
	InsertLast(E_INDEX);
	InsertLast(F_INDEX);

	fopen_s(&file, "intrebari.txt", "r");

 	// TODO: Place code here.
	

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_WIN32PROJECT4, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}
MSG msg;
	HACCEL hAccelTable;
	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT4));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
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
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT4));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_WIN32PROJECT4);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   CW_USEDEFAULT, 0, 510, 500, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
	{
	  butonDeOprire = CreateWindowEx(0, L"BUTTON", L"M-am plictisit. Vreau sa aflu rezultatul!",
		  WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
		  10, 180, 470, 30, hWnd, NULL, NULL, NULL);
	zonaCuIntrebari = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_VISIBLE | WS_CHILD | ES_CENTER | ES_MULTILINE,
	    10, 10, 470, 80, hWnd, NULL, NULL, NULL);
	Abutton = CreateWindowEx(0, L"BUTTON", L"100%", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		10, 100, 70, 70, hWnd, NULL, NULL, NULL);
	Bbutton = CreateWindowEx(0, L"BUTTON", L"80%", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		90, 100, 70, 70, hWnd, NULL, NULL, NULL);
	Cbutton = CreateWindowEx(0, L"BUTTON", L"60%", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		170, 100, 70, 70, hWnd, NULL, NULL, NULL);
	Dbutton = CreateWindowEx(0, L"BUTTON", L"40%", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		250, 100, 70, 70, hWnd, NULL, NULL, NULL);
	Ebutton = CreateWindowEx(0, L"BUTTON", L"20%", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		330, 100, 70, 70, hWnd, NULL, NULL, NULL);
	Fbutton = CreateWindowEx(0, L"BUTTON", L"0%", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
		410, 100, 70, 70, hWnd, NULL, NULL, NULL);
	
	SendMessage(hWnd, PROCESS_CASE, wParam, lParam);
	}
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case BN_CLICKED:
			// cazul apasarii pe butoane:
			if (butonDeOprire == (HWND)lParam) {
				DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Raspuns);
				break;
			}
			if (Abutton == (HWND)lParam) {
				UseNode(A_INDEX);
				SendMessage(hWnd, PROCESS_CASE, wParam, lParam);
				break;
			}
			if (Bbutton == (HWND)lParam) {
				UseNode(B_INDEX);
				SendMessage(hWnd, PROCESS_CASE, wParam, lParam);
				break;
			}
			if (Cbutton == (HWND)lParam) {
				UseNode(C_INDEX);
				SendMessage(hWnd, PROCESS_CASE, wParam, lParam);
				break;
			}
			if (Dbutton == (HWND)lParam) {
				UseNode(D_INDEX);
				SendMessage(hWnd, PROCESS_CASE, wParam, lParam);
				break;
			}
			if (Ebutton == (HWND)lParam) {
				UseNode(E_INDEX);
				SendMessage(hWnd, PROCESS_CASE, wParam, lParam);
				break;
			}
			if (Fbutton == (HWND)lParam) {
				UseNode(F_INDEX);
				SendMessage(hWnd, PROCESS_CASE, wParam, lParam);
				break;
			}
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case PROCESS_CASE:
	{
						 LPWSTR buffer = (LPWSTR)malloc(sizeof(WCHAR)* MAX_PATH);
						 fgetws(buffer, MAX_PATH, file);
						 if (feof(file)) {
							 DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, Raspuns);
						 }
						 else {
							 SetWindowText(zonaCuIntrebari, buffer);
						 }
						 free(buffer);
	}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
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

INT_PTR CALLBACK Raspuns(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
	{	 // am adaugat aici la initializare:
		 int raspuns;
		 // am calculat raspunsul : media aritmetica ponderata
		 raspuns = (0.2 * first->index) + (0.3 * first->next->index) + (0.2 * first->next->next->index) + (0.1 * first->next->next->next->index) + (0.1 * first->next->next->next->next->index);
		fclose(file);
		fopen_s(&file, "raspunsuri.txt", "r");
		LPWSTR buffer = (LPWSTR)malloc(sizeof(WCHAR)* MAX_PATH * 10);
		while (raspuns--)
		{
			fgetws(buffer, MAX_PATH * 10, file);
			
		}
		HWND zonaCuRaspuns = GetDlgItem(hDlg, IDC_EDIT1);
		SetWindowText(zonaCuRaspuns, buffer);
		fclose(file);
		Initialize();
		SetWindowText(zonaCuIntrebari, L"");
		fopen_s(&file, "intrebari.txt", "r");
		return (INT_PTR)TRUE;
	}
	
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
