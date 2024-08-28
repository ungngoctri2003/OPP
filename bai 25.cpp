#include<stdio.h>
#include<iomanip>
#include<iostream>
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
	cout<<"Nhap vao ma sinh vien:";getline(cin,masv);fflush(stdin);
	cout<<"Nhap vao ho va ten :";getline(cin,hoten);fflush(stdin);
}

void SV::xuat(){
	cout<<"Ma sinh vien:"<<masv<<endl;
	cout<<"Ho va ten sinh vien :"<<hoten<<endl;
}

class SVSDH: public SV{
	private:
		float hocphi;
	public:
		SVSDH(){
			hocphi=0;
		}
		~SVSDH(){
			hocphi=0;
		}
		
		void nhap();
		void xuat();
		void Hocphi();
		float getHocPhi();
};

float SVSDH::getHocPhi(){
	return this->hocphi;
}
void SVSDH::nhap(){
	SV::nhap();
	cout<<"Nhap vao hoc phi sinh vien:";cin>>hocphi;fflush(stdin);
}

void SVSDH::xuat(){
	SV::xuat();
	cout<<"Hoc phi cua sinh vien vua nhap:"<<hocphi;
}

void NhapDS(SVSDH a[], int &n){
	cout<<"Nhap vao so luong sinh vien:";cin>>n;fflush(stdin);
	for(int i=0;i<n;i++){
		cout<<"\n\t Sinh vien thu"<<i+1<<endl;
		a[i].nhap();
	}
}

void Hocphi(SVSDH a[], int n){
	for(int i=0;i<n;i++){
		if(a[i].getHocPhi()>9000){
			a[i].xuat();
		}
	}
}
void XuatDS(SVSDH a[],int n){
	for(int i=0;i<n;i++){
		a[i].xuat();
	}
}
int main(){
	int n;
	SVSDH svsdh[100];
	SV sv;
	cout<<"Nhap thong tin cho mot sinh vien"<<endl;
	sv.nhap();
	cout<<"\nThong tin mot sinh vien"<<endl;
	sv.xuat();
	cout<<"\nThong tin nhieu sinh vien"<<endl;
	NhapDS(svsdh,n);	
	XuatDS(svsdh,n);
	cout<<"Thong tin sinh vien co hoc phi >9000:"<<endl;
	Hocphi(svsdh,n);
	
}
