#include<iomanip>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<string.h>
using namespace std;
class HANGHOA{
	private:
		string mahang,tenhang;
	public:
		HANGHOA(){
			mahang=tenhang="";
		}
		void Nhap();
		void Xuat();
		string Getten();
};

string HANGHOA::Getten(){
	return this->tenhang;
}
void HANGHOA::Nhap(){
	cout<<"Nhap ma hang:";fflush(stdin);getline(cin,mahang);
	cout<<"Nhap ten hang:";fflush(stdin);getline(cin,tenhang);
}

void HANGHOA::Xuat(){
	cout<<"Ma hang:"<<mahang<<endl;
	cout<<"Ten hang:"<<tenhang<<endl;
}

class MAYTINH:public HANGHOA{
	private:
		string nhasx;
		int nam;
		float gia;
	public:
		float static khuyenmai;
		MAYTINH(){
			nhasx="";
			nam=gia=0;
		}
		void Nhap();
		void Xuat();
		float giaban();
		string Getnhasx();
        void hienthi();
};
float MAYTINH::khuyenmai=0.2;

string MAYTINH::Getnhasx(){
	return this->nhasx;
}


float MAYTINH::giaban(){
	return gia-gia*khuyenmai;
}
void MAYTINH::Nhap(){
	HANGHOA::Nhap();
	cout<<"Nhap nha san xuat:";fflush(stdin);getline(cin,nhasx);
	cout<<"Nhap nam san xuat:";cin>>nam;
	cout<<"Nhap gia ban niem yet:";cin>>gia;
}

void MAYTINH::Xuat(){
	HANGHOA::Xuat();
	cout<<"Nha san xuat:"<<nhasx<<endl;
	cout<<"Nam san xuat:"<<nam<<endl;
	cout<<"Gia ban niem yet:"<<gia<<endl;
	cout<<"Gia ban thuc te:"<<giaban()<<endl;
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
		if(a[i].Getnhasx()=="SAM SUNG"){
			a[i].Xuat();
		}
	}
}

void SAPXEP(MAYTINH a[100], int n){
	float min=a[0].giaban();
	for(int i=0;i<n;i++){
		if(min>a[i].giaban()){
			min=a[i].giaban();
		}
	}
	
	
	for(int i=0;i<n;i++){
		if(a[i].giaban()==min){
			a[i].Xuat();  
		}
	}
}
int main(){
	HANGHOA hh;
	hh.Nhap();
	hh.Xuat();
	int n;
	MAYTINH a[100];
	cout<<"\nNhap vao so may tinh can them:";cin>>n;
	NhapDS(a,n);
	cout<<"\nThong tin cac may tinh:"<<endl;
	XuatDS(a,n);
	cout<<"\nCac may tinh co nha san xuat SAM  SUNG la:"<<endl;
	hienthi(a,n);
	cout<<"\nCac may tinh co chi phi thuc te it nhat la:"<<endl;
	SAPXEP(a,n);
	
}

