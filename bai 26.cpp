#include<stdio.h>
#include<iostream>
#include<iomanip>
using namespace std;

class SV{
	private:
		string masv;
		string hoten;
	public:
		SV(){
			masv="";
			hoten="";
		}
		~SV(){
			masv="";
			hoten="";
		}
	void nhap();
	void xuat();
};

void SV::nhap(){
	cout<<"Nhap vao ma sinh vien:";getline(cin,masv);
	cout<<"Nhap vao ho va ten:";getline(cin,hoten);
}

void SV::xuat(){
	cout<<"Ma sinh vien:"<<masv<<endl;
	cout<<"ho va ten:"<<hoten<<endl;
}


class SVCNPM: public SV{
	private:
		float dtb;
	public:
		SVCNPM(){
			dtb=0;
		}
		~SVCNPM(){
			dtb=0;
		}
	void nhap();
	void xuat();
	void diem();
	float getdtb();
};

float SVCNPM::getdtb(){
	return this->dtb;
}
void SVCNPM::nhap(){
	SV::nhap();
	cout<<"Nhap vao diem trung binh:";cin>>dtb;fflush(stdin);
}

void SVCNPM::xuat(){
	SV::xuat();
	cout<<"Diem trung binh:"<<dtb<<endl;
}

void diem(SVCNPM a[],int n){
	for(int i=0;i<n;i++){
		if(a[i].getdtb()>=8.5){
			a[i].xuat();
		}
	}
}
void NhapDS(SVCNPM a[],int &n){
	cout<<"Nhap n sinh vien:";cin>>n;fflush(stdin);
	for(int i=0;i<n;i++){
		a[i].nhap();
	}
}

void XuatDS(SVCNPM a[], int n){
	for(int i=0;i<n;i++){
		a[i].xuat();
	}
}
int main(){
	int n;
	SVCNPM svcnpm[100];
	SV sv;
	cout<<"Nhap du lieu cho 1 sinh vien!!!!"<<endl;
	sv.nhap();
	cout<<"\nDu lieu cho 1 sinh vien vua nhap la:"<<endl;
	sv.xuat();
	cout<<"\nNhap thong tin cho cac sinh vien!!!"<<endl;
	NhapDS(svcnpm,n);
	XuatDS(svcnpm,n);
	diem(svcnpm,n);
	
} 
