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
int r, l, rr, ll; //判斷是否最左或最右 
int BlockNum = 0; // 隨機方塊紀錄 
int High = 0; //紀錄高度，減少計算 
int game = 0; //難度 
int mode = 0; //紀錄方塊變形
int rmode = 0; //紀錄上一個方塊變形 
int ChangeBlock[4][4] = {0}; //方塊變形儲存
float Time = 0; //計算時間 
void Print();
void Set(int x, int y);

void One()
{
	switch(mode){
		case 1:
			mode = 2; rr = r; ll = l+1;
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 2, ChangeBlock[0][3] = 2;
			ChangeBlock[1][0] = 0, ChangeBlock[1][1] = 0, ChangeBlock[1][2] = 0, ChangeBlock[1][3] = 2;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 0, ChangeBlock[2][2] = 0, ChangeBlock[2][3] = 2;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 0;
			break;
		case 2:
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 2, ChangeBlock[1][1] = 2, ChangeBlock[1][2] = 2, ChangeBlock[1][3] = 0;
			ChangeBlock[2][0] = 2, ChangeBlock[2][1] = 0, ChangeBlock[2][2] = 0, ChangeBlock[2][3] = 0;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 0;
			mode = 3; rr = r; ll = l-1;
			break;
		case 3:
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 2, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 0, ChangeBlock[1][1] = 0, ChangeBlock[1][2] = 2, ChangeBlock[1][3] = 0;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 0, ChangeBlock[2][2] = 2, ChangeBlock[2][3] = 2;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 0;
			mode = 4; rr = r; ll = l+1;
			break;
		case 4:
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 0, ChangeBlock[1][1] = 0, ChangeBlock[1][2] = 2, ChangeBlock[1][3] = 0;
			ChangeBlock[2][0] = 2, ChangeBlock[2][1] = 2, ChangeBlock[2][2] = 2, ChangeBlock[2][3] = 0;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 0;
			mode = 1; rr = r; ll = l-1;
			break;
	}
}
void Two()
{
	switch(mode){
		case 1:
			mode = 2; rr = r; ll = l+1;
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 0, ChangeBlock[1][1] = 0, ChangeBlock[1][2] = 0, ChangeBlock[1][3] = 2;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 0, ChangeBlock[2][2] = 0, ChangeBlock[2][3] = 2;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 2, ChangeBlock[3][3] = 2;
			break;
		case 2:
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 2, ChangeBlock[1][1] = 2, ChangeBlock[1][2] = 2, ChangeBlock[1][3] = 0;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 0, ChangeBlock[2][2] = 2, ChangeBlock[2][3] = 0;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 0;
			mode = 3; rr = r; ll = l-1;
			break;
		case 3:
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 0, ChangeBlock[1][1] = 0, ChangeBlock[1][2] = 2, ChangeBlock[1][3] = 2;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 0, ChangeBlock[2][2] = 2, ChangeBlock[2][3] = 0;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 2, ChangeBlock[3][3] = 0;
			mode = 4; rr = r; ll = l+1;
			break;
		case 4:
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 2, ChangeBlock[1][1] = 0, ChangeBlock[1][2] = 0, ChangeBlock[1][3] = 0;
			ChangeBlock[2][0] = 2, ChangeBlock[2][1] = 2, ChangeBlock[2][2] = 2, ChangeBlock[2][3] = 0;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 0;
			mode = 1; rr = r; ll = l-1;
			break;
	}
}
void Three()
{
	switch(mode){
		case 1:
			mode = 2; rr = r; ll = l+1;
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 0, ChangeBlock[1][1] = 0, ChangeBlock[1][2] = 0, ChangeBlock[1][3] = 2;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 0, ChangeBlock[2][2] = 2, ChangeBlock[2][3] = 2;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 2;
			break;
		case 2:
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 2, ChangeBlock[1][1] = 2, ChangeBlock[1][2] = 2, ChangeBlock[1][3] = 0;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 2, ChangeBlock[2][2] = 0, ChangeBlock[2][3] = 0;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 0;
			mode = 3; rr = r; ll = l-1;
			break;
		case 3:
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 0, ChangeBlock[1][1] = 0, ChangeBlock[1][2] = 2, ChangeBlock[1][3] = 0;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 0, ChangeBlock[2][2] = 2, ChangeBlock[2][3] = 2;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 2, ChangeBlock[3][3] = 0;
			mode = 4; rr = r; ll = l+1;
			break;
		case 4:
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 0, ChangeBlock[1][1] = 2, ChangeBlock[1][2] = 0, ChangeBlock[1][3] = 0;
			ChangeBlock[2][0] = 2, ChangeBlock[2][1] = 2, ChangeBlock[2][2] = 2, ChangeBlock[2][3] = 0;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 0;
			mode = 1; rr = r; ll = l-1;
			break;
	}
}
void Four()
{
	switch(mode){
		case 1:
			mode = 2; rr = r; ll = l+1;
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 0, ChangeBlock[1][1] = 0, ChangeBlock[1][2] = 0, ChangeBlock[1][3] = 2;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 0, ChangeBlock[2][2] = 2, ChangeBlock[2][3] = 2;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 2, ChangeBlock[3][3] = 0;
			break;
		case 2:
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 2, ChangeBlock[1][1] = 2, ChangeBlock[1][2] = 0, ChangeBlock[1][3] = 0;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 2, ChangeBlock[2][2] = 2, ChangeBlock[2][3] = 0;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 0;
			mode = 1; rr = r; ll = l-1;
			break;
	}
}
void Five()
{
	switch(mode){
		case 1:
			mode = 2; rr = r; ll = l+1;
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 0, ChangeBlock[1][1] = 0, ChangeBlock[1][2] = 2, ChangeBlock[1][3] = 0;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 0, ChangeBlock[2][2] = 2, ChangeBlock[2][3] = 2;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 2;
			break;
		case 2:
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 0, ChangeBlock[1][1] = 2, ChangeBlock[1][2] = 2, ChangeBlock[1][3] = 0;
			ChangeBlock[2][0] = 2, ChangeBlock[2][1] = 2, ChangeBlock[2][2] = 0, ChangeBlock[2][3] = 0;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 0;
			mode = 1; rr = r; ll = l-1;
			break;
	}
}
void Six()
{
	switch(mode){
		case 1:
			mode = 2; rr = r+2; ll = l+1;
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 2, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 0, ChangeBlock[1][1] = 2, ChangeBlock[1][2] = 0, ChangeBlock[1][3] = 0;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 2, ChangeBlock[2][2] = 0, ChangeBlock[2][3] = 0;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 2, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 0;
			break;
		case 2:
			mode = 1; rr = r-2; ll = l-1;
			ChangeBlock[0][0] = 0, ChangeBlock[0][1] = 0, ChangeBlock[0][2] = 0, ChangeBlock[0][3] = 0;
			ChangeBlock[1][0] = 2, ChangeBlock[1][1] = 2, ChangeBlock[1][2] = 2, ChangeBlock[1][3] = 2;
			ChangeBlock[2][0] = 0, ChangeBlock[2][1] = 0, ChangeBlock[2][2] = 0, ChangeBlock[2][3] = 0;
			ChangeBlock[3][0] = 0, ChangeBlock[3][1] = 0, ChangeBlock[3][2] = 0, ChangeBlock[3][3] = 0;
			break;
	}
}

void Lobby(){
	int choice = 0;
	cout << "       選擇遊戲難度  " << endl;
	cout << "     ----------------" << endl;
	cout << "     |  1 簡單模式  |" << endl;
	cout << "     |  2 普通模式  |" << endl;
	cout << "     |  3 困難模式  |" << endl;
	cout << "     ----------------" << endl;
	cin >> choice;
	switch(choice)
	{
		case 1:
			game = 35;
			break;
		case 2:
			game = 25;
			break;
		case 3:
			game = 15;
			break;
	}
}

void GameOver(){
	system("cls");
	cout << endl << "     | Game Over |" << endl << "     |獲得分數: " << score << "|" << endl << "     |消除總數: " << tt << "|" <<  endl;
}

int Change()
{
	int k = 0;
	rmode = mode;
	switch(BlockNum)
	{
		case 0:
			return 0;
		case 1:
			if(High >= 1)
			{
				One();
				k = 3;
				break;
			}
			else{return 0;}
		case 2:
			if(High >= 1)
			{
				Two();
				k = 3;
				break;
			}
			else{return 0;}
		case 3:
			if(High >= 1)
			{
				Three();
				k = 3;
				break;
			}
			else{return 0;}
		case 4:
			if(High >= 1)
			{
				Four();
				k = 3;
				break;
			}			
			else{return 0;}
		case 5:
			if(High >= 1)
			{
				Five();
				k = 3;
				break;
			}
			else{return 0;}
		case 6:
			if(High >= 2)
			{
				Six();
				if(mode == 1){k = 3;}
				else{k = 4;}
				break;
			}
			else{return 0;}
	}
	for(int a = 0; 4 > a; a++)
	{
		for(int b = 0; 4 > b; b++)
		{
			if(ChangeBlock[a][b] == 2){
				if(map[a+High][b+l] == 1||map[a+High][b+l] == 3){mode = rmode; return 0;}
			}
		}
	}
	for(int a = 0; 4 > a; a++)
	{
		for(int b = 0; 4 > b; b++)
		{
			if(map[a+High-1][b+l-3+k] == 2&&ChangeBlock[a][b] == 0){
				map[a+High-1][b+l-3+k] = 0;
				Set((b+l-3+k)*2, a+High-1);
				cout << "  ";
			}
			if(ChangeBlock[a][b] == 2&&map[a+High-1][b+l-3+k] == 0){
				map[a+High-1][b+l-3+k] = 2;
				Set((b+l-3+k)*2, a+High-1);
				cout << "□";
			}
		}
	}
	r = rr; l = ll;
}

int Right()
{
	if(r == 0){return 0;}
	for(int a = 1; 21 >= a; a++)
	{
		for(int b = 11; b > 1; b--)
		{
			if(map[a][b] == 2){if(map[a][b+1] != 0){return 0;}break;}
		}
	}
	for(int a = 1; 21 >= a; a++)
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
	for(int a = 1; 21 >= a; a++)
	{
		for(int b = 1; 11 >= b; b++)
		{
			if(map[a][b] == 2){if(map[a][b-1] != 0){return 0;}break;}
		}
	}
	for(int a = 1; 21 >= a; a++)
	{
		for(int b = 1; 11 >= b; b++)
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
	for(int a = High+3; a >= High-3; a--)
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
	for(int a = High+2; a >= High-3; a--)
	{
		for(int b = l; 11-r >= b; b++)
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
	Lobby();
	while(1){
		if(check == 1){
			mode = 1;
			High = 1;
			Create();
			if(Copy()){GameOver(); break;}
			check = 0;
			}
		Print();
		float time1 = 0;
		while(1)
		{
			if(time1 == game){break;}
			time1++;
			Time = (game-time1)/25;
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
						time1 = 0;
						High++;
						break;
				}
				Remove();
			}
			if(High == 20){break;}
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
