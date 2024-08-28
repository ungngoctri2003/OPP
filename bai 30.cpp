#include<iomanip>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<string.h>
using namespace std;
class MONHOC{
	private:
		string mamh,tenmh;
		float diemtb;
		int sotc;
	public:
		MONHOC(){
			mamh=tenmh="";
			diemtb=sotc=0;
			
		}
		~MONHOC(){
			mamh=tenmh="";
			diemtb=sotc=0;
		}
		int Getsotc();
		void Nhap();
		void Xuat();
		float Getdiemtb();
	}; 
	
float MONHOC::Getdiemtb(){
	return this->diemtb;
}
int  MONHOC::Getsotc(){
	return this->sotc;
}


void MONHOC::Nhap(){
	cout<<"Nhap vao ma mon hoc:";fflush(stdin);getline(cin,mamh);
	cout<<"Nhap ten mon hoc:";fflush(stdin);getline(cin,tenmh);
	cout<<"Nhap diem trung binh:";cin>>diemtb;
	cout<<"Nhap so tin chi:";cin>>sotc;
}

void MONHOC::Xuat(){
	cout<<"Ma mon hoc:"<<mamh<<endl;
	cout<<"Ten mon hoc:"<<tenmh<<endl;
	cout<<"Diem trung binh:"<<diemtb<<endl;
	cout<<"So tin chi:"<<sotc<<endl;
}

class SINHVIEN:public MONHOC{
	private:
		string masv,tensv;
		int somh;
		MONHOC arr[100];
	public:
		SINHVIEN(){
			masv=tensv="";
			somh=0;
			MONHOC arr[100];
		}
	void Nhap();
	void Xuat();
	float diemtongket();
};		

void SINHVIEN::Nhap(){
	cout<<"Nhap vao ma sinh vien:";fflush(stdin);getline(cin,masv);
	cout<<"Nhap ten sinh vien:";fflush(stdin);getline(cin,tensv);
	cout<<"Nhap so mon hoc:";cin>>somh;
	for(int i=0;i<somh;i++){
		arr[i].MONHOC::Nhap();
	}
}

void SINHVIEN::Xuat(){
	cout<<"Ma sinh vien:"<<masv<<endl;
	cout<<"Ten sinh vien:"<<tensv<<endl;
	cout<<"So mon hoc:"<<somh<<endl;
	cout<<"Diem tong ket:"<<diemtongket()<<endl;
		for(int i=0;i<somh;i++){
		arr[i].MONHOC::Xuat();
	}
}

float SINHVIEN::diemtongket(){
	float diemtk=0;
	float tongdiem=0;
	int tongtc=0;
	for(int i=0;i<somh;i++){
		tongtc=tongtc+arr[i].Getsotc();
	}
	for(int i=0;i<somh;i++){
		tongdiem=tongdiem+arr[i].Getdiemtb()*arr[i].Getsotc();
	}
	return tongdiem/tongtc;
}

void NhapDS(SINHVIEN a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nSinh vien thu:"<<i+1<<endl;
		a[i].Nhap();
	}
}

void XuatDS(SINHVIEN a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nSinh vien thu:"<<i+1<<endl;
		a[i].Xuat();
	}
}

void hienthi(SINHVIEN a[100], int n){
	for(int i=0;i<n;i++){
		if(a[i].diemtongket()>=8.5){
			a[i].Xuat();
		}
	}
}
int main(){
	MONHOC mh;
	mh.Nhap();
	mh.Xuat();
	SINHVIEN a[100];
	int n;
	cout<<"\nNhap so sinh vien them:";cin>>n;
	NhapDS(a,n);
	cout<<"\nDanh sach cac sinh vien da them:"<<endl;
	XuatDS(a,n);
	cout<<"\nSinh vien duoc cap hoc bong:"<<endl;
	hienthi(a,n);
}

