#pragma once
#include <iostream>
#include "goto_draw.cpp"
using namespace std;

void trasach(vector<hocsinh> &hs, long &sohs, vector<book> &sach, long &sosach,int h)
		{	
			bool kt[1000]={false};
			string st = hs[h].borrow;
			string s;
			int muon;
			for (int i=0;i<=st.length();i++) if (st[i] == ';'){ muon++;kt[stoi(s)] = true;s="";}else s = s + st[i];
			int n;cout << "Nhap so sach ban tra: ";cin >> n;
			while (n>muon) {
				cout << "Ban chi duoc phep tra it hon " << muon << " quyen sach ban da muon!" << endl;
				cout << "Nhap lai so sach ban tra: ";cin >> n;
			}
			cout<<"Nhap ma sach can tra, ngan cach boi enter: "<< endl;
			//cout << (char)19<< " Luu y neu ban nhap ma sach ma ban khong muon thi yeu cau do se khong duoc thuc hien!!!" << endl;
			int k=0;
			while (n>0){
			n--;k++;
			int ms;
			cout << (char)16 << (char)16 << "Nhap ma thu " << k << ": ";cin>>ms;
			while (kt[ms] == false) {cout <<"Ban chua muon sach nay, nhap lai:";cin>>ms; }
			cout<<"Ban dang tra quyen: "<<sach[ms].bookname<<endl; 
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
			cout << (char)19<< " Yeu cau cua ban da duoc thuc hien" << endl;
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
	unsigned int ms1[5];
    int lc, lc1, lc2;
	int dem=0;
	string ngm, ngt;
	cout<<"nhap lua chon tiep theo:"<<endl;
	cout<<"1. muon sach"<<endl;
	cout<<"2. thoat"<<endl;
	cin>>lc1;
	switch (lc1)
	{
		case 1:
		{
		
			cout<<"Nhap so sach can muon (toi da 5 quyen): "<<endl;
			int n;
			cin>>n;
			cout<<"Nhap ma sach can muon: ";
			for (int i = 0; i < n; i++)
			{
				cin>>ms1[i];

			}
			for (int kk=0; kk<hs[h].borrow.length(); kk++)
			{
				int num4 ;
			
				std::stringstream sss;
				sss << hs[h].borrow[kk];
				sss >> num4;
				for (int jk=0; jk<n; jk++)
				{
					if (num4 == ms1[jk])
					{
						dem++;
					}
				}

			}
			if(dem >=1 ) 
			{
				int ms2[5];
				cout<<"Ban da nhap trung sach da muon, ban khong duoc muon trung!"<<endl;
				cout<<"Vui long nhap lai ma so sach can muon: "<<endl;
				for (int lk=0; lk<n; lk++)
				{
					cin>>ms2[lk];
				}
				for(int kl=0;kl<n; kl++)
				{
					ms1[kl]=ms2[kl];
				}
			}
			cout<<"Ban dang muon quyen: "<<endl;
			for(int iij=0; iij<n;iij++)
			{
				int num; 
				std::stringstream ss;
				ss << sach[ms1[iij]].amount;
				ss>> num;
				if (num ==0) {
				cout<<"Loai sach nay da duoc muon het!!!"<<endl;
				cout<<"Vui long chon quyen khac!!!";}
				else {cout<<sach[ms1[iij]].bookname<<endl; }
			}
			
			
			cout<<"Nhap ngay muon: "<<endl;
			cin>>ngm;
			cout<<"Nhap ngay tra: "<<endl;
			cin>>ngt;
			cout<<"Moi lua chon:"<<endl;
			cout<<"1. in phieu muon"<<endl;
			cout<<"2. khong in phieu muon"<<endl;
    		cin>>lc2;
    		// update muon: 
    		
			for (int ji=0; ji<n; ji++)
			{
				stringstream ss2;
				ss2 << ms1[ji];
    			if (hs[h].borrow == "0;") hs[h].borrow = "";
    			hs[h].borrow = hs[h].borrow + ss2.str() +";";
    			int numm; stringstream ssa;  ssa << sach[ms1[ji]].amount;  ssa >> numm; numm--;
    			stringstream sss; sss << numm;	sach[ms1[ji]].amount = sss.str(); 
			}
    	//	cout << "=     " << sach[ms].amount << "       =      ";
    		//
    		cout <<"Ma sach muon: "<< hs[h].borrow<<endl;;
			if (lc2==1) 
			{
				ofstream phieumuon("phieumuon.txt");
				phieumuon<<"Phieu muon sach"<<endl;
				phieumuon<<"============================="<<endl;
				phieumuon<<"Ho ten: " << hs[h].hoten << endl; 
				phieumuon<<"sach ban muon: "<<endl;
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
				phieumuon<<"Ngay muon: "<<ngm<<endl;
				phieumuon<<"Ngay tra: "<<ngt<<endl;
				phieumuon<<"                             "<<endl;
				phieumuon<<"                             "<<endl;
    			phieumuon<<"============================="<<endl;
				phieumuon<<"Nguoi muon ky va ghi ro ho ten"<<endl;
			}
			else if (lc2==2) 
			{
				cout<<"Ban da chon khong in phieu muon"<<endl;
				cout<<"Hoan tat muon sach"<<endl;
			}
			int lenh1;
				cout << "\nBan co muon lam gi nua khong, nhap 1 de tro ve man hinh chon, 2 de ket thuc: ";
				cin >> lenh1;
				if (lenh1 == 1)
				{
					system("cls");
					us1(hs, sohs, sach, sosach, h);
				}
				break; 
			
			break;
		}
	case 2:
		{
			
			exit(0);
		}
	
	default:
		cout<<"Lua chon sai!!!"<<endl;
		cout<<"Vui long chon lai"<<endl;
		break;
	}

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
				cout << "___________________________________________________" << endl;
				cout << setw(2) << left << "|";
				cout << setw(4) << left << "Ma ";
				cout << setw(11) << left << "|";
				cout << setw(33) << left << "Ten sach"
					 << "|" << endl;
				cout << "___________________________________________________" << endl;
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
					outfile << "\nXin Chao " << hs[i].hoten << " , cac sach ban dang muon la: " << endl
							<< endl;
					outfile << "___________________________________________________" << endl;
					outfile << setw(2) << left << "|";
					outfile << setw(4) << left << "Ma ";
					outfile << setw(11) << left << "|";
					outfile << setw(33) << left << "Ten sach"
							<< "|" << endl;
					outfile << "___________________________________________________" << endl;
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
					outfile << "___________________________________________________" << endl;
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
	vector<book> tam;tam.push_back(sach[0]);
	string tensach;
	system("cls");
	cout << "Ban muon tim kiem sach gi?" << endl;
	cout << "  -> Nhap sach ban muon tim o day: "; fflush(stdin);getline(cin,tensach); int n=tensach.length();
		for (int i=1;i<=sosach;i++) 
			 	if (convert(sach[i].bookname).find(tensach) < sach[i].bookname.length()) tam.push_back(sach[i]);
//	cout << tam.size();
	long g = tam.size()-1;
	us1(hs,sohs,tam,g,h);// Cai nay chi de trinh bay cac sach, con muon quyen nao thi dung ham muon sau; neu kieu la us1 thi se auto goi ham muon, neu us3 us4 thi tu goi
	// muon(hs,sohs,sach,sosach,h);
}
void user(vector<hocsinh> &hs,long &sohs,vector<book> &sach,long &sosach,int h){ // dang dang nhap hoc sinh h
	system("cls");
	SetColor(0,2);cout << "Dang nhap thanh cong " << endl;SetColor(0,7);
	cout << " Chao ban: " << hs[h].hoten << " " << (char)1 << endl; 
	cout << "1. Xem cac sach thu vien co - Muon sach" << endl;
	cout << "2. Kiem tra sach ban dang muon - Tra sach" << endl;
	cout <<	"3. Tim kiem sach - Muon sach " << endl;
	cout << "4. Loc sach theo the loai - Muon sach " << endl;
	cout << "6. Doi mat khau: " << endl;
	int ma;cout << "Nhap chon lua cua ban: ";cin >> ma;

	switch (ma){
		
		case 1:us1(hs,sohs,sach,sosach,h);break; // Cong
		case 2:
		us2(hs, sohs, sach, sosach,h);
		int lenh;
		cout << "			-------------------";
		cout << "\nBan co muon lam gi nua khong? Nhap 1 de tro ve man hinh chon, ky tu bat ki de ket thuc: ";
		cin >> lenh;
		if (lenh == 1)
		{
			system("cls");
			user(hs, sohs, sach, sosach, h);
		}
		break; // Sy
		case 3:us3(hs,sohs,sach,sosach,h);break;
		us2(hs, sohs, sach, sosach,h);
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
	};
	}

