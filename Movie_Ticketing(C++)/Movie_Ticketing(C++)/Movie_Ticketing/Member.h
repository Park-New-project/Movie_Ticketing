#ifndef Movie_h
#define Movie_h

struct Audience{
	string A_name;
	string card;
	int pw;
};
class Movie {
	string M_name;
	string genre;
	int runtime;
	double star;
public:
	void Set_Data(string n, string g, int t, double s) {
		M_name = n;
		genre = g;
		runtime = t;
		star = s;
	}
	string Get_Data() {
		return M_name;
	}
	void Movie_Book();//1. ��ȭ �����ϱ�
};
void Movie::Movie_Book()//1. ��ȭ �����ϱ�
{
	int chj, chmo, chk, no;
	string j[6] = { "1. ����","2. ��õ", "3. ����", "4. �뱸",
		"5. �λ�", "6. ����" };
	int k[8][5] = { {2,8,4,3,5}, {1,7,5,2,6}, {4,3,6,1,2}, {8,7,6,3,1} ,
	{ 3,5,2,8,4, },{ 7,3,5,2,6 },{ 7,3,5,1,2 },{ 1,7,2,3,6 } };

	ifstream fi("Movie.txt");
	fi >> no;
	Movie *mo = new Movie[no];
	for (int m = 0; m < no; m++) {
		fi >> mo[m].M_name >> mo[m].genre >> mo[m].runtime >> mo[m].star;
	}
	fi.close();

	//��ȭ�� ����
	while (1) {
		for (int i = 0; i < 30; i++) {
			if (i == 0 || i == 29) { Design(); }
			else if (i == 6)  cout << "                        < �� ȭ ��  �� �� >" << endl;
			else if (i == 10) {
				cout << "                        ";
				for (int m = 0; m < 3; m++) cout << j[m] << "    ";
			}
			else if (i == 14) {
				cout << "                        ";
				for (int m = 3; m < 6; m++) cout << j[m] << "    ";
			}
			else cout << endl;
		}
		cout << endl << "  -> �Է����ּ���: ";
		cin >> chj;
		if (chj > 6) {
			cout << "  -> �߸� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���: " << endl;
			Sleep(700);
			system("cls");
		}
		else {
			system("cls");
			break;
		}
	}

	//��ȭ ����
	string moviename;
	while (1) {
		for (int i = 0; i < 14; i++) {
			if (i == 0 || i == 13) { Design(); }
			else if (i == 6)  cout << "                        < �� ȭ  �� �� >" << endl;
			else if (i == 8) {
				for (int m = 0; m < 5; m++) {
					cout << "                        ";
					cout << m + 1 << ". ����: " << mo[m].M_name << endl;
					cout << "                        ";
					cout << mo[m].genre << " / " << mo[m].runtime << "�� / ���� :" << mo[m].star << endl << endl << endl;
				}
			}
			else cout << endl;
		}
		cout << endl << "  -> �Է����ּ���: ";
		cin >> chmo;
		if (chmo > 6) {
			cout << "  -> �߸� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���: " << endl;
			Sleep(700);
			system("cls");
		}
		else {
			moviename = mo[chmo-1].Get_Data();
			system("cls");
			break;
		}

	}

	//�ð� ����
	while (1) {
		for (int i = 0; i < 30; i++) {
			if (i == 0 || i == 29) { Design(); }
			else if (i == 7)  cout << "                     < �� ȭ �� ��  �� �� >" << endl;
			else if (i == 10) {
				cout << "                 1.  " << k[chj][chmo] << "��   ||   1 : 40 - ";
				cout << "                 4.  " << k[chj][chmo] << "��   ||   8 : 40 - ";
			}
			else if (i == 14) {
				cout << "                 2.  " << k[chj][chmo] << "��   ||   4 : 00 - ";
				cout << "                 5.  " << k[chj][chmo] << "��   ||   11 : 00 - ";
			}
			else if (i == 18) cout << "                 3.  " << k[chj][chmo] << "��   ||   6 : 20 - ";

			else cout << endl;
		}
		cout << endl << "  -> �Է����ּ���: ";
		cin >> chk;
		if (chk > 6) {
			cout << "  -> �߸� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���: " << endl;
			Sleep(700);
			system("cls");
		}
		else {
			system("cls");
			break;
		}
	}
	//�¼� ����

	ifstream fin("Seat.txt");
	int seat[8][20], n1;

	while (1) {
		fin >> n1;
		if (n1 == (chj - 1) * 100 + (chmo - 1) * 10 + (chk - 1) + 2) break;
	}

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 20; j++) {
			fin >> seat[i][j];
		}
	}
	fin.close();

	char ask[8] = { 'A','B','C','D','E','F','G','H' }, a[30];
	int b[30], c[30], num;
	while (1) {
		for (int i = 0; i < 15; i++) {
			if (i == 0 || i == 14) { Design(); }
			else if (i == 6)  cout << "                     < �� �� �� �� >" << endl;
			else if (i == 7)  cout << "                                   (�� = �� �¼�,�� = ���� �¼� ) " << endl;
			else if (i == 10) {
				cout << "        ";
				for (int j = 0; j < 20; j++) {
					if (j < 8) cout << j + 1 << "  ";
					else cout << j + 1 << " ";
				}
				cout << endl;

				for (int m = 0; m < 8; m++) {
					cout << "      " << ask[m] << " ";
					for (int j = 0; j < 20; j++) {
						if (seat[m][j] == 0)cout << "��" << " ";
						else cout << "��" << " ";
					}
					cout << endl;
				}
			}
			else cout << endl;
		}
		cout << endl << "  -> �� ������ �Է����ּ���: ";
		cin >> num;
		for (int t = 0; t < num; t++) {
			cout << endl << "  -> �ڸ��� ������� �Է����ּ���: ";
			cin >> a[t] >> b[t];
			if (a[t] == 'A') c[t] = 0;
			else if (a[t] == 'B') c[t] = 1;
			else if (a[t] == 'C') c[t] = 2;
			else if (a[t] == 'D') c[t] = 3;
			else if (a[t] == 'E') c[t] = 4;
			else if (a[t] == 'F') c[t] = 5;
			else if (a[t] == 'G') c[t] = 6;
			else c[t] = 7;

			if (seat[c[t]][b[t]] == 1 || a[t] > 'H' || b[t] > 20) {
				cout << endl << "  -> �߸� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���: " << endl;
				t--;
			}
			else {
				seat[c[t]][b[t] - 1] = 7;
			}
		}
		system("cls");
		break;
	}

	//�ڸ� Ȯ��
	int n;
	while (1) {
		for (int i = 0; i < 15; i++) {
			if (i == 0 || i == 14) { Design(); }
			else if (i == 6)  cout << "                     < �� �� Ȯ �� >" << endl;
			else if (i == 7)  cout << "                                   (�� = ���� �¼� ) " << endl;
			else if (i == 10) {
				cout << "        ";
				for (int j = 0; j < 20; j++) {
					if (j < 8) cout << j + 1 << "  ";
					else cout << j + 1 << " ";
				}
				cout << endl;

				for (int m = 0; m < 8; m++) {
					cout << "      " << ask[m] << " ";
					for (int j = 0; j < 20; j++) {
						if (seat[m][j] == 0) cout << "��" << " ";
						else if (seat[m][j] == 7) cout << "��" << " ";
						else cout << "��" << " ";
					}
					cout << endl;
				}
			}
			else cout << endl;
		}
		cout << endl << "  -> ������ 0, �ƴϸ� 1�� �Է����ּ���: ";
		cin >> n;
		if (n == 0) {
			system("cls");
		}
		else {
			cout << endl << "  -> ��ҵǾ����ϴ�.";
			Sleep(700);
			system("cls");
		}
		break;
	}

	//���� �� Ȯ��
	while (n==0) {
		for (int i = 0; i < 30; i++) {
			if (i == 0 || i == 29) { Design(); }
			else if (i == 6)  cout << "                     < Ȯ �� ��  �� �� >" << endl;
			else if (i == 10) cout << "              ��ȭ ����: " << moviename << "(" << k[chj][chmo] << "��)" << endl;
			else if (i == 13) cout << "              ��ȭ ���� �ο�: " << num << "��" << endl;
			else if (i == 16) cout << "              ���� �Ѿ�: " << num * 11000 << "��" << endl;
			else if (i == 19) {
				cout <<              "�¼�: ";
				for (int t = 0; t < num; t++) {
					cout << a[t] <<" "<< b[t] <<",";
				}
			}
			else cout << endl;
		}
		cout << endl << "  -> ������ 0, �ƴϸ� 1�� �Է����ּ���: ";
		cin >> n;
		if (n == 0) {
			system("cls");
		}
		else {
			cout << endl << "  -> ��ҵǾ����ϴ�.";
			Sleep(700);
			system("cls");
			break;
		}
		break;
	}

	//����
	Audience u;
	while (n == 0) {
		for (int i = 0; i < 30; i++) {
			if (i == 0 || i == 29) { Design(); }
			else if (i == 6)  cout << "                     < �� ��  ȭ �� >" << endl;
			else if (i == 10) {
				cout << "               �̸�: ";
				cin >> u.A_name;
			}
			else if (i == 12) {
				cout << "               ī���ȣ(ex.xxxx-xxxx-xxxx-xxxx): ";
				cin >> u.card;
			}
			else if (i == 14) {
				cout << "               ī�� ��й�ȣ: " ;
				cin >> u.pw;
			}
			else cout << endl;
		}
		cout << endl << "  -> ������ �Ϸ�Ǿ����ϴ�.";
		Sleep(700);
		system("cls");

		ofstream fo("Audience.txt");
		fo << u.A_name << " " << u.card << " " << u.pw << " ";
		for (int t = 0; t < num; t++) {
			fo << a[t] << " " << b[t] << " ";
		}
		fo << moviename << endl;
		fo.close();

		break;
	}
	return;
	delete mo;
}
#endif