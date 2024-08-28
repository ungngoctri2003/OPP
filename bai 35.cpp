
#include<iomanip>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<string.h>
using namespace std;
class HANGHOA{
	private:
		int mahang;
		string tenhang;
	public:
		HANGHOA(){
			mahang=0;
			tenhang="";
		}
		~HANGHOA(){
			mahang=0;
			tenhang="";
		}
		void Nhap();
		void Xuat();
};

void HANGHOA::Nhap(){
	cout<<"Nhap ma hang:";cin>>mahang;
	cout<<"Nhap ten hang:";fflush(stdin);getline(cin,tenhang);
}

void HANGHOA::Xuat(){
	cout<<"Ma hang:"<<mahang<<endl;
	cout<<"Ten hang:"<<tenhang<<endl;
}


class MAYTINH:public HANGHOA{
	friend void sapxep(MAYTINH a[], int n);
	private:
		string nhasx;
		int namsx;
		float giabanNY;
	public:
		float static tilekhuyenmai;
	MAYTINH(){
		nhasx="";
		namsx=giabanNY=0;
	}
	void Nhap();
	void Xuat();
	float giabanTT();
	friend operator >(MAYTINH a, MAYTINH b);
};

float MAYTINH::tilekhuyenmai=0.2;
void MAYTINH::Nhap(){
	HANGHOA::Nhap();
	cout<<"Nhap vao nha san xuat:";fflush(stdin);getline(cin,nhasx);
	cout<<"Nhap nam san xuat:";cin>>namsx;
	cout<<"Nhap gia ban niem yet:";cin>>giabanNY;
}

void MAYTINH ::Xuat(){
	HANGHOA::Xuat();
	cout<<"Nha san xuat:"<<nhasx<<endl;
	cout<<"Nam san xuat:"<<namsx<<endl;
	cout<<"Gia ban niem yet:"<<giabanNY<<endl;
}

float MAYTINH::giabanTT(){
	return giabanNY-giabanNY*tilekhuyenmai;
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

operator >(MAYTINH a,MAYTINH b){
	return a.giabanTT()>b.giabanTT();
}

void sapxep(MAYTINH a[100], int n){
	MAYTINH temp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].giabanTT()<a[j].giabanTT()){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	XuatDS(a,n);
}

int main(){
	HANGHOA hh;
	hh.Nhap();
	hh.Xuat();
	int n;
	MAYTINH a[100];
	cout<<"So may tinh them:";cin>>n;
	NhapDS(a,n);
	cout<<"\nThong tin may tinh da them:"<<endl;
	XuatDS(a,n);
	cout<<"\nThong tin may sau khi sap xem:"<<endl;
	sapxep(a,n);


}

