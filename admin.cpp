#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "data.cpp"
#include <stdlib.h>
#include "book.cpp"
#include <sstream>
#include "goto_draw.cpp"
using namespace std;

void ad1(vector<hocsinh> hs,long sohs,vector<book> sach,long sosach){
	long k=1;
	
	string st;
	cout << "Nhap username cua nguoi ma ban muon tra cuu: "; cin >> st;bool chay = false;
	for (int i=1;i<=sohs;i++)
		if (st == hs[i].getUserName()) 
			{	chay = true;
				cout << "Ho va ten: " << hs[i].hoten << endl;
				if (hs[i].borrow == "0;") cout << "!!! Hien tai hoc sinh nay chua muon sach cua thu vien" << endl;
				else {
				cout << "Cac sach dang muon: " << endl; 
				st = hs[i].borrow;
				string sst;
				for (int i=0;i<st.length();i++) if (st[i] == ';')
													{
														int num; 
														stringstream ss;  
														ss << sst;  
														ss >> num; 	// CHUYEN XAU SANG SO - 1
														cout << k << ". " << sach[num].bookname << endl;
														k++;
														sst ="";
													}
													else sst = sst + st[i];
				}
			}
	if (chay == false) {
		system("cls");
		cout << "Username khong ton tai" << endl;
		ad1(hs,sohs,sach,sosach);
	}

}
void ad2(vector<hocsinh> hs, long sohs, vector<book> sach, long sosach)
{
    system("cls");
    string t;
    string st;
    int i = 1;
    int sl[20];
    for (int i = 1; i <= 19; i++)
    {
        sl[i] = 0;
    }
    cout << "++++++++ DANH SACH CAC SINH VIEN DANG MUON SACH ++++++++ " << endl
         << endl;
    cout << "____________________________________________________" << endl;
    cout << setw(2	) << left << "|";
    cout << setw(4) << left << "STT";
    cout << setw(11) << left << "|";
    cout << setw(23) << left << "Ten sinh vien";
    cout << setw(2) << left << "|";
    cout << setw(9) << left << "so luong"
         << "|" << endl;
    cout << "____________________________________________________" << endl;
    for (int i = 1; i <= sohs; i++)
    {
        st = hs[i].borrow;
        string sst;
        for (int j = 0; j < st.length(); j++)
            if (st[j] == ';')
            {
                sl[i] = sl[i] + 1;
                sst = "";
            }
            else
                sst = sst + st[j];
    }

    int j = 1;
    while (i <= sohs)
    {
        t = hs[i].borrow;
        if (t != "0;")
        {
            cout << setw(3) << left << "|";
            cout << setw(3) << left << j;
            cout << setw(4) << left << "|";
            cout << setw(30) << hs[i].hoten;
            cout << setw(5) << left << "|";
            cout << setw(6) << left << sl[i] << "|" << endl;
            j++;
        }
        i++;
    };
    cout << "____________________________________________________" << endl
         << endl;
    cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
}
void ad3(vector<hocsinh> hs, long sohs, vector<book> sach, long sosach)
{

    int sl[24];
    int T = 0;
    for (int i = 1; i <= 23; i++)
    {
        sl[i] = 0;
    }
    long k = 1;
    system("cls");

    cout << "++++++++++++++++ SO LUONG SACH SINH VIEN DA MUON +++++++++++++++++" << endl
         << endl;
    cout << "______________________________________________________________" << endl;
    cout << setw(2) << left << "|";
    cout << setw(4) << left << "STT";
    cout << setw(11) << left << "|";
    cout << setw(33) << left << "Ten sach";
    cout << setw(2) << left << "|";
    cout << setw(9) << left << "So luong"
         << "|" << endl;
    cout << "______________________________________________________________" << endl;
    string st;
    for (int i = 1; i <= sohs; i++)
    {
        st = hs[i].borrow;
        string sst;
        for (int i = 0; i < st.length(); i++)
            if (st[i] == ';')
            {
                int num;
                stringstream ss;
                ss << sst;
                ss >> num;
                sl[num] = sl[num] + 1;
                sst = "";
            }
            else
                sst = sst + st[i];
    };
    for (int j = 1; j <= 23; j++)
    {
        if (sl[j] != 0)
        {
            cout << setw(3) << left << "|";
            cout << setw(3) << left << k;
            cout << setw(4) << left << "|";
            cout << setw(40) << sach[j].bookname;
            cout << setw(6) << left << "|";
            cout << setw(5) << left << sl[j] << "|" << endl;
            T = T + sl[j];
            k++;
        }
    }
    cout << "______________________________________________________________" << endl;
    cout << setw(49) << left << "Tong cong	 ";
    cout << setw(15) << left << T << endl;
    cout << "______________________________________________________________" << endl
         << endl;
    cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
}
void ad4(vector<book> sach, long sosach)
{	
	cout<<"Cac sach hien tai cua thu vien va so luong:" << endl;
	cout << "--------------------------------------------------" << endl;
	cout <<"Code|" << "      Ten sach       " << " 	       | So luong" << endl;
	cout << "--------------------------------------------------" << endl;
	for(int i=1; i<sosach;i++)
	{	
		if (i<10) cout << " ";
		cout << " "<< i << " | " ;
		cout <<sach[i].bookname; 
		for (int ii=sach[i].bookname.length();ii<=36;ii++) if (ii==33)cout <<"| ";else cout << " ";
		
		cout <<sach[i].amount << endl;
	}
}
void ad5(vector<book> &sach,long &sosach){
	cout << "Ban muon nhap them bao nhieu quyen sach:	"; int n; cin >> n; //fstream fout;	fout.open("danhsachsach.csv", ios::out | ios::app);
	for (int i=1;i<=n;i++) 
		{
			cout << "Nhap thong tin ma sach thu " << i << ":" << endl;
			string ten;string sl;
			fflush(stdin);
			cout << "	Nhap ten sach: ";getline(cin,ten);	
			cout << "	Nhap so luong: ";cin >> sl;
			stringstream ss2; ss2 << sosach+i;	string masach = ss2.str();	// CHUYEN SO SANG XAU - 2
//			fout << masach << "," << ten << "," << sl << "\n";
			book tam;
			tam.code = masach;tam.bookname = ten; tam.amount = sl;
			sach.push_back(tam);
		};sosach = sosach + n; //cout << sosach;
		
	
}
void admin(vector<hocsinh> &hs,long &sohs,vector<book> &sach,long &sosach){
	system("cls");
	SetColor(0,2);cout << "Dang nhap thanh cong " << endl;SetColor(0,7);
	cout << "1. Tim kiem thong tin sinh vien" << endl;
	cout << "2. Thong ke cac SV dang muon" << endl;
	cout << "3. SL va cac sach dang duoc sinh vien muon" << endl;
	cout << "4. SL va cac sach hien tai cua thu vien" << endl;
	cout << "5. Nhap vao sach moi" << endl;
	//cout << "6. Dang xuat" << endl;
	int ma;cout << "Nhap chon lua cua ban: ";cin >> ma;
	switch (ma){
		
		case 1:system("cls");ad1(hs,sohs,sach,sosach);cout << "Ban co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: "; 
											int lenh;cin >> lenh;if (lenh == 1){system("cls");admin(hs,sohs,sach,sosach);}break; // Hai
		case 2:
        ad2(hs, sohs, sach, sosach);
        cout << "\nBan co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: ";

        cin >> lenh;
        if (lenh == 1)
        {
            system("cls");
            admin(hs, sohs, sach, sosach);
        }
        break; // Sy
    case 3:
        ad3(hs, sohs, sach, sosach);
        cout << "\nBan co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: ";

        cin >> lenh;
        if (lenh == 1)
        {
            system("cls");
            admin(hs, sohs, sach, sosach);
        }
        break; // Sy
		case 4:ad4(sach,sosach);break; // Cong	
		case 5:ad5(sach,sosach);break; // Hai
		//case 6:dangnhap();
	}
}
