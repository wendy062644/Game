#include<iostream> 
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include <cstdlib> 
#include <math.h>
using namespace std;
void PrintPerson();
int map[30][60] = {
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 2, 0, 2, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int ez[5][5] = {
{0, 0, 1, 0, 0},
{0, 1, 1, 1, 0},
{1, 0, 1, 0, 1},
{0, 1, 0, 1, 0},
{0, 1, 0, 1, 0}
};
int med[7][7];
int hard[9][9];
int pur[15][15];
int l = 0, r = 0, h = 0, realh = 0, myh = 250, realmyh = 250;
int pr = 53, pl = 1;
int AttackNum = 0;

void Set(int x, int y);
bool lang = 0;
int mode = 0;
void PrintHealth();

void Print(){
	for(int a = 0; 30 > a; a++)
	{
		for(int b = 0; 60 > b; b++)
		{
			if(map[a][b] == 0){cout << "  ";}
			else if(map[a][b] == 1){cout << "■";}
			else{cout << "  ";}
		}
		cout << endl;
	} 
}

void PrintPerson()
{
	for(int a = 1; 30 > a; a++)
	{
		for(int b = 1; 60 > b; b++)
		{
			if(map[a][b] == 2){Set(b*2, a); cout << "*";}
		}
	}
}

void Language()
{	
	Set(44, 11);
	cout << "選擇語言 Choose A Language";
	Set(50, 13);
	cout << "「1」繁體中文";
	Set(50, 15);
	cout << "「2」English";
	int ch = getch();
	if(ch == 49){lang = false;}
	else{lang = true;}
}

void Choice(){
	Set(52, 10);
	cout << "- Game Mode -";
	Set(52, 12);
	cout << "「1」Easy";
	Set(52, 14);
	cout << "「2」Medium";
	Set(52, 16);
	cout << "「3」Hard";
	Set(52, 18);
	cout << "「4」Purgatory";
	int ch = getch();
	mode = ch-48;
}

void Choice1(){
	Set(50, 10);
	cout << "-選.擇.遊.戲.模.式-";
	Set(52, 12);
	cout << "「1」簡單模式";
	Set(52, 14);
	cout << "「2」正常模式";
	Set(52, 16);
	cout << "「3」困難模式";
	Set(52, 18);
	cout << "「4」煉獄模式";
	int ch = getch();
	mode = ch-48;
	switch (mode){
		case 1:
			l = 53; r = 1; h = 125, realh = 125;
			break;
		case 2:
			l = 51; r = 1; h = 200, realh = 200;
			break;
		case 3:
			l = 49; r = 1; h = 400, realh = 400;
			break;
		case 4:
			l = 43; r = 1; h = 700, realh = 700;
			break;
	}
}

void Skill(){
	
}

void Ultimate(){
	
}

void Attack()
{
	int n = 0;
	map[25][pl+6] = 5;
	AttackNum++;
	Set((pl+6)*2, 25);
	cout << "O ";
}

void Heal()
{
	
}

void PrintHealth()
{
	for(int a = 0; h/25 > a; a++)
	{
		Set(60+a*2, 2);
		if(realh >= (a)*25){cout << "■";}
		else{cout << "□";}
	}
	Set(61, 3);
	for(int a = 0; (int)log10(abs(h))-(int)log10(abs(realh)) > a; a++)
	{
		cout << " ";
	}
	cout << realh << "/" << h;
	for(int a = 0; myh/25 > a; a++)
	{
		Set(56-a*2, 2);
		if(realmyh >= (a)*25){cout << "■";}
		else{cout << "□";}
	}
	Set(49, 3);
	for(int a = 0; (int)log10(abs(myh))-(int)log10(abs(realmyh)) > a; a++)
	{
		cout << " ";
	}
	cout << realmyh << "/" << myh;
}

void pause(){
	system("cls");
	Print();
	Set(56, 11);
	if(lang){
		cout << "- PAUSE -";
		Set(49, 13);
		cout << "Press space to continue";
	}
	else{cout << "遊戲暫停";
		Set(54, 13);
		cout << "按空白鍵繼續";
	}
	while(1)
	{
		char input = getch();
		switch(input)
		{
			case 32: //空白鍵，遊戲繼續
				system("cls");
				Print();
				return;
		}
	}
}

void Up(){
	
}

void Right(){
	if(pr == 0){return;}
	pr--;
	for(int a = 1; 30 > a; a++)
	{
		for(int b = 1; 60 > b; b++)
		{
			if(map[a][b] == 2){if(map[a][b+1] == 1||map[a][b+1] == 3){pr++; return;}}
		}
	}
	for(int a = 1; 30 > a; a++)
	{
		for(int b = 59; b > 0; b--)
		{
			if(map[a][b] == 2){map[a][b+1] = 2; map[a][b] = 0; Set(b*2, a); cout << "  ";}
		}
	}
	pl++;
	PrintPerson();
}

void Left(){
	if(pl == 0){return;}
	pl--;
	for(int a = 1; 30 > a; a++)
	{
		for(int b = 1; 60 > b; b++)
		{
			if(map[a][b] == 2){if(map[a][b-1] == 1||map[a][b-1] == 3){pl++; return;}}
		}
	}
	for(int a = 1; 30 > a; a++)
	{
		for(int b = 1; 60 > b; b++)
		{
			if(map[a][b] == 2){map[a][b-1] = 2; map[a][b] = 0; Set(b*2, a); cout << " ";}
		}
	}
	pr++;
	PrintPerson();
}

void Down(){
	
}

void PrintBoss(){
	switch (mode){
		case 1:
		for(int a = 24; 30 > a; a++)
		{
			for(int b = l; l+5 > b; b++)
			{
				if(ez[a-24][b-l] == 1){map[a][b] = 3; Set(b*2, a);cout << "*";}
			}
		}
		break;
	}
}

void AttackKeep()
{
	for(int a = 59; a > 1; a--)
	{
		for(int b = 3; 29 > b; b++)
		{
			if(map[b][a] == 5){
				if(map[b][a+1] == 3){map[b][a] = 0; AttackNum--; realh = realh -5; Set(a*2, b); cout << "  "; PrintHealth();}
				else if(a == 59){map[b][a] = 0; Set(a*2, b); cout << "  ";}
				else{map[b][a] = 0; map[b][a+1] = 5; Set(a*2, b); cout << "  O ";}
			}
		}
	}
}

int main()
{
	Print();
	Sleep(1000);
	Language();
	system("cls");
	Print();
	if(lang){Choice();}
	else{Choice1();}
	system("cls");
	Print();
	Sleep(100);
	PrintPerson();
	PrintHealth();
	PrintBoss();
	while(1)
	{
		if(AttackNum){AttackKeep();}
		int times = 3;
		while(times--)
		{
			if(_kbhit())
			{
				char ch = getch();
				switch(ch)
				{
					case 27: //ESC，遊戲暫停
						pause();
						PrintPerson();
						PrintHealth();
						PrintBoss();
						break;
					case 72: //上鍵
						Up();
						break;
					case 75: //左鍵 
						Left();
						break;
					case 77: //右鍵 
						Right();
						break;
					case 80: //下鍵 
						Down();
						break;
					case 32: //空白建，攻擊 
						Attack();
						break;
					case 81: //補血 
						Heal();
						break;
					case 87: //技能 
						Skill();
						break;
					case 69: //大絕招 
						Ultimate();
						break; 
				}
			}
			Sleep(1);
		}
	}
}

void Set(int x, int y){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = {x, y};
	SetConsoleCursorPosition(hOut, pos);
}
