#pragma once
#include <iostream>
#include "goto_draw.cpp"
#include <ctime>
#include "update.cpp"
#include "inkhung.cpp"

using namespace std;
string get_time(){
	time_t now = time(0);
 	tm *ltm = localtime(&now);
 	return to_string(ltm->tm_hour) + ":" + to_string(ltm->tm_min) + ":" + to_string(ltm->tm_sec);
}
string get_day(){
	time_t now = time(0);
 	tm *ltm = localtime(&now);
	return to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);
}
void intime(){
	cout << " Thoi gian: "<< get_time() << endl;
	cout << " Ngay: "<< get_day() << endl;
}
void thanhcong(){
	cout << "------------------" << endl;
	SetColor(0,9);	
	cout << " Yeu cau cua ban da duoc thuc hien" << endl;
	intime();
	SetColor(0,7);
	cout << "------------------" << endl;
}
void trasach(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach,int h)
		{	
			bool *kt = new bool[sosach+1];
			for (int i=1;i<=sosach;i++) kt[i]=false;
			string st = hs[h].borrow;
			string s;
			int muon;
			for (int i=0;i<=st.length();i++) if (st[i] == ';'){ muon++;kt[stoi(s)] = true;s="";}else s = s + st[i];
			int n;cout << "Nhap so sach ban tra: ";cin >> n;
			while (n>muon) {
				cout << "Ban chi duoc phep tra it hon " << muon << " quyen sach ban da muon!" << endl;
				cout << (char)16 << "Nhap lai so sach ban tra: ";cin >> n;
			}
			if (n>0){
			vector<int> ms1;
			cout<<"Nhap ma sach can tra, ngan cach boi enter: "<< endl;
			//cout << (char)19<< " Luu y neu ban nhap ma sach ma ban khong muon thi yeu cau do se khong duoc thuc hien!!!" << endl;
			int k=0;
			int nn=n;
			while (n>0){
			n--;k++;
			int ms;
			cout << (char)16 << (char)16 << "Nhap ma thu " << k << ": ";cin>>ms;
			while (kt[ms] == false) {cout <<"Ban chua muon sach nay ";cout << "Cac sach ma sach ban dang muon: "; cout << hs[h].borrow << endl;
			cout <<"Nhap lai:";cin>>ms; }
			ms1.push_back(ms);kt[ms]=false;
			SetColor(0,2);cout<<"Ban dang tra quyen: "<<sach[ms].bookname<<endl;SetColor(0,7);
    		// update tra: 
    		stringstream ss2; ss2 << ms;	string sms = ss2.str();
    		string st = hs[h].borrow;
				string sst;
				for (int i=0;i<st.length();i++) if (st[i] == ';')
													{
														if (sms == sst) 
															{
															st.erase(st.begin()+i-sst.length(),st.begin()+i+1);
															break;
															}
														sst =""; 
													}else sst = sst + st[i];
    		 hs[h].borrow = st;if (hs[h].borrow == "") hs[h].borrow = "0;";
    		int numm; stringstream ssa;  ssa << sach[ms].amount;  ssa >> numm; numm++;
    		stringstream sss; sss << numm;	sach[ms].amount = sss.str();
			}
			n=nn;
			thanhcong();
			
			cout<<"Ban co muon in phieu khong?"<<endl;
			cout<<"	1. In phieu muon"<<endl;
			cout<<"	2. Khong in"<<endl;
    		int lc2;cin>> lc2;
    		
    	//	cout <<"Ma sach muon: "<< hs[h].borrow<<endl;;
			if (lc2==1) 
			{
				ofstream phieutra("phieutra.txt");
				phieutra<<"Phieu tra sach"<<endl;
				phieutra<<"============================="<<endl;
				phieutra<<"Ho ten: " << hs[h].hoten << endl; 
			
				phieutra<<"Ma so sach: "<<"   ";
				
				phieutra<<"Ten sach: "<<endl;
				for(int j=0; j<n; j++)
				{
					phieutra<<sach[ms1[j]].code;
					for(int l=sach[ms1[j]].code.length(); l<15; l++)
					{
						phieutra<<" ";
					}
					phieutra<<sach[ms1[j]].bookname<<endl;

				}
				phieutra<<"Ngay tra: "<<get_day()<<endl;

				phieutra<<"                             "<<endl;
    			phieutra<<"============================="<<endl;
				phieutra<<"Nguoi muon ky va ghi ro ho ten"<<endl;
			}
			else if (lc2==2) 
			{
				cout<<"Ban da chon khong in phieu muon"<<endl;
				cout<<"Hoan tat tra sach"<<endl;
			}
			update(hs,sohs,sach,sosach,h);
			}
		}
void muon(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach,int h)
{
			cout<<"Nhap so sach can muon (toi da 5 quyen), ngan cach boi enter: "<<endl;
			int n;
			cin>>n;
			while ((n>5)) 
				{
					SetColor(0,4);cout << "Ban can chi duoc muon 1..5 cuon" << endl;SetColor(0,7);
					cout << "Nhap n: ";cin>>n;
				}
			if (n>0){
			
			int nn=n;
			bool *kt = new bool[sosach+1];
			for (int i=1;i<=sosach;i++) kt[i]=false;
			string st = hs[h].borrow;
			string s;
			vector<int> ms1;
			for (int i=0;i<=st.length();i++) if (st[i] == ';'){ kt[stoi(s)] = true;s="";}else s = s + st[i];
			cout << "Nhap ma sach ban muon muon: " << endl;
			SetColor(0,4);	cout << "Ban khong duoc muon 1 sach nhieu cuon hoac muon sach co sl = 0 " << endl;SetColor(0,7);
			while (n>0)
				{
					n--;
					int ms;					
					
					cout <<" "<< (char)16 << (char)16 ;cin >> ms;
					while ( ms<=0 || (kt[ms]==true) || (sach[ms].amount == "0") || ms>sosach )
						{
							SetColor(0,4);	cout << "Ban can nhap dung theo yeu cau, nhap lai ma: " << endl;
							cout << "Cac sach ma sach ban dang muon: "; cout << hs[h].borrow << endl;SetColor(0,7);
							cout <<" "<< (char)16 << (char)16 ;cin >> ms;
						}
					
					//update
					SetColor(0,2);cout << "Ban dang muon quyen " << sach[ms].bookname << endl;SetColor(0,7);
					kt[ms] = true;
					ms1.push_back(ms);
	    			if (hs[h].borrow == "0;") hs[h].borrow = "";
	    			hs[h].borrow = hs[h].borrow + to_string(ms) +";";
	    			int t = stoi(sach[ms].amount)-1;
	    			sach[ms].amount = to_string(t);
				}
			n=nn;
		//	cout << ms1[1] << endl;
			string ngm, ngt;
			int lc2;
			thanhcong();
			cout<<"Ban co muon in phieu khong?"<<endl;
			cout<<"	1. In phieu muon"<<endl;
			cout<<"	2. Khong in"<<endl;
    		cin>>lc2;
    		
    	//	cout <<"Ma sach muon: "<< hs[h].borrow<<endl;;
			if (lc2==1) 
			{
				ofstream phieumuon("phieumuon.txt");
				phieumuon<<"Phieu muon sach"<<endl;
				phieumuon<<"============================="<<endl;
				phieumuon<<"Ho ten: " << hs[h].hoten << endl; 
			
				phieumuon<<"Ma so sach: "<<"   ";
				
				phieumuon<<"Ten sach: "<<endl;
				for(int j=0; j<n; j++)
				{
					phieumuon<<sach[ms1[j]].code;
					for(int l=sach[ms1[j]].code.length(); l<15; l++)
					{
						phieumuon<<" ";
					}
					phieumuon<<sach[ms1[j]].bookname<<endl;

				}
				phieumuon<<"Ngay muon: "<<get_day()<<endl;

				phieumuon<<"                             "<<endl;
    			phieumuon<<"============================="<<endl;
				phieumuon<<"Nguoi muon ky va ghi ro ho ten"<<endl;
			}
			else if (lc2==2) 
			{
				cout<<"Ban da chon khong in phieu muon"<<endl;
				cout<<"Hoan tat muon sach"<<endl;
			}
			update(hs,sohs,sach,sosach,h);
			}
}
void us1(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach,int h) 
{
	cout<<"Sau day la cac sach theo tuy chon cua ban:" << endl;
	cout << "--------------------------------------------------" << endl;
	cout <<"Code|" << "      Ten sach       " << " 	       | So luong" << endl;
	cout << "--------------------------------------------------" << endl;
	for(int i=1; i<=sosach;i++)
	{	
		if (stoi(sach[i].code,0)<10) cout << " ";
		cout << " "<< sach[i].code << " | " ;
		cout <<sach[i].bookname; 
		for (int ii=sach[i].bookname.length();ii<=37;ii++) if (ii==33)cout <<"| ";else cout << " ";
		
		cout <<sach[i].amount << endl;

	}
	cout << "--------------------------------------------------" << endl;
	


}
void us2(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long sosach,int h)
{
	long k = 1;
	system("cls");
	string st, t;
	int c;
	for (int i = 1; i <= sohs; i++)
	{
		st = hs[h].getUserName();
		if (st == hs[i].getUserName())
		{
			t = hs[i].borrow;
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
			if (t == "0;")
			{
				cout << "\nXin Chao " << hs[i].hoten << " , ban chua muon quyen sach nao!" << endl;
			}
			else
			{
				cout << "\nXin Chao " << hs[i].hoten << " , cac sach ban dang muon la: " << endl
					 << endl;
				inkhung();
				st = hs[i].borrow;
				string sst;
				for (int i = 0; i < st.length(); i++)
				{
					if (st[i] == ';')
					{
						int num;
						stringstream ss;
						ss << sst;
						ss >> num;
						cout << setw(3) << left << "|";
						cout << setw(3) << left << sach[num].code;
						cout << setw(4) << left << "|";
						cout << setw(40) << sach[num].bookname << "|" << endl;
						k++;
						sst = "";
					}
					else
						sst = sst + st[i];
				}
				
				cout << "___________________________________________________" << endl;
				cout << " Ban co the in ra danh sach nay hoac tra sach: " << endl;
				cout << "1. In danh sach" << endl;
				cout << "2. Tra sach" << endl;
				cout << "3. Thoat, nhan phim bat ky" << endl;
				cout << "Lua chon cua ban: ";
				cin >> c;
				if (c == 1)
				{
					ofstream outfile;
					outfile.open("output.txt");
					outfile << "Xin Chao " << hs[i].hoten << " , cac sach ban dang muon la: " << endl
							<< endl;
					outfile << "---------------------------------------------------" << endl;
					outfile << setw(2) << left << "|";
					outfile << setw(4) << left << "Ma ";
					outfile << setw(11) << left << "|";
					outfile << setw(33) << left << "Ten sach"
							<< "|" << endl;
					outfile << "---------------------------------------------------" << endl;
					st = hs[i].borrow;
					string sst;
					for (int i = 0; i < st.length(); i++)
					{
						if (st[i] == ';')
						{
							int num;
							stringstream ss;
							ss << sst;
							ss >> num;
							outfile << setw(3) << left << "|";
							outfile << setw(3) << left << k;
							outfile << setw(4) << left << "|";
							outfile << setw(40) << sach[num].bookname << "|" << endl;
							k++;
							sst = "";
						}
						else
							sst = sst + st[i];
					}
					outfile << "---------------------------------------------------" << endl;
					thanhcong();
				    break;
				}
				if (c==2) trasach(hs,sohs,sach,sosach,h);
			}
		
		}
	}
}
string convert(string s){
	for (int i=0;i<=s.length();i++) s[i] = tolower(s[i]);
	return s;
}
void us3(vector<hocsinh> &hs,long &sohs,vector<book> &sach,long &sosach,int h){
	long g=0;
	system("cls");
	vector<book> tam;tam.push_back(sach[0]);
	while (g==0){
	string tensach;
	cout << " Ban muon tim kiem sach gi?" << endl;
	cout << "  -> Nhap sach ban muon tim o day: "; fflush(stdin);getline(cin,tensach); int n=tensach.length();
		for (int i=1;i<=sosach;i++) 
			 	if (convert(sach[i].bookname).find(tensach) < sach[i].bookname.length()) tam.push_back(sach[i]);
//	cout << tam.size();
	g = tam.size()-1;if (g==0) {system("cls");SetColor(0,4);cout << "Khong co sach thoa man"<< endl;SetColor(0,7);}
	}
	us1(hs,sohs,tam,g,h);// Cai nay chi de trinh bay cac sach, con muon quyen nao thi dung ham muon sau; neu kieu la us1 thi se auto goi ham muon, neu us3 us4 thi tu goi
	muon(hs,sohs,sach,sosach,h);
}
void us4(vector<hocsinh> &hs,long &sohs,vector<book> &sach,long &sosach,int h){
	vector<book> tam;
	SetColor(0,2);
	cout << "Hien tai thu vien co cac the loai sau:" << endl;
	map<string,int> kt;
	string ngc[1000];
	//for (int i=1;i<=sosach;i++) kt[sach[i].category] = 1;
	SetColor(0,3);int k=0;
	for (int i=1;i<=sosach;i++) kt[sach[i].category]=1;
	for (auto x:kt)
	{	k++;
		cout <<"  " <<k<<". " << x.first << endl; //<< " " << x.second; 
		ngc[k] = x.first;
	}
	SetColor(0,7);
	cout << "Ban muon loc theo the loai nao?" << endl; cout << (char) 16 << "Nhap so: "; int so;cin >> so;
	while ((so<0) || (so>k)) 
		{
			cout << "Ban nhap khong hop le, nhap lai: ";cin >> so;
		}
	tam.push_back(sach[0]);
	for (int i=1;i<=sosach;i++) if (sach[i].category == ngc[so]) tam.push_back(sach[i]);
	long sotam =tam.size()-1;
	us1(hs,sohs,tam,sotam,h);
	muon(hs,sohs,sach,sosach,h);
}
void us5(vector<hocsinh> &hs,long &sohs,vector<book> &sach,long &sosach,int h){
	string mk,lmk;
	system("cls");SetColor(0,12);
	cout << " DOI MAT KHAU" << endl;SetColor(0,7);
 	cout << "Nhap mat khau moi: " ;cin >> mk;
 	while (mk == hs[h].getPassword()) 
 		{
			system("cls");
			SetColor(0,4);
			cout << (char)19 << "Ban da nhap trung mat khau cu" << endl;SetColor(0,7);
			cout << "Nhap mat khau moi: " ;cin >> mk;
		//	cout << "Nhap lai mat khau moi: ";cin >> lmk;
		}
	cout << "Nhap lai mat khau moi: ";cin >> lmk;
	while (mk!=lmk) 
		{
			system("cls");
			SetColor(0,4);
			cout << (char)19 << "Mat khau khong trung khop" << endl;SetColor(0,7);
			cout << "Nhap mat khau moi: " ;cin >> mk;
			cout << "Nhap lai mat khau moi: ";cin >> lmk;
		}
	hs[h].setPassword(mk);
	update(hs,sohs,sach,sosach,h);
}
void user(vector<hocsinh> &hs,long &sohs,vector<book> &sach,long &sosach,int h){ // dang dang nhap hoc sinh h
	system("cls");
	SetColor(0,2);cout << "Dang nhap thanh cong " << endl;SetColor(0,7);
	cout << " Chao ban: " << hs[h].hoten << " " << (char)1 << endl; 
	cout << "1. Xem cac sach thu vien co - Muon sach" << endl;
	cout << "2. Kiem tra sach ban dang muon - Tra sach" << endl;
	cout <<	"3. Tim kiem sach - Muon sach " << endl;
	cout << "4. Loc sach theo the loai - Muon sach " << endl;
	cout << "5. Doi mat khau: " << endl;
	
	int ma;cout << "Nhap chon lua cua ban: ";cin >> ma;

	switch (ma){
		
		case 1:us1(hs,sohs,sach,sosach,h);muon(hs,sohs,sach,sosach,h); // Cong
		int lenh;
		cout << "			-------------------";
		cout << "\nBan co muon lam gi nua khong? Nhap 1 de tro ve man hinh chon, ky tu bat ki de ket thuc: ";
		cin >> lenh;
		if (lenh == 1)
		{
			system("cls");
			user(hs, sohs, sach, sosach, h);
		}
		break;
		case 2:
		us2(hs, sohs, sach, sosach,h);
		cout << "			-------------------";
		cout << "\nBan co muon lam gi nua khong? Nhap 1 de tro ve man hinh chon, ky tu bat ki de ket thuc: ";
		cin >> lenh;
		if (lenh == 1)
		{
			system("cls");
			user(hs, sohs, sach, sosach, h);
		}
		break; // Sy
		case 3:us3(hs,sohs,sach,sosach,h);
		//us2(hs, sohs, sach, sosach,h);
		//int lenh;
		cout << "			-------------------";
		cout << "\nBan co muon lam gi nua khong? Nhap 1 de tro ve man hinh chon, ky tu bat ki de ket thuc: ";
		cin >> lenh;
		if (lenh == 1)
		{
			system("cls");
			user(hs, sohs, sach, sosach, h);
		}
		break;
		case 4: us4(hs,sohs,sach,sosach,h);
		cout << "		-------------------";
		cout << "\nBan co muon lam gi nua khong? Nhap 1 de tro ve man hinh chon, ky tu bat ki de ket thuc: ";
		cin >> lenh;
		if (lenh == 1)
		{
			system("cls");
			user(hs, sohs, sach, sosach, h);
		}
		break;
		case 5: us5(hs,sohs,sach,sosach,h);
		SetColor(0,2);cout << "Ban da doi mat khau thanh cong" << endl;SetColor(0,7);
		cout << "		-------------------";
		cout << "\nBan co muon lam gi nua khong? Nhap 1 de tro ve man hinh chon, ky tu bat ki de ket thuc: ";
		cin >> lenh;
		if (lenh == 1)
		{
			system("cls");
			user(hs, sohs, sach, sosach, h);
		}
		break;
		
	};
	}

