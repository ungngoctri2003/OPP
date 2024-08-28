#include<iomanip>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<string.h>
using namespace std;
class DATE{
	private:
		int ngay,thang,nam;
	public:
		DATE(){
			ngay,thang,nam=0;
		}
	void Nhap();
	void Xuat();
};

void DATE::Nhap(){
	cout<<"Nhap ngay:";cin>>ngay;
	cout<<"Nhap thang:";cin>>thang;
	cout<<"Nhap nam:";cin>>nam;
}

void DATE::Xuat(){
	cout<<""<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}

class CANBO:public DATE{
	private:
		string macb,tencb;
		float luong;
	public:
		float static tienphucvu;
	CANBO(){
			macb,tencb="";
		luong=0;
	}
	void Nhap();
	void Xuat();
	float tinhluong();
	string Gettencb();
};

float CANBO::tienphucvu=2100;

string CANBO::Gettencb(){
	return this->tencb;
}
	
void CANBO::Nhap(){
	DATE::Nhap();
	cout<<"Nhap ma can bo:";fflush(stdin);getline(cin,macb);
	cout<<"Nhap ten can bo:";fflush(stdin);getline(cin,tencb);
	cout<<"Nhap luong co ban:";cin>>luong;
}

void CANBO::Xuat(){
	DATE::Xuat();
	cout<<"Ma can bo:"<<macb<<endl;
	cout<<"Ten can bo:"<<tencb<<endl;
	cout<<"Luong co ban:"<<luong<<endl;
	cout<<"Luong duoc nhan:"<<tinhluong()<<endl;
}

float CANBO::tinhluong(){
	return luong+tienphucvu;
}

void NhapDS(CANBO a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nCan bo thu:"<<i+1<<endl;
		a[i].Nhap();
	}
}

void XuatDS(CANBO a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nCan bo thu:"<<i+1<<endl;
		a[i].Xuat();
	}
}

void min(CANBO a[100], int n){
	float Min=a[0].tinhluong();
	for(int i=0;i<n;i++){
		if(Min>a[i].tinhluong()){
			Min=a[i].tinhluong();
		}
	}
	for(int i=0;i<n;i++){
		if(Min==a[i].tinhluong()){
			cout<<"Ten can bo:"<<a[i].Gettencb();
		}
	}
}

int main(){
	DATE dt;
	dt.Nhap();
	dt.Xuat();
	int n;
	CANBO a[100];
	cout<<"Nhap vao so can bo muon them:";cin>>n;
	NhapDS(a,n);
	cout<<"Thong tin can bo vua them:"<<endl;
	XuatDS(a,n);
	cout<<"\nThong tin cac can bo co luong thap nhat:"<<endl;
	min(a,n);
	
}

