#include <bits/stdc++.h>
#include "data.cpp"
#include "admin.cpp"
#include "user.cpp"
#include "book.cpp"
#include <windows.h>
#include "goto_draw.cpp"
using namespace std;
	int tt=0;		string mk;		string tk; long sohs,sosach;
	vector<hocsinh> hs;
	vector<book> sach;
	bool kkt = false;

void dangky(){
	string lmk=" ";string st;
	while (mk != lmk) 
		{
		bool kk = true;cout << "Nhap tai khoan: "; cin >> tk;
		while (kk == true) 
			{
			for (int i=0;i<=sohs;i++) if (tk == hs[i].getUserName()) {system("cls");cout << "Tai khoan da ton tai" << endl;kk=true;break;}else kk = false;
			if (kk == true) {cout << "Nhap tai khoan: "; getline(cin,tk);;}
			}
		cout << "Nhap mat khau: " ; cin >> mk;
		cout << "Nhap lai mat khau: "; cin >> lmk ;
		if (mk!=lmk) {
						system("cls");
						cout << "Mat khau nhap lai khong chinh xac, vui long dang ky lai" << endl;
					}
		}
	system("cls");cout <<"Dang ky thanh cong" << endl;
	fflush(stdin);cout << "Nhap ho ten cua ban: "; getline(cin,st);
	fstream fout;	fout.open("data.csv", ios::out | ios::app);
	hocsinh tam;
	fout << tk << "," << mk << "," << st << ",0;" << endl; 
	tam.setUserName(tk);tam.setPassword(mk);tam.hoten = st;tam.borrow = "0;";
	hs.push_back(tam);
	sohs++;
	user(hs,sohs,sach,sosach,sohs);
}

int tim(string st){
	for (int i=0;i<=sohs;i++) 
		{
			if ((st == hs[i].getUserName()) && (st == "admin")) {kkt=true;return i;}
			if (st == hs[i].getUserName()) return i;
			
		}
	return -1;
}
void check(int h){
	if (h == -1) {
		//system("cls");
		SetColor(0,4);GoTo(11,7);cout << "Khong co tai khoan hop le, nhap lai " << (char) 30;SetColor(0,7);
		GoTo(27,5);cout << "                    ";
		GoTo(26,6);cout << "                    ";
		GoTo(27,5); cin >> tk;
		GoTo(26,6); cin >> mk; check(tim(tk));
	}
	else {
		//system("cls");
		
		if (hs[h].getPassword() == mk) {if (kkt == true) {admin(hs,sohs,sach,sosach);kkt = false;}else user(hs,sohs,sach,sosach,h);}
			else 
			{
			GoTo(11,7);cout << "                                     ";
			SetColor(0,4);GoTo(11,7);cout << (char) 19 << " Mat khau sai";kkt = false;SetColor(0,7);
			GoTo(26,6);cout << "                    ";
			GoTo(26,6); cin >> mk; check(tim(tk));
			}
	};
	
}

void dangnhap(){
	
	//SetConsoleOutputCP(65001);
	system("cls");
	draw(9,2,47,8);
	GoTo(14,4);cout<< "DANG NHAP";
	GoTo(11,5);cout << "Nhap tai khoan: ";
	GoTo(11,6);cout << "Nhap mat khau: " ; 
	GoTo(27,5);cin >> tk;
	GoTo(11,6);cout << "Nhap mat khau: " ; cin >> mk; check(tim(tk));
}
void update(){
	fstream fin, fout;
	fin.open("data.csv", ios::in);
	fout.open("datanew.csv", ios::out);
	for (int i=0;i<=sohs;i++)
		{
			fout << hs[i].getUserName() << "," << hs[i].getPassword() << "," << hs[i].hoten << "," << hs[i].borrow << "\n";
		}
	fin.close();
	fout.close();

	// removing the existing file
	remove("data.csv");

	// renaming the updated file with the existing file name
	rename("datanew.csv", "data.csv");
	// SACH
//	fstream fin, fout;
	fin.open("danhsachsach.csv", ios::in);
	fout.open("danhsachsachnew.csv", ios::out);
	for (int i=0;i<=sosach;i++)
		{
			fout << sach[i].code << "," <<  sach[i].bookname << "," << sach[i].amount << "\n";
		}
	fin.close();
	fout.close();

	// removing the existing file
	remove("danhsachsach.csv");

	// renaming the updated file with the existing file name
	rename("danhsachsachnew.csv", "danhsachsach.csv");
	// SACH
};
int main(){

int t=-1;
ifstream ip("data.csv");
  string username;
  string password;
  string borroww;
  string hotenn;
  while (ip.peek()!=EOF)
{
	t++;
    getline(ip,username,',');
    getline(ip,password,',');
    getline(ip,hotenn,',');
    getline(ip,borroww,'\n');
   
	hocsinh tam; tam.setUserName(username);tam.setPassword(password);tam.hoten = hotenn;tam.borrow = borroww;	
    hs.push_back(tam);
  }
sohs = t;
ip.close();

ifstream ip2("danhsachsach.csv");
t=-1;
  while (ip2.peek()!=EOF)
{
	t++;
	book ta;
	getline(ip2,ta.code,',');
    getline(ip2,ta.bookname,',');
    getline(ip2,ta.amount,'\n');
  //  getline(ip2,ta.price,'\n');
    sach.push_back(ta);
  }
sosach = t;
ip2.close();
//cout << hs[7].hoten;
GoTo(10,2);cout << "QUAN LY THU VIEN";
//drawbook();
GoTo(75,25);cout << "San pham cua nhom 6 - 20KTMT1:";
	GoTo(78,26);cout << (char)175 << " Ton That Hai";
	GoTo(78,27);cout << (char)175 << " Ngo Xuan Sy";
	GoTo(78,28);cout << (char)175 << " Le Pham Cong";
GoTo(11,5);cout << "1. Dang nhap " << endl;
GoTo(11,6);cout << "2. Dang ky " << endl;
GoTo(11,7);int ma; cout << "Nhap lua chon cua ban: ";cin >> ma;
switch (ma){
	case 1: dangnhap();break;
	case 2: dangky();
}

update();

return 0;
}

