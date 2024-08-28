#include<iomanip>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<string.h>
using namespace std;
class MONHOC{
	private:
		string mamh,malp;
	public:
		LOPHOC(){
			mamh,malp="";
		}
	void Nhap();
	void Xuat();
};

void MONHOC::Nhap(){
	cout<<"Nhap ma lop:";fflush(stdin);getline(cin,mamh);
	cout<<"Nhap ten lop:";fflush(stdin);getline(cin,malp);
}

void MONHOC::Xuat(){
	cout<<"Ma lop:"<<mamh<<endl;
	cout<<"Ten lop"<<malp<<endl;
}

class GIANGDAY:public MONHOC{
	private:
		string magv,mamh;
		int sotinchi;
	public:
		int static sotiet;
		GIANGDAY(){
			magv=mamh="";
			sotinchi=0;
		}
		void Nhap();
		void Xuat();
		float tinhtien();
		int Getsotin();
		string Getmagv();
};

string GIANGDAY::Getmagv(){
	return this->magv;
}
int GIANGDAY::sotiet=10;

int GIANGDAY::Getsotin(){
	return this->sotinchi;
}
void GIANGDAY::Nhap(){
	MONHOC::Nhap();
	cout<<"Nhap Ma giang vien:";fflush(stdin);getline(cin,magv);
	cout<<"Nhap Ma mon hoc:";fflush(stdin);getline(cin,mamh);
	cout<<"Nhap So tin chi:";cin>>sotinchi;
}

void GIANGDAY::Xuat(){
	MONHOC::Xuat();
	cout<<"Ma giang vien:"<<magv<<endl;
	cout<<"Ma mon hoc:"<<mamh<<endl;
	cout<<"So tin chi:"<<sotinchi<<endl;
	cout<<"So tiet con lai:"<<tinhtien()<<endl;
}

float GIANGDAY::tinhtien(){
	return sotinchi*15-sotiet;
}

void NhapDS(GIANGDAY a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nGiang vien giang day thu:"<<i+1<<endl;
		a[i].Nhap();
	}
}

void XuatDS(GIANGDAY a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nGiang vien giang day thu:"<<i+1<<endl;
		a[i].Xuat();
	}
}

void hienthi(GIANGDAY a[100], int n){
	for(int i=0;i<n;i++){
		if(a[i].Getsotin()==3){
			a[i].Xuat();
		}
	}
}

void Thap(GIANGDAY a[100], int n){
	int min=a[0].tinhtien();
	for(int i=0;i<n;i++){
		if(min>a[i].tinhtien()){
			min=a[i].tinhtien();
		}
	}
	for(int i=0;i<n;i++){
		if(min==a[i].tinhtien()){
			cout<<"Ma giang vien:"<<a[i].Getmagv()<<endl;
		}
	}
}

int main(){
	MONHOC mh;
	mh.Nhap();
	mh.Xuat();
	int n;
	GIANGDAY a[100];
	cout<<"Nhap so lop hoc muon them:";cin>>n;
	NhapDS(a,n);
	cout<<"Thong tin cac lop hoc muon them:"<<endl;
	XuatDS(a,n);
	cout<<"\nThong tin cac lop co 3 tin chi:"<<endl;
	hienthi(a,n);
	cout<<"\nCac ma giang vien co so tiet con lai:"<<endl;
	Thap(a,n);
}

