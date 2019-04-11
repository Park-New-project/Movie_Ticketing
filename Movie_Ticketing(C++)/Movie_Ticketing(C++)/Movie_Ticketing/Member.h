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
	void Movie_Book();//1. 영화 예매하기
};
void Movie::Movie_Book()//1. 영화 예매하기
{
	int chj, chmo, chk, no;
	string j[6] = { "1. 서울","2. 인천", "3. 대전", "4. 대구",
		"5. 부산", "6. 강릉" };
	int k[8][5] = { {2,8,4,3,5}, {1,7,5,2,6}, {4,3,6,1,2}, {8,7,6,3,1} ,
	{ 3,5,2,8,4, },{ 7,3,5,2,6 },{ 7,3,5,1,2 },{ 1,7,2,3,6 } };

	ifstream fi("Movie.txt");
	fi >> no;
	Movie *mo = new Movie[no];
	for (int m = 0; m < no; m++) {
		fi >> mo[m].M_name >> mo[m].genre >> mo[m].runtime >> mo[m].star;
	}
	fi.close();

	//영화관 선택
	while (1) {
		for (int i = 0; i < 30; i++) {
			if (i == 0 || i == 29) { Design(); }
			else if (i == 6)  cout << "                        < 영 화 관  선 택 >" << endl;
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
		cout << endl << "  -> 입력해주세요: ";
		cin >> chj;
		if (chj > 6) {
			cout << "  -> 잘못 입력되었습니다. 다시 입력해주세요: " << endl;
			Sleep(700);
			system("cls");
		}
		else {
			system("cls");
			break;
		}
	}

	//영화 선택
	string moviename;
	while (1) {
		for (int i = 0; i < 14; i++) {
			if (i == 0 || i == 13) { Design(); }
			else if (i == 6)  cout << "                        < 영 화  선 택 >" << endl;
			else if (i == 8) {
				for (int m = 0; m < 5; m++) {
					cout << "                        ";
					cout << m + 1 << ". 제목: " << mo[m].M_name << endl;
					cout << "                        ";
					cout << mo[m].genre << " / " << mo[m].runtime << "분 / 별점 :" << mo[m].star << endl << endl << endl;
				}
			}
			else cout << endl;
		}
		cout << endl << "  -> 입력해주세요: ";
		cin >> chmo;
		if (chmo > 6) {
			cout << "  -> 잘못 입력되었습니다. 다시 입력해주세요: " << endl;
			Sleep(700);
			system("cls");
		}
		else {
			moviename = mo[chmo-1].Get_Data();
			system("cls");
			break;
		}

	}

	//시간 선택
	while (1) {
		for (int i = 0; i < 30; i++) {
			if (i == 0 || i == 29) { Design(); }
			else if (i == 7)  cout << "                     < 영 화 시 간  선 택 >" << endl;
			else if (i == 10) {
				cout << "                 1.  " << k[chj][chmo] << "관   ||   1 : 40 - ";
				cout << "                 4.  " << k[chj][chmo] << "관   ||   8 : 40 - ";
			}
			else if (i == 14) {
				cout << "                 2.  " << k[chj][chmo] << "관   ||   4 : 00 - ";
				cout << "                 5.  " << k[chj][chmo] << "관   ||   11 : 00 - ";
			}
			else if (i == 18) cout << "                 3.  " << k[chj][chmo] << "관   ||   6 : 20 - ";

			else cout << endl;
		}
		cout << endl << "  -> 입력해주세요: ";
		cin >> chk;
		if (chk > 6) {
			cout << "  -> 잘못 입력되었습니다. 다시 입력해주세요: " << endl;
			Sleep(700);
			system("cls");
		}
		else {
			system("cls");
			break;
		}
	}
	//좌석 선택

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
			else if (i == 6)  cout << "                     < 자 리 선 택 >" << endl;
			else if (i == 7)  cout << "                                   (□ = 빈 좌석,■ = 남은 좌석 ) " << endl;
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
						if (seat[m][j] == 0)cout << "□" << " ";
						else cout << "■" << " ";
					}
					cout << endl;
				}
			}
			else cout << endl;
		}
		cout << endl << "  -> 몇 명인지 입력해주세요: ";
		cin >> num;
		for (int t = 0; t < num; t++) {
			cout << endl << "  -> 자리를 순서대로 입력해주세요: ";
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
				cout << endl << "  -> 잘못 입력되었습니다. 다시 입력해주세요: " << endl;
				t--;
			}
			else {
				seat[c[t]][b[t] - 1] = 7;
			}
		}
		system("cls");
		break;
	}

	//자리 확인
	int n;
	while (1) {
		for (int i = 0; i < 15; i++) {
			if (i == 0 || i == 14) { Design(); }
			else if (i == 6)  cout << "                     < 자 리 확 인 >" << endl;
			else if (i == 7)  cout << "                                   (▩ = 선택 좌석 ) " << endl;
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
						if (seat[m][j] == 0) cout << "□" << " ";
						else if (seat[m][j] == 7) cout << "▩" << " ";
						else cout << "■" << " ";
					}
					cout << endl;
				}
			}
			else cout << endl;
		}
		cout << endl << "  -> 맞으면 0, 아니면 1을 입력해주세요: ";
		cin >> n;
		if (n == 0) {
			system("cls");
		}
		else {
			cout << endl << "  -> 취소되었습니다.";
			Sleep(700);
			system("cls");
		}
		break;
	}

	//결제 전 확인
	while (n==0) {
		for (int i = 0; i < 30; i++) {
			if (i == 0 || i == 29) { Design(); }
			else if (i == 6)  cout << "                     < 확 인 후  결 제 >" << endl;
			else if (i == 10) cout << "              영화 제목: " << moviename << "(" << k[chj][chmo] << "관)" << endl;
			else if (i == 13) cout << "              영화 관람 인원: " << num << "명" << endl;
			else if (i == 16) cout << "              결제 총액: " << num * 11000 << "원" << endl;
			else if (i == 19) {
				cout <<              "좌석: ";
				for (int t = 0; t < num; t++) {
					cout << a[t] <<" "<< b[t] <<",";
				}
			}
			else cout << endl;
		}
		cout << endl << "  -> 맞으면 0, 아니면 1을 입력해주세요: ";
		cin >> n;
		if (n == 0) {
			system("cls");
		}
		else {
			cout << endl << "  -> 취소되었습니다.";
			Sleep(700);
			system("cls");
			break;
		}
		break;
	}

	//결제
	Audience u;
	while (n == 0) {
		for (int i = 0; i < 30; i++) {
			if (i == 0 || i == 29) { Design(); }
			else if (i == 6)  cout << "                     < 결 제  화 면 >" << endl;
			else if (i == 10) {
				cout << "               이름: ";
				cin >> u.A_name;
			}
			else if (i == 12) {
				cout << "               카드번호(ex.xxxx-xxxx-xxxx-xxxx): ";
				cin >> u.card;
			}
			else if (i == 14) {
				cout << "               카드 비밀번호: " ;
				cin >> u.pw;
			}
			else cout << endl;
		}
		cout << endl << "  -> 결제가 완료되었습니다.";
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