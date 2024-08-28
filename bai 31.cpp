#include<iomanip>
#include<iostream>
using namespace std;
class NHANVIEN{
	private:
		string manv;
		string hoten;
		int tuoi;
	public:
		NHANVIEN(){
			manv=hoten="";
			tuoi=0;
		}
	void Nhap();
	void  Xuat();
	void Vehuu();
	int gettuoi();
};


int NHANVIEN::gettuoi(){
	return this->tuoi;
}

void NHANVIEN::Nhap(){
	cout<<"Nhap vao ma nhan vien:";getline(cin,manv);fflush(stdin);
	cout<<"Nhap vao ho va ten:";getline(cin,hoten);fflush(stdin);
	cout<<"Nhap vao tuoi:";cin>>tuoi;fflush(stdin);
}

void NHANVIEN::Xuat(){
	cout<<"Ma nhan vien:"<<manv<<endl;
	cout<<"Ho va ten nhan vien:"<<hoten<<endl;
	cout<<"Tuoi nhan vien:"<<tuoi<<endl;
}


class Canbo:public NHANVIEN {
	private:
		float hsluong;
		float phucap;
		string trinhdo;
	public:
		Canbo(){
			hsluong=phucap=0;
			trinhdo="";
		}
		void Nhap();
		void Xuat();
		void Xuatluong();
		float tinhluong();
		int tinhtuoi ();
		float gethsluong();
};

float Canbo::gethsluong(){
	return this->hsluong;
}


int Canbo::tinhtuoi() {
	if(gettuoi()>=60) {
		return 1;
	}else {
		return 0;
	}
}
float Canbo::tinhluong() {
	if(tinhtuoi()==0) {
		return hsluong*1550+phucap;
	}else {
		return (hsluong*1550+phucap)*0.7;
	}
}

void hienthi(Canbo a[100], int n){
	for(int i=0;i<n;i++){
		if(a[i].tinhtuoi()==0){
			a[i].Xuat();
		}
	}
}

void Canbo::Nhap(){
	NHANVIEN::Nhap();
	cout<<"Nhap he so luong:";cin>>hsluong;fflush(stdin);
	cout<<"Nhap he so phu cap:";cin>>phucap;fflush(stdin);
	cout<<"Trinh do:";getline(cin,trinhdo);fflush(stdin);
}

void Canbo::Xuat(){
	NHANVIEN::Xuat();
	cout<<"He so luong:"<<hsluong<<endl;
	cout<<"He so phu cap:"<<phucap<<endl;
	cout<<"Trinh do:"<<trinhdo<<endl;
	cout<<"Luong:"<<tinhluong()<<endl;
}

void NhapDS(Canbo a[100], int &n){
	cout<<"Nhap vao n can bo can them:";cin>>n;fflush(stdin);
	for(int i=0;i<n;i++){
		cout<<"\nCan bo thu:"<<i+1<<endl;
		a[i].Nhap();
	}
}

void XuatDS(Canbo a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nCan bo thu:"<<i+1<<endl;
		a[i].Xuat();
	}
}

int main(){
	int n;
	NHANVIEN nv;
	Canbo a[100];
	nv.Nhap();
	nv.Xuat();
	NhapDS(a,n);
	cout<<"\nDanh sach cac can bo vua them:"<<endl;
	XuatDS(a,n); 
	cout<<"\nDanh sach cac can bo chua ve huu bao gom luong :"<<endl;
	hienthi(a,n);
	
}

