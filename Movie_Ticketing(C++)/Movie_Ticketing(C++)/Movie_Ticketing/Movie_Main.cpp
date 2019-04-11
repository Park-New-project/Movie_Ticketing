// 영화 예약 프로그램
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
using namespace std;

void Design();
void M_Main();

#include "Member.h"

int main()
{
	system("mode con: lines=40 cols=100");

	//시작 화면
	for (int i = 0; i < 33; i++) {
		if (i == 0 || i == 32) { Design(); }
		else if (i == 11) {
			cout << "        ■      ■   ■■■    ■      ■ ■■■■  ■■■■" << endl;
			cout << "        ■■  ■■  ■     ■   ■    ■     ■     ■" << endl;
			cout << "        ■  ■  ■  ■     ■    ■  ■      ■     ■■■■" << endl;
			cout << "        ■      ■  ■     ■     ■■       ■     ■" << endl;
			cout << "        ■      ■   ■■■        ■     ■■■■  ■■■■" << endl;
			cout << endl << "                                           예약 프로그램  " << endl;
		}
		else if (i == 17) cout << "    Copyrightⓒ.2017.박민지.All Rights Reserved." << endl;
		else cout << endl;
	}
	Sleep(1500);
	system("cls");

	//프로그램
	M_Main();

	return 0;
}
void Design() {
	for (int i = 0; i < 50; i++)
	{
		if (i % 2)cout << "■";
		else cout << "□";
	}
	cout << endl;
	return;
}
void M_Main()
{
	Movie a;
	int check;
	while (1) {
		for (int i = 0; i < 30; i++) {
			if (i == 0 || i == 29) { Design(); }
			else if (i == 10)  cout << "                        1. 영화 예매하기" << endl;
			else if (i == 13)  cout << "                        2. 예매 조회하기" << endl;
			else if (i == 16)  cout << "                        3. 프로그램 종료" << endl;
			else cout << endl;
		}
		cout << endl<< "  -> 입력해주세요: ";
		cin >> check;

		if (check == 1) {
			system("cls");
			a.Movie_Book();
		}
		else if (check == 2) {
			system("cls");
			//추가 할 것
		}
		else if (check == 3) {
			system("cls");
			break;
		}
		else {
			cout << "  -> 잘못 입력되었습니다. 다시 입력해주세요: " << endl;
			Sleep(700); 
			system("cls");
		}
	}
}