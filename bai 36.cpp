#include<stdio.h>
#include<iomanip>
#include<iostream>
using namespace std;

class HANGHOA{
	private:
		int  mahang;
		string tenhang;
	public:
		HANGHOA(){
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

class MAYTINH: public HANGHOA{
	private:
	string nhasx;
	int namsx;
	float giabanNY;
	public:
	static float  tilekhuyenmai;
		MAYTINH(){
			nhasx="";
			namsx=giabanNY=0;
		}
	void Xuat();
	void Nhap();
	float getgia();
	void Hienthi();
	string getnhasx();
	float Tinh();
};
float MAYTINH::tilekhuyenmai=0.2;
float MAYTINH::getgia(){
	return this->giabanNY;
}

string MAYTINH::getnhasx(){
	return this->nhasx;
}
void MAYTINH::Nhap(){
	HANGHOA::Nhap();
	cout<<"Nhap nha san xuat:";fflush(stdin);getline(cin,nhasx);
	cout<<"Nhap nam san xuat:";cin>>namsx;
	cout<<"Nhap  gia ban niem yet:";cin>>giabanNY;
}
float MAYTINH::Tinh(){
	float tinh;
	return tinh=getgia()-getgia()*tilekhuyenmai;
}
void MAYTINH::Xuat(){
	HANGHOA::Xuat();
		cout<<"Nha san xuat:"<<nhasx<<endl;
		cout<<"Nam san xuat:"<<namsx<<endl;
		cout<<"Gia ban niem yet:"<<giabanNY<<endl;
	
}

void NhapDS(MAYTINH a[],int &n){
	cout<<"Nhap vao n may tinh:";cin>>n;
	for(int i=0;i<n;i++){
		cout<<"\t\n thong tin may tinh thu:"<<i+1<<endl;
		a[i].Nhap();
	}
}

void XuatDS(MAYTINH a[],int n){
	for(int i=0;i<n;i++){
		cout<<"\nMay tinh thu:"<<i+1<<endl;
		a[i].Xuat();
	}
}

void Hienthi(MAYTINH mt[100], int n){
	for(int i=0;i<n;i++){
		if(mt[i].getnhasx()=="SAM SUNG"){
			mt[i].Xuat();
		}
	}
}

void Min(MAYTINH mt[100], int n){
	float min=mt[0].Tinh();
	for(int i=0;i<n;i++){
		if(min>mt[i].Tinh()){
			min=mt[i].Tinh();
		}
	}
	for(int i=0;i<n;i++){
		if(min==mt[i].Tinh()){
			mt[i].Xuat();
		}
	}
}

int main(){
	int n;
	MAYTINH mt[100];
	HANGHOA hh;
	cout<<"Nhap thong tin cho cac may tinh "<<endl;
	hh.Nhap();
	cout<<"\nThong tin may tinh vua nhap"<<endl;
	hh.Xuat();
	NhapDS(mt,n);
	cout<<"\nThong tin cac may tinh vua nhap"<<endl;
	XuatDS(mt,n);
	cout<<"\nThong tin cac may tinh SAM SUNG:"<<endl;
	Hienthi(mt,n);
	cout<<"\nThong tin cac may tinh co gia ban thuc te thap nhat:"<<endl;
	Min(mt,n);
}
