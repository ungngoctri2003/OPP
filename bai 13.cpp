#include<iomanip>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
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
	cout<<"Nhap ngay:";cin>>ngay;
	cout<<"Nhap thang:";cin>>thang;
	cout<<"Nhap nam:";cin>>nam;
}

void DATE::Xuat(){
	cout<<""<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}

class MUONTRA:public DATE{
	friend void sapxep(MUONTRA a[100], int n);
	private:
		string madg,masach;
		int solg;
	public:
		int static phicuoc;
	MUONTRA(){
		madg=masach="";
		solg=0;
	}
	void  Nhap();
	void Xuat();
	int tinhtien();
	friend bool operator <(MUONTRA a, MUONTRA b);
};
int MUONTRA::phicuoc=200;
void MUONTRA::Nhap(){
	DATE::Nhap();
	cout<<"Nhap vao ma doc gia:";fflush(stdin);
	cout<<"Nhap vao ma sach:";fflush(stdin);
	cout<<"Nhap so luong sach:";fflush(stdin);
}

void MUONTRA::Xuat(){
	DATE::Xuat();
	cout<<"Ma doc gia:"<<madg<<endl;
	cout<<"Ma sach:"<<masach<<endl;
	cout<<"So luong sach:"<<solg<<endl;
	cout<<"Tien cuoc muon tra"<<tinhtien()<<endl;
}

void NhapDS(MUONTRA a[100], int n){
	for(int i=0;i<n;i++){
		a[i].Nhap();
	}
}

void XuatDS(MUONTRA a[100], int n){
	for(int i=0;i<n;i++){
		a[i].Xuat();
	}
}

int MUONTRA::tinhtien(){
	return solg*phicuoc;
}

bool operator <(MUONTRA a, MUONTRA b){
	return a.solg<b.solg;
}

void Sapxep(MUONTRA a[100], int n){
	MUONTRA temp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].tinhtien()<a[j].tinhtien()){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}

		}
	}
	XuatDS(a,n);
}
int main(){
	DATE ngay;
	ngay.Nhap();
	ngay.Xuat();
	MUONTRA a[100];
	int n;
	cout<<"Nhap vao doi tuong muon tra:";cin>>n;
	NhapDS(a,n);
	cout<<"\nThong tin muon tra:"<<endl;
	XuatDS(a,n);
	cout<<"\nDanh sach muon tra sau khi sap xep:"<<endl;
	Sapxep(a,n);

}
