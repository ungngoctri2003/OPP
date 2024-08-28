#include<iomanip>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<string.h>

using namespace std;

class MONHOC{
	private:
		int mamh;
		string tenmh;
	public:
		MONHOC(){
			mamh=0;
			tenmh="";
		}
		void Nhap();
		void Xuat();
};

void MONHOC::Nhap(){
	cout<<"Nhap ma mon hoc:";cin>>mamh;
	cout<<"Nhap ten mon hoc:";fflush(stdin);getline(cin,tenmh);
}

void MONHOC::Xuat(){
	cout<<"Ma mon hoc:"<<mamh<<endl;;
	cout<<"Ten mon hoc:"<<tenmh<<endl;
}

class GIANGDAY :public MONHOC{
	private:
		int magv;
		int malop;
		int sotin;
	public:
		int static sotiet;
		GIANGDAY(){
			magv=malop=sotin=0;
		}
		void Nhap();
		void Xuat();
		int Sotiet();
		int GetTin();
		int GetMaGv();
		
};
int GIANGDAY::sotiet=20;

int GIANGDAY::GetMaGv(){
	return this->magv;
}
void GIANGDAY::Nhap(){
	MONHOC::Nhap();
	cout<<"Nhap ma giang vien:";cin>>magv;
	cout<<"Nhap ma lop:";cin>>malop;
	cout<<"Nhap so tin:";cin>>sotin;
}

void GIANGDAY::Xuat(){
	MONHOC::Xuat();
	cout<<"Ma giang vien:"<<magv<<endl;
	cout<<"Ma lop:"<<malop<<endl;
	cout<<"So tin:"<<sotin<<endl;
}
int GIANGDAY::GetTin(){
	return this->sotin;
}
int GIANGDAY::Sotiet(){
	int soTiet;
	return soTiet=sotin*15-sotiet;
}

void NhapDS(GIANGDAY a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nGiang vien thu:"<<i+1<<endl;
		a[i].Nhap();
	}
}

void XuatDS(GIANGDAY a[100], int n ){
	for(int i=0;i<n;i++){
		cout<<"\nGiang vien thu:"<<i+1<<endl;
		a[i].Xuat();
	}
}

void hienthi(GIANGDAY a[100], int n){
	for(int i=0;i<n;i++){
		if(a[i].GetTin() ==3){
			a[i].Xuat();
		}
	}
}

void hienthiMa(GIANGDAY a[100], int n){
	int min;
	min=a[0].Sotiet();
	for(int i=0;i<n;i++){
		if(min>a[i].Sotiet()){
			min=a[i].Sotiet();
		}
	}
	for(int i=0;i<n;i++){
		if(a[i].Sotiet()==min){
			cout<<"Ma giang vien:"<<a[i].GetMaGv()<<endl;
		}
	}
}

int main(){
	int n;
	MONHOC mh;
	mh.Nhap();
	mh.Xuat();
	GIANGDAY a[100];
	cout<<"Nhap vao so doi tuong can them:";cin>>n;
	NhapDS(a,n);
	cout<<"\nDanh sach cac doi tuong:"<<endl;
	XuatDS(a,n);
	cout<<"\nDanh sach cac mon hoc co 3 tin:"<<endl;
	hienthi(a,n);
	cout<<"\nCac ma giang vien co so tiet con lai nho nhat:"<<endl;
	hienthiMa(a,n);
	
}

