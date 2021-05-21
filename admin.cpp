#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "data.cpp"
#include <stdlib.h>
#include "book.cpp"
#include <sstream>
#include "goto_draw.cpp"
#include "update.cpp"
#include "inkhung.cpp"
#include <algorithm>
#include "docfile.cpp"
long kk;
book2 *tam;
hs2 *tam2;

using namespace std;
void xoatk(vector<hocsinh> &hs,long &sohs,vector<book> &sach,long &sosach){
	map<string,int> chk;
	for (int i=0;i<=sohs;i++) chk[hs[i].getUserName()] = 1;
	int n;
	//system("cls");
	cout << "Ban muon xoa bao nhieu tai khoan: ";SetColor(0,2);cin >> n;SetColor(0,7);
	while ((n>sohs) || (n<=0)) 
		{cout << "Nhap hop le: " ; cin >> n;
		}
	sohs = sohs - n;
	cout << "Nhap cac username, ngan cach boi enter" << endl;
	while (n>0){
		n--;
		string st;
		cout << (char)16; cin >> st;
		while ((chk[st] == 0) || (st=="admin")) {
			SetColor(0,4);cout << "UserName khong ton tai, nhap lai";SetColor(0,7);cout << (char)16;cin >> st;
		}
		chk[st] = 0;
		update2(hs,sohs,sach,sosach,chk);
		hs.resize(0);
		sach.resize(0);
		docfile(hs,sohs,sach,sosach);
	}
	
	
}

void xuat2(hs2 *hs, long sohs, vector<book> sach, long sosach)
{
    
    cout << "++++++++ DANH SACH CAC SINH VIEN DANG MUON SACH ++++++++ " << endl
         << endl;
    cout << "____________________________________________________" << endl;
    cout << setw(2) << left << "|";
    cout << setw(4) << left << "STT";
    cout << setw(11) << left << "|";
    cout << setw(23) << left << "Ten sinh vien";
    cout << setw(2) << left << "|";
    cout << setw(9) << left << "So luong"
         << "|" << endl;
    cout << "____________________________________________________" << endl;
    int i=0;
    while (i < sohs)
    {
    			i++;
            cout << setw(3) << left << "|";
            cout << setw(3) << left << i; 	
            cout << setw(4) << left << "|";
            cout << setw(30) << hs[i].hoten;
            cout << setw(5) << left << "|";
            cout << setw(6) << left << hs[i].sl << "|" << endl;
    };
    cout << "____________________________________________________" << endl
         << endl;
    cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
}
void xuat3(vector<hocsinh> hs, long sohs, book2 *sach, long sosach)
{
    system("cls");cout << kk;
    cout << "++++++++++++++++ SO LUONG SACH DANG DUOC MUON +++++++++++++++++" << endl
         << endl;
    cout << "______________________________________________________________" << endl;
    cout << setw(2) << left << "|";
    cout << setw(4) << left << "Ma ";
    cout << setw(11) << left << "|";
    cout << setw(33) << left << "Ten sach";
    cout << setw(2) << left << "|";
    cout << setw(9) << left << "So luong"
         << "|" << endl;
    cout << "______________________________________________________________" << endl;
    string st;
    long long T=0;
    for (int j = 1; j <= sosach; j++)
    {
        

            cout << setw(3) << left << "|";
            cout << setw(3) << left << sach[j].code; 
            cout << setw(4) << left << "|";
            cout << setw(40) << sach[j].bookname;
            cout << setw(6) << left << "|";
            cout << setw(5) << left << sach[j].sl << "|" << endl;
            T = T + sach[j].sl;
         //   k++;
        
    }
    cout << "______________________________________________________________" << endl;
    cout << setw(49) << left << "Tong cong	 ";
    cout << setw(15) << left << T << endl;
    cout << "______________________________________________________________" << endl
         << endl;
    cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
}
bool temp1(book2 x, book2 y) 
{
       return x.sl>y.sl; 
};
bool temp2(book2 x, book2 y) 
{
       return x.sl<y.sl; 
};
bool cmp1(hs2 x, hs2 y) 
{
       return x.sl>y.sl; 
};
bool cmp2(hs2 x, hs2 y) 
{
       return x.sl<y.sl; 
};
void xuat4(vector<hocsinh> hs,long sohs,book2 *sach,long sosach)
{	system("cls");
	cout<<"Cac sach hien tai cua thu vien va so luong:" << endl;
	cout << "--------------------------------------------------" << endl;
	cout <<"Code|" << "      Ten sach       " << " 	       | So luong |" << endl;
	cout << "--------------------------------------------------" << endl;
	for(int i=1; i<sosach;i++)
	{//	kk++;
		if (i<10) cout << " ";
		cout << " "<< i << " | " ;
		cout <<sach[i].bookname; 
		for (int ii=sach[i].bookname.length();ii<=36;ii++) if (ii==33)cout <<"| ";else cout << " ";
		
		cout <<sach[i].sl;
		string tt=to_string(sach[i].sl);
		for (int i=1;i<7-tt.length();i++) cout << " ";
		cout << "|" << endl;
	}
}
void ad1(vector<hocsinh> hs,long sohs,vector<book> sach,long sosach){
	long k=1;
	
	string st;
	cout << "Nhap username cua nguoi ma ban muon tra cuu: "; SetColor(0,9);cin >> st;bool chay = false;SetColor(0,7);
	for (int i=1;i<=sohs;i++)
		if (st == hs[i].getUserName()) 
			{	chay = true;
				cout << "Ho va ten: " << hs[i].hoten << endl;
				if (hs[i].borrow == "0;") {SetColor(0,4);cout << " !!! Hien tai hoc sinh nay chua muon sach cua thu vien" << endl;}
				else {
				SetColor(0,2);cout << "Cac sach dang muon: " << endl; SetColor(0,7);
			//	cout << "\nXin Chao " << hs[i].hoten << " , cac sach ban dang muon la: " << endl
					 //<< endl;
				inkhung();
				st = hs[i].borrow;
				string sst;
				for (int i=0;i<st.length();i++) if (st[i] == ';')
													{
														
														int num; 
														stringstream ss;  
														ss << sst;  
														ss >> num; 	// CHUYEN XAU SANG SO - 1
														cout << setw(3) << left << "|";
														cout << setw(3) << left << sach[num].code;
														cout << setw(4) << left << "|";
														cout << setw(40) << sach[num].bookname << "|" << endl;
														k++;
														sst ="";
													}
													else sst = sst + st[i];
				
				}
				break;//kiem duoc thi dung ko kiem nua
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
    for (int i = 1; i <= sohs; i++)
    {
        sl[i] = 0;
    }
    cout << "++++++++ DANH SACH CAC SINH VIEN DANG MUON SACH ++++++++ " << endl
         << endl;
    cout << "____________________________________________________" << endl;
    cout << setw(2) << left << "|";
    cout << setw(4) << left << "STT";
    cout << setw(11) << left << "|";
    cout << setw(23) << left << "Ten sinh vien";
    cout << setw(2) << left << "|";
    cout << setw(9) << left << "So luong"
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
    tam2 = new hs2[sohs+1];
    while (i <= sohs)
    {
        t = hs[i].borrow;
        if (t == "0;") sl[i] = 0;
        
            cout << setw(3) << left << "|";
            cout << setw(3) << left << j; tam2[j].hoten = hs[i].hoten;tam2[j].sl = sl[i];
            cout << setw(4) << left << "|";
            cout << setw(30) << hs[i].hoten;
            cout << setw(5) << left << "|";
            cout << setw(6) << left << sl[i] << "|" << endl;
           
        	j++;
        i++;
    };kk=j;
    cout << "____________________________________________________" << endl
         << endl;
    cout << "\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
}
void ad3(vector<hocsinh> hs, long sohs, vector<book> sach, long sosach)
{
	
    int sl[sosach+1];
    int T = 0;
    for (int i = 1; i <= sosach; i++)
    {
        sl[i] = 0;
    }
    long k = 1;
    system("cls");
    cout << "++++++++++++++++ SO LUONG SACH DANG DUOC MUON +++++++++++++++++" << endl
         << endl;
    cout << "______________________________________________________________" << endl;
    cout << setw(2) << left << "|";
    cout << setw(4) << left << "Ma ";
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
                int num=stoi(sst);
                sl[num] = sl[num] + 1;
                sst = "";
            }
            else
                sst = sst + st[i];
    };kk=0;tam=new book2[sosach+1];
    for (int j = 1; j <= sosach; j++)
    {
        if (sl[j] != 0)
        {
        	kk++;
            cout << setw(3) << left << "|";
            cout << setw(3) << left << sach[j].code; tam[kk].code = sach[j].code;tam[kk].bookname =  sach[j].bookname;tam[kk].sl = sl[j];
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
	cout <<"Code|" << "      Ten sach       " << " 	       | So luong |" << endl;
	cout << "--------------------------------------------------" << endl;
	kk=0;tam=new book2[sosach+1];
	for(int i=1; i<sosach;i++)
	{	kk++;
		if (i<10) cout << " ";
		cout << " "<< i << " | " ;
		cout <<sach[i].bookname; 
		for (int ii=sach[i].bookname.length();ii<=36;ii++) if (ii==33)cout <<"| ";else cout << " ";
		tam[kk].code = sach[i].code;tam[kk].bookname =  sach[i].bookname;tam[kk].sl = stoi(sach[i].amount);
		cout <<sach[i].amount;
		string tt=sach[i].amount;
		for (int i=1;i<7-tt.length();i++) cout << " ";
		cout << "|" << endl;
	}
}
void ad5(vector<hocsinh> &hs,long &sohs,vector<book> &sach,long &sosach){
	cout << "Ban muon nhap them bao nhieu dau sach:	"; int n; cin >> n; //fstream fout;	fout.open("danhsachsach.csv", ios::out | ios::app);
	for (int i=1;i<=n;i++) 
		{
			SetColor(0,2);cout << "Nhap thong tin ma sach thu " << i << ":" << endl;
			string ten;string sl,theloai;
			fflush(stdin);
			SetColor(0,6);
			cout << "  " << (char)16 << "Nhap ten sach: ";getline(cin,ten);fflush(stdin);	
			cout << "  " << (char)16 <<"Nhap the loai: ";getline(cin,theloai);
			cout << "  " << (char)16 <<"Nhap so luong: ";cin >> sl;
			cout << "-------" << endl;
			stringstream ss2; ss2 << sosach+i;	string masach = ss2.str();	// CHUYEN SO SANG XAU - 2
//			fout << masach << "," << ten << "," << sl << "\n";
			book tam;
			tam.code = masach;tam.bookname = ten;tam.category = theloai; tam.amount = sl;
			sach.push_back(tam);
		};sosach = sosach + n; //cout << sosach;
		update(hs,sohs,sach,sosach,0);
		SetColor(0,7);
	
}

void admin(vector<hocsinh> &hs,long &sohs,vector<book> &sach,long &sosach){
	system("cls");
	SetColor(0,2);cout << "Dang nhap thanh cong " << endl;SetColor(0,7);
	cout << "1. Tim kiem thong tin sinh vien" << endl;
	cout << "2. Thong ke cac SV dang muon - Sap xep - Xoa TK" << endl;
	cout << "3. Thong ke sach dang duoc sinh vien muon - Sap xep" << endl;
	cout << "4. Thong ke cac sach hien tai cua thu vien" << endl;
	cout << "5. Nhap them dau sach moi" << endl;
	//cout << "6. Xoa tai khoan nguoi dung" << endl;
	//cout << "6. Xoa dau sach" << endl;
	//cout << "6. Dang xuat" << endl;
	int ma;cout << "Nhap chon lua cua ban: ";cin >> ma;
	switch (ma){
		
		case 1:system("cls");ad1(hs,sohs,sach,sosach);cout << "Ban co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: "; 
											int lenh;cin >> lenh;if (lenh == 1){system("cls");admin(hs,sohs,sach,sosach);}break; // Hai
		case 2:
        ad2(hs, sohs, sach, sosach);
        cout << "\nBan co muon lam gi nua khong" <<endl;
		cout <<"	1. Tro ve man hinh chon " << endl;
		cout <<"	2. Sap xep giam dan theo so luong sach" << endl;
		cout <<"	3. Sap xep tang dan theo so luong sach" << endl;
		cout <<"	4. Xoa tai khoan" << endl;
        cin >> lenh;
       // switch (lenh)
        	if (lenh == 1) {
			
            	system("cls");
            	admin(hs, sohs, sach, sosach);
            	break;}
        	if (lenh == 2 ){
			    
        		system("cls");
        		sort(tam2+1,tam2+sohs+1,cmp1);
        		xuat2(tam2, sohs, sach,sosach);
        		cout << "\nBan co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: ";
		
        		cin >> lenh;
			        if (lenh == 1)
			        {
			            system("cls");
			            admin(hs, sohs, sach, sosach);
			        }
			        break;
        	}
        	if (lenh==3){
			
        		system("cls");
        		sort(tam2+1,tam2+sohs+1,cmp2);
        		xuat2(tam2, sohs, sach,sosach);
        		cout << "\nBan co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: ";
		
        		cin >> lenh;
			        if (lenh == 1)
			        {
			            system("cls");
			            admin(hs, sohs, sach, sosach);
			        }
			        break;
			    }
			if (lenh==4) {
				xoatk(hs,sohs,sach,sosach);
				}
				cout << "\nBan co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: ";
		
        		cin >> lenh;
			        if (lenh == 1)
			        {
			            system("cls");
			            admin(hs, sohs, sach, sosach);
			        }
			        break;
			
    case 3:
        ad3(hs, sohs, sach, sosach);
        cout << "\nBan co muon lam gi nua khong" <<endl;
		cout <<"	1. Tro ve man hinh chon " << endl;
		cout <<"	2. Sap xep giam dan theo so luong sach" << endl;
		cout <<"	3. Sap xep tang dan theo so luong sach" << endl;

        cin >> lenh;
       // switch (lenh)
        	if (lenh == 1) {
			
            	system("cls");
            	admin(hs, sohs, sach, sosach);
            	break;}
        	if (lenh == 2 ){
			    
        		system("cls");
        		sort(tam+1,tam+kk+1,temp1);
        		xuat3(hs, sohs, tam, kk);
        		cout << "\nBan co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: ";
		
        		cin >> lenh;
			        if (lenh == 1)
			        {
			            system("cls");
			            admin(hs, sohs, sach, sosach);
			        }
			        break;
        	}
        	if (lenh==3){
			
        		system("cls");
        		sort(tam+1,tam+kk+1,temp2);
        		xuat3(hs, sohs, tam, kk);
        		cout << "\nBan co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: ";
		
        		cin >> lenh;
			        if (lenh == 1)
			        {
			            system("cls");
			            admin(hs, sohs, sach, sosach);
			        }
			        break;
			    }
		//ketthuc();
		 // Sy
		case 4:ad4(sach,sosach); // Cong  
        cout << "\nBan co muon lam gi nua khong" <<endl;
		cout <<"	1. Tro ve man hinh chon " << endl;
		cout <<"	2. Sap xep giam dan theo so luong sach" << endl;
		cout <<"	3. Sap xep tang dan theo so luong sach" << endl;

        cin >> lenh;
       // switch (lenh)
        	if (lenh == 1) {
			
            	system("cls");
            	admin(hs, sohs, sach, sosach);
            	break;}
        	if (lenh == 2 ){
			    
        		system("cls");
        		sort(tam+1,tam+kk+1,temp1);
        		xuat4(hs, sohs, tam, sosach);
        		cout << "\nBan co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: ";
		
        		cin >> lenh;
			        if (lenh == 1)
			        {
			            system("cls");
			            admin(hs, sohs, sach, sosach);
			        }
			        break;
        	}
        	if (lenh==3){
			
        		system("cls");
        		sort(tam+1,tam+kk+1,temp2);
        		xuat4(hs, sohs, tam, sosach);
        		cout << "\nBan co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: ";
		
        		cin >> lenh;
			        if (lenh == 1)
			        {
			            system("cls");
			            admin(hs, sohs, sach, sosach);
			        }
			        break;
			    }
		case 5:ad5(hs,sohs,sach,sosach);// Hai
		cout << "\nBan co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: ";

        cin >> lenh;
        if (lenh == 1)
        {
            system("cls");
            admin(hs, sohs, sach, sosach);
        }
        break;
	}
}
