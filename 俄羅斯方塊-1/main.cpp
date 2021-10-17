#include <windows.h>
#include<time.h>

#define DEF_TIMER1 1234

int Background[20][10] = {0}; //遊戲格子 

int g_tetris[2][4] = {0}; //方塊格子 

int g_nLine = -1;
int g_nList = -1;

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

void Return(HWND hWnd);

void Left(HWND hWnd);

void Right(HWND hWnd);

void Up(HWND hWnd);

void Down(HWND hWnd);

void Timer(HWND hWnd);

void SqareDown()
{
	int i = 0;
	int j = 0;
	for (i = 19; i >= 0; i--)
	{
		for (j = 0; j < 10; j++)
		{
			if (1 == Background[i][j])
			{
				Background[i + 1][j] = Background[i][j];
				Background[i][j] = 0;
			}
		}
	}
}

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
	while(GetMessage(&msg, NULL, 0, 0))
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
		
		case WM_KEYDOWN: //按鍵 
			switch(wParam)
			{
				case VK_RETURN:
					Return(hWnd); 
					break;
				case VK_LEFT:
					Left(hWnd);
					break;
				case VK_RIGHT:
					Right(hWnd);
					break;
				case VK_UP:
					Up(hWnd);
					break;
				case VK_DOWN:
					Down(hWnd);
					break;
			}
			break;
		
		case WM_TIMER: //計時 
			Timer(hWnd);
			break;
		
		case WM_PAINT:
			hDC = BeginPaint(hWnd, &ps); //顯示圖案 
			
			OnPaint(hDC);
				
			EndPaint(hWnd, &ps); //結束圖案 
			break;
			
		case WM_CLOSE:
			DestroyWindow(hWnd);
			break;
		
		case WM_DESTROY: //關掉整個exe檔
			KillTimer(hWnd, DEF_TIMER1);
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
			if(Background[i][j] == 1)
			{
				HPEN hPen = CreatePen(PS_SOLID, 1, RGB(51, 201, 255));
				HPEN oldPen = (HPEN)SelectObject(hDC, hPen);
				
				HBRUSH hBrush = CreateSolidBrush(RGB(51, 201, 255));
				HBRUSH oldBrush = (HBRUSH)SelectObject(hDC, hBrush); 
				
				Rectangle(hDC, 	j*30+1, i*30+1, j*30+29, i*30+29);
				SelectObject(hDC, oldBrush);
			}
			if(Background[i][j] == 2)
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
			g_nLine = 0;
			g_nList = 3;
			break;
		case 1:
			g_tetris[0][0] = 0, g_tetris[0][1] = 1, g_tetris[0][2] = 1, g_tetris[0][3] = 0;
			g_tetris[1][0] = 0, g_tetris[1][1] = 1, g_tetris[1][2] = 1, g_tetris[1][3] = 0;
			g_nLine = 0;
			g_nList = 3;
			break;
		case 2:
			g_tetris[0][0] = 0, g_tetris[0][1] = 0, g_tetris[0][2] = 0, g_tetris[0][3] = 1;
			g_tetris[1][0] = 0, g_tetris[1][1] = 1, g_tetris[1][2] = 1, g_tetris[1][3] = 1;
			g_nLine = 0;
			g_nList = 3;
			break;
		case 3:
			g_tetris[0][0] = 1, g_tetris[0][1] = 0, g_tetris[0][2] = 0, g_tetris[0][3] = 0;
			g_tetris[1][0] = 1, g_tetris[1][1] = 1, g_tetris[1][2] = 1, g_tetris[1][3] = 0;
			g_nLine = 0;
			g_nList = 3;
			break;
		case 4:
			g_tetris[0][0] = 0, g_tetris[0][1] = 1, g_tetris[0][2] = 1, g_tetris[0][3] = 0;
			g_tetris[1][0] = 0, g_tetris[1][1] = 0, g_tetris[1][2] = 1, g_tetris[1][3] = 1;
			g_nLine = 0;
			g_nList = 3;
			break;
		case 5:
			g_tetris[0][0] = 0, g_tetris[0][1] = 1, g_tetris[0][2] = 1, g_tetris[0][3] = 0;
			g_tetris[1][0] = 1, g_tetris[1][1] = 1, g_tetris[1][2] = 0, g_tetris[1][3] = 0;
			g_nLine = 0;
			g_nList = 3;
			break;
		case 6:
			g_tetris[0][0] = 1, g_tetris[0][1] = 1, g_tetris[0][2] = 1, g_tetris[0][3] = 1;
			g_tetris[1][0] = 0, g_tetris[1][1] = 0, g_tetris[1][2] = 0, g_tetris[1][3] = 0;
			g_nLine = 0;
			g_nList = 4;
			break;
	}
} 

void Copy()
{
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			Background[i][j+3] = g_tetris[i][j];
		}
	}
}

int Down1()
{
	for (int i = 0; i < 10; i++)
	{
		if (1 == Background[19][i])
		{
			return 0;
		}
	}
	return 1;
}

int Down2()
{
	for (int i = 19; i >= 0; i--)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == Background[i][j] && 2 == Background[i + 1][j])
			{
				return 0;
			}
		}
	}
	return 1;
}

void Timer(HWND hWnd)
{
	HDC hDc = GetDC(hWnd);
	
	if(Down1() == 1&&Down2() == 1)
	{
		SqareDown();
		g_nLine++;
	}
	else{
		
	}
}

void Return(HWND hWnd)
{
	SetTimer(hWnd, DEF_TIMER1, 600, NULL);
}

int Left1()
{
	for (int i = 0; i < 20; i++)
	{
		if (Background[i][0] == 1)
		{
			return 0;
		}
	}
	return 1;
}

int Left2()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Background[i][j] == 1&& Background[i][j - 1] == 2)
			{
				return 0;
			}
		}
	}
	return 1;
}

void SqareLeft()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (1 == Background[i][j])
			{
				Background[i][j - 1] = Background[i][j];
				Background[i][j] = 0;
			}
		}
	}
}

void Left(HWND hWnd)
{
	if (1 == Left1() && 1 == Left2())
	{
		HDC hDc = GetDC(hWnd);
		g_nList--;
		SqareLeft();
		OnPaint(hDc);
		ReleaseDC(hWnd, hDc);
	}
}

int Right1()
{
	for (int i = 0; i < 20; i++)
	{
		if (Background[i][19] == 1)
		{
			return 0;
		}
	}
	return 1;
}

int Right2()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Background[i][j] == 1 && Background[i][j + 1] == 2)
			{
				return 0;
			}
		}
	}
	return 1;
}

void SqareRight()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 9; j >= 0; j--)
		{
			if (1 == Background[i][j])
			{
				Background[i][j + 1] = Background[i][j];
				Background[i][j] = 0;
			}
		}
	}
}

void Right(HWND hWnd)
{
	if (1 == Right1() && 1 == Right2())
	{
		HDC hDc = GetDC(hWnd);
		g_nList++;
		SqareRight();
		OnPaint(hDc);
		ReleaseDC(hWnd, hDc);
	}
}

void Down(HWND hWnd)
{
	Timer(hWnd);
}
