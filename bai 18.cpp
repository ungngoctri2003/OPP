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
			ngay=thang=nam=0;
		}
		void Nhap();
		void Xuat();
};

void DATE::Nhap(){
	cout<<"Nhap vao ngay:";cin>>ngay;
	cout<<"Nhap vao thang:";cin>>thang;
	cout<<"Nhap vao nam:";cin>>nam;
}

void DATE::Xuat(){
	cout<<""<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}

class MAYTINH:public DATE{
	private:
		int mamt;
		string tenmt;
		float gianiemyet; 
	public:
		float static khuyenmai;
		MAYTINH(){
			mamt=gianiemyet=0;
			tenmt="";
		}
		void Nhap();
		void Xuat();
		float tinhtien();
		friend void hienthi(MAYTINH a[100], int n);
};

float MAYTINH::khuyenmai=0.2;

float MAYTINH::tinhtien(){
	return gianiemyet-gianiemyet*khuyenmai;
}
void MAYTINH::Nhap(){
	DATE::Nhap();
	cout<<"Nhap vao ma may tinh:";cin>>mamt;
	cout<<"Nhap ten may tinh:";fflush(stdin);getline(cin,tenmt);
	cout<<"Nhap gia niem yet:";cin>>gianiemyet;
} 

void MAYTINH::Xuat(){
	DATE::Xuat();
	cout<<"Ma may tinh:"<<mamt<<endl;
	cout<<"Ten may tinh:"<<tenmt<<endl;
	cout<<"Gia niem yet:"<<gianiemyet<<endl;
	cout<<"Gia ban thuc te:"<<tinhtien()<<endl;
}

void NhapDS(MAYTINH a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nMay tinh thu:"<<i+1<<endl;
		a[i].Nhap();
	}
}

void XuatDS(MAYTINH a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nMay tinh thu:"<<i+1<<endl;
		a[i].Xuat();
	}
}

void hienthi(MAYTINH a[100], int n){
	for(int i=0;i<n;i++){
		if(a[i].tenmt=="ASUS"){
			a[i].Xuat();
		}
	}
}

void giabanthap(MAYTINH a[100], int n){
	float min;
	min=a[0].tinhtien();
	for(int i=0;i<n;i++){
	    if(min>a[i].tinhtien()){
	    	min=a[i].tinhtien();
		}
	}
	for(int i=0;i<n;i++){
		if(min==a[i].tinhtien()){
			a[i].Xuat();
		}
	}
}


int main(){
	DATE dt;
	dt.Nhap();
	dt.Xuat();
	MAYTINH a[100];
	int n;
	cout<<"Nhap vao so may tinh muon them:";cin>>n;
	NhapDS(a,n);
	cout<<"\nCac may tinh vua nhap:"<<endl;
	XuatDS(a,n);
	cout<<"\nCac may tinh co ten ASUS:"<<endl;
	hienthi(a,n);
	cout<<"\nCac may tinh co gia ban thuc te thap nhat:"<<endl;
	giabanthap(a,n);
}

