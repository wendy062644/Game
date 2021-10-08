#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<iomanip>

using namespace std;
int map[22][12] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int score = 0; //總分 
int tt = 0; //消除數 
int last = 0; //最後得分 
int block[2][4] = {0}; //方塊圖案 
int check = 1; //確認是否結束一個方塊
int r, l; //判斷是否最左或最右 
int BlockNum = 0;
int High = 0; //紀錄高度，減少計算 
float Time = 0; //計算時間 
void Print();
void Set(int x, int y);

void GameOver(){
	system("cls");
	cout << endl << "     | Game Over |" << endl << "     |獲得分數: " << score << "|" << endl << "     |消除總數: " << tt << "|" <<  endl;
}

int Change()
{
	
}

int Right()
{
	if(r == 0){return 0;}
	for(int a = 1; 21 > a; a++)
	{
		for(int b = 11; b > 1; b--)
		{
			if(map[a][b] == 2){if(map[a][b+1] != 0){return 0;}break;}
		}
	}
	for(int a = 1; 21 > a; a++)
	{
		for(int b = 11; b >= 1; b--)
		{
			if(map[a][b] == 2){
				map[a][b+1] = 2;
				map[a][b] = 0;
				Set(b*2, a);
				cout << "  ";
				Set((b+1)*2, a);
				cout << "□";
			}
		}
	}
	r--; l++;
}

int Left(){
	if(l == 0){return 0;}
	for(int a = 1; 20 > a; a++)
	{
		for(int b = 1; 11 >= b; b++)
		{
			if(map[a][b] == 2){if(map[a][b-1] != 0){return 0;}break;}
		}
	}
	for(int a = 1; 20 > a; a++)
	{
		for(int b = 1; 11 > b; b++)
		{
			if(map[a][b] == 2){
				map[a][b-1] = 2;
				map[a][b] = 0;
				Set(b*2, a);
				cout << "  ";
				Set((b-1)*2, a);
				cout << "□";
			}
		}
	}
	l--; r++;
}

void Remove(){
	int n = 0;
	for(int a = 1; 21 > a; a++)
	{
		for(int b = 1; 11 > b; b++)
		{
			if(map[a][b] != 3){break;}
			if(b == 10){
				n++;
				for(int c = 1; 11 > c; c++)
				{
					map[a][c] = 0;	
				}		
			}
		}
	}
	switch(n)
	{
		case 1:
			score += 100;
			last = 100;
			break;
		case 2:
			score += 300;
			last = 300;
			break;
		case 3:
			score += 600;
			last = 600;
			break;
		case 4:
			score += 1000;
			last = 1000;
			break;
	}
	tt += n;
}

void Down(){
	int d = 0;
	for(int a = High+1; a >= High; a--)
	{
		for(int b = l; 11-r > b; b++)
		{
			if((map[a][b] == 2&&(map[a+1][b] == 1||map[a+1][b] == 3)) || d == 1){
				d = 1;
				for(int i = 1; 21 > i; i++)
				{
					for(int j = 0; 11 > j; j++)
					{
						if(map[i][j] == 2){map[i][j] = 3; Set(a*2, b);}
					}
				}
				check = 1;
				break;
			}
		}
	}
	for(int a = High+1; a >= High; a--)
	{
		for(int b = l; 11-r > b; b++)
		{
			if(map[a][b] == 2){map[a+1][b] = 2; map[a][b] = 0; 
			Set(b*2, a+1);
			cout << "□";
			Set(b*2, a);
			cout << "  ";
			}
		}
	}
}

int Copy(){
	for(int a = 0; 2 > a; a++)
	{
		for(int b = 0; 4 > b; b++)
		{
			if(map[a+1][b+4] == 3){return 1;}
			if(block[a][b] == 2){map[a+1][b+4] = block[a][b];
			Set(b*2, a+1);
			cout << "□";
			Set(b*2, a);
			cout << "  ";
			}
		} 
	}
	return 0;
}

void Create()
{
	srand((unsigned)time(NULL));
	BlockNum = rand() % 7;
	switch(BlockNum)
	{
		case 0:
			block[0][0] = 0, block[0][1] = 2, block[0][2] = 2, block[0][3] = 0;
			block[1][0] = 0, block[1][1] = 2, block[1][2] = 2, block[1][3] = 0;
			r = 4, l = 4;
			break;
		case 1:
			block[0][0] = 0, block[0][1] = 0, block[0][2] = 2, block[0][3] = 0;
			block[1][0] = 2, block[1][1] = 2, block[1][2] = 2, block[1][3] = 0;
			r = 4, l = 3;
			break;
		case 2:
			block[0][0] = 2, block[0][1] = 0, block[0][2] = 0, block[0][3] = 0;
			block[1][0] = 2, block[1][1] = 2, block[1][2] = 2, block[1][3] = 0;
			r = 4, l = 3;
			break;
		case 3:
			block[0][0] = 0, block[0][1] = 2, block[0][2] = 0, block[0][3] = 0;
			block[1][0] = 2, block[1][1] = 2, block[1][2] = 2, block[1][3] = 0;
			r = 4, l = 3;
			break;
		case 4:
			block[0][0] = 2, block[0][1] = 2, block[0][2] = 0, block[0][3] = 0;
			block[1][0] = 0, block[1][1] = 2, block[1][2] = 2, block[1][3] = 0;
			r = 4, l = 3;
			break;
		case 5:
			block[0][0] = 0, block[0][1] = 2, block[0][2] = 2, block[0][3] = 0;
			block[1][0] = 2, block[1][1] = 2, block[1][2] = 0, block[1][3] = 0;
			r = 4, l = 3;
			break;
		case 6:
			block[0][0] = 2, block[0][1] = 2, block[0][2] = 2, block[0][3] = 2;
			block[1][0] = 0, block[1][1] = 0, block[1][2] = 0, block[1][3] = 0;
			r = 3, l = 3;
			break;
	}
}

void Print(){
	for(int a = 0; a < 22; a++)
	{
		for(int b = 0; b < 12; b++)
		{
			
			Set(b*2 ,a);
			
			switch(map[a][b])
			{
				case 0:
					cout << "  ";
					break;
				case 1:
					cout << "■";
					break;
				case 2:
					cout << "□";
					break;
				case 3:
					cout << "□";
					break;
			}
		}
		if(a == 8){cout << "  剩餘時間: ";} 
		if(a == 9){cout << "  上次得分: " << last;} 
		if(a == 10){cout << "  總分數: " << score;}
		if(a == 11){cout << "  消除數: " << tt;}
		cout << endl;
	}
}

int main(){
	
	while(1){
		if(check == 1){
			High = 1;
			Create();
			if(Copy()){GameOver(); break;}
			check = 0;
			}
		Print();
		float time1 = 0;
		while(1)
		{
			if(time1 == 25){break;}
			time1++;
			Time = (1000-time1*40)/1000;
			Set(36, 8);
			cout << fixed << setprecision(1) << Time << "s";
			if(_kbhit())
			{
				char ch = getch();
				switch(ch)
				{
					case 32: //空白鍵、換型態 
						Change(); 
					case 72: //上箭頭 ，換型態 
						Change();
						break;
					case 75: //左箭頭 ，左移 
						Left();
						break;
					case 77: //右箭頭，右移 
						Right();
						break;
					case 80: //下箭頭，加速下降 
						Down();
						High++;
						break;
				}
				Remove();
			}
			Sleep(40);
		}
		
		Down();
		High++;
		Remove();
		}
		
	return 0;
}

void Set(int x, int y){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(hOut, pos);
}
