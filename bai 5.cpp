#include<stdio.h>
#include<iomanip>
#include<iostream>
using namespace std;

class DATE {
	private:
		int ngay,thang,nam;
	public:
		DATE(){
			ngay=0;
			thang=0;
			nam=0;
		}
	void nhap();
	void xuat();
};

void DATE::nhap(){
	cout<<"Nhap vao ngay:";cin>>ngay;
	cout<<"Nhap vao thang:";cin>>thang;
	cout<<"Nhap vao nam:";cin>>nam;	
}

void DATE::xuat(){
	cout<<"Ngay thang nam:";
	cout<<""<<ngay;
	cout<<"/"<<thang;
	cout<<"/"<<nam<<endl;
}

class MAYTINH: public DATE{
	private:
	int ma;
	string ten;
	float gia;
	float giaban;
	public:
	static float  tilekhuyenmai;
		MT(){
			ma=0;
			ten="";
			gia=0;
			giaban=0;
		}
	void xuat();
	void nhap();
	string getten();
	float getgia();
	void Hienthi();
	float Tinh();
};
float MAYTINH::tilekhuyenmai=0.2;
float MAYTINH::getgia(){
	return this->gia;
}
string MAYTINH::getten(){
	return this->ten;
}

void MAYTINH::nhap(){
	DATE::nhap();
	cout<<"Nhap vao ma may tinh:";cin>>ma;fflush(stdin);
	cout<<"Nhap vao ten may tinh:";getline(cin,ten);fflush(stdin);
	cout<<"Nhap vao gia niem yet:";cin>>gia;
}
float MAYTINH::Tinh(){
	return giaban=getgia()-getgia()*tilekhuyenmai;
}
void MAYTINH::xuat(){
	DATE::xuat();
	cout<<"Ma may tinh:"<<ma<<endl;
	cout<<"Ten may tinh:"<<ten<<endl;
	cout<<"Gia niem yet:"<<gia<<endl;
	cout<<"Gia ban:"<<Tinh()<<endl;
}

void NhapDS(MAYTINH a[],int &n){
	cout<<"Nhap vao n may tinh:";cin>>n;

	for(int i=0;i<n;i++){
		cout<<"\t\n thong tin may tinh thu:"<<i+1<<endl;
		a[i].nhap();
	}
}

void XuatDS(MAYTINH a[],int n){
	for(int i=0;i<n;i++){
		cout<<"\nMay tinh thu:"<<i+1<<endl;
		a[i].xuat();
	}
}

void Hienthi(MAYTINH a[100], int n){
	int kt=0;
	for(int i=0;i<n;i++){
		if(a[i].getten()=="ASUS"){
			kt++;
		}
	}
	if(kt==0){
		cout<<"\nKhong co may tinh co ten ASUS"<<endl;
	}
	else{
		for(int i=0;i<n;i++)
		{
			a[i].xuat();
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
			mt[i].xuat();
		}
	}
}

int main(){
	int n;
	MAYTINH mt[100];
	DATE dt;
	cout<<"Nhap thong tin cho cac may tinh "<<endl;
	dt.nhap();
	cout<<"\nThong tin may tinh vua nhap"<<endl;
	dt.xuat();
	NhapDS(mt,n);
	cout<<"\nThong tin cac may tinh vua nhap"<<endl;
	XuatDS(mt,n);
	Hienthi(mt,n);
	cout<<"\nThong tin cac may tinh co gia ban thuc te thap nhat:"<<endl;
	Min(mt,n);
}
