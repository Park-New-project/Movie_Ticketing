// ��ȭ ���� ���α׷�
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

	//���� ȭ��
	for (int i = 0; i < 33; i++) {
		if (i == 0 || i == 32) { Design(); }
		else if (i == 11) {
			cout << "        ��      ��   ����    ��      �� �����  �����" << endl;
			cout << "        ���  ���  ��     ��   ��    ��     ��     ��" << endl;
			cout << "        ��  ��  ��  ��     ��    ��  ��      ��     �����" << endl;
			cout << "        ��      ��  ��     ��     ���       ��     ��" << endl;
			cout << "        ��      ��   ����        ��     �����  �����" << endl;
			cout << endl << "                                           ���� ���α׷�  " << endl;
		}
		else if (i == 17) cout << "    Copyright��.2017.�ڹ���.All Rights Reserved." << endl;
		else cout << endl;
	}
	Sleep(1500);
	system("cls");

	//���α׷�
	M_Main();

	return 0;
}
void Design() {
	for (int i = 0; i < 50; i++)
	{
		if (i % 2)cout << "��";
		else cout << "��";
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
			else if (i == 10)  cout << "                        1. ��ȭ �����ϱ�" << endl;
			else if (i == 13)  cout << "                        2. ���� ��ȸ�ϱ�" << endl;
			else if (i == 16)  cout << "                        3. ���α׷� ����" << endl;
			else cout << endl;
		}
		cout << endl<< "  -> �Է����ּ���: ";
		cin >> check;

		if (check == 1) {
			system("cls");
			a.Movie_Book();
		}
		else if (check == 2) {
			system("cls");
			//�߰� �� ��
		}
		else if (check == 3) {
			system("cls");
			break;
		}
		else {
			cout << "  -> �߸� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���: " << endl;
			Sleep(700); 
			system("cls");
		}
	}
}