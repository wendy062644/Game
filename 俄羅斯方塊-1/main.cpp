#include <windows.h>
#include<time.h>

int g_arrBackground[20][10] = {0}; //遊戲格子 

int g_tetris[2][4] = {0}; //方塊格子 

LRESULT CALLBACK WindowProc(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
);

void OnPaint(HDC hDC); //顯示畫面 

void DrawBlock(HDC hDC); //顯示方塊 

void OnCreate(); //生成方塊

void CreateBlock(); //隨機產生方塊

void Copy();

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	
	
	TCHAR szAPPClassName[] = TEXT("123");
	
	WNDCLASS wc = {0};
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = szAPPClassName;
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	
	RegisterClass(&wc);
	
	HWND hWnd = CreateWindow(
		szAPPClassName,
		TEXT("俄羅斯方塊"),
		WS_BORDER|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,
		300, 200,
		490, 640,
		NULL,
		NULL,
		hInstance,
		NULL
	);
	
	ShowWindow(hWnd, SW_SHOW);
	
	UpdateWindow(hWnd);
	
	MSG msg;
	while(GetMessage(&msg, NULL, 0, 0) )
	{
		TranslateMessage(&msg);
		
		DispatchMessage(&msg);
	}
	
	return 0;
}

LRESULT CALLBACK WindowProc(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	PAINTSTRUCT ps;
	HDC hDC;
	
	switch(uMsg)
	{
		case WM_CREATE:
			OnCreate();
			break;
		
		case WM_KEYDOWN:
			switch(wParam)
			{
				case VK_RETURN:
					break;
			}
		
		case WM_PAINT:
			hDC = BeginPaint(hWnd, &ps); //顯示圖案 
			
			OnPaint(hDC);
				
			EndPaint(hWnd, &ps); //結束圖案 
			break;
			
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;
		
		case WM_DESTROY: //關掉整個exe檔 
			PostQuitMessage(0);
			break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void OnPaint(HDC hDC) //顯示圖案 
{
	HDC hMemDC = CreateCompatibleDC(hDC);
	
	HBITMAP hBackBmp = CreateCompatibleBitmap(hDC, 300, 600);
	SelectObject(hMemDC, hBackBmp);
	
	DrawBlock(hMemDC);
	
	BitBlt(hDC, 0, 0, 300, 600, hMemDC, 0, 0, SRCCOPY);
	
	DeleteDC(hMemDC); 
}

void DrawBlock(HDC hDC)
{
	Rectangle(hDC, 0, 0, 300, 600);
	
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 10; j++)
		{
			if(g_arrBackground[i][j] == 1)
			{
				HPEN hPen = CreatePen(PS_SOLID, 1, RGB(51, 201, 255));
				HPEN oldPen = (HPEN)SelectObject(hDC, hPen);
				
				HBRUSH hBrush = CreateSolidBrush(RGB(51, 201, 255));
				HBRUSH oldBrush = (HBRUSH)SelectObject(hDC, hBrush); 
				
				Rectangle(hDC, 	j*30+1, i*30+1, j*30+29, i*30+29);
				SelectObject(hDC, oldBrush);
			}
			if(g_arrBackground[i][j] == 2)
			{
				HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 201, 255));
				HPEN oldPen = (HPEN)SelectObject(hDC, hPen);
				
				HBRUSH hBrush = CreateSolidBrush(RGB(100, 0, 255));
				HBRUSH oldBrush = (HBRUSH)SelectObject(hDC, hBrush); 
				
				Rectangle(hDC, 	j*30+1, i*30+1, j*30+29, i*30+29);
				SelectObject(hDC, oldBrush);
			}
		}
	}
}

void OnCreate()
{
	CreateBlock();
	Copy();
}

void CreateBlock()
{
	srand((UINT)time(NULL));
	int index = rand() % 7;
	
	switch(index)
	{
		case 0:
			g_tetris[0][0] = 0, g_tetris[0][1] = 1, g_tetris[0][2] = 0, g_tetris[0][3] = 0;
			g_tetris[1][0] = 1, g_tetris[1][1] = 1, g_tetris[1][2] = 1, g_tetris[1][3] = 0;
			break;
		case 1:
			g_tetris[0][0] = 0, g_tetris[0][1] = 1, g_tetris[0][2] = 1, g_tetris[0][3] = 0;
			g_tetris[1][0] = 0, g_tetris[1][1] = 1, g_tetris[1][2] = 1, g_tetris[1][3] = 0;
			break;
		case 2:
			g_tetris[0][0] = 0, g_tetris[0][1] = 0, g_tetris[0][2] = 0, g_tetris[0][3] = 1;
			g_tetris[1][0] = 0, g_tetris[1][1] = 1, g_tetris[1][2] = 1, g_tetris[1][3] = 1;
			break;
		case 3:
			g_tetris[0][0] = 1, g_tetris[0][1] = 0, g_tetris[0][2] = 0, g_tetris[0][3] = 0;
			g_tetris[1][0] = 1, g_tetris[1][1] = 1, g_tetris[1][2] = 1, g_tetris[1][3] = 0;
			break;
		case 4:
			g_tetris[0][0] = 0, g_tetris[0][1] = 1, g_tetris[0][2] = 1, g_tetris[0][3] = 0;
			g_tetris[1][0] = 0, g_tetris[1][1] = 0, g_tetris[1][2] = 1, g_tetris[1][3] = 1;
			break;
		case 5:
			g_tetris[0][0] = 0, g_tetris[0][1] = 1, g_tetris[0][2] = 1, g_tetris[0][3] = 0;
			g_tetris[1][0] = 1, g_tetris[1][1] = 1, g_tetris[1][2] = 0, g_tetris[1][3] = 0;
			break;
		case 6:
			g_tetris[0][0] = 0, g_tetris[0][1] = 0, g_tetris[0][2] = 0, g_tetris[0][3] = 0;
			g_tetris[1][0] = 1, g_tetris[1][1] = 1, g_tetris[1][2] = 1, g_tetris[1][3] = 1;
			break;
	}
} 

void Copy()
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			g_arrBackground[i][j+3] = g_tetris[i][j];
		}
	}
}
