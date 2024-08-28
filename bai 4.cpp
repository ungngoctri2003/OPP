#include<stdio.h>
#include<iomanip>
#include<iostream>
#include<string.h>
using namespace std;

class SV{
	private:
		int masv;
		string hoten;
	public:
		SV(){
		    masv=0;
		    hoten="";
		}
		~SV(){
			masv=0;
		    hoten="";
		}
	void nhap();
	void xuat();
};

void SV::nhap(){
	cout<<"Nhap thong tin cua ban!!!!!"<<endl;
	cout<<"Nhap ma sinh vien:";cin>>masv;fflush(stdin);
	cout<<"Nhap ho va ten:";getline(cin,hoten);
}

void SV::xuat(){
	cout<<"Ma sinh vien:"<<masv<<endl;
	cout<<"Ho va ten:"<<hoten<<endl;
}

class SVAL:public SV{
    friend void Sapxep(SVAL [],int);
	private:		
		float diem;
	public:
		SVAL(){
			diem=0;
		}
		~SVAL(){
			diem=0;
		}
	void nhap();
	void hienthi();
};

void SVAL::nhap(){
	SV::nhap();
	cout<<"Nhap diem trung binh:";cin>>diem;
}

void SVAL::hienthi(){
	SV::xuat();
	cout<<"Diem trung binh:"<<diem<<endl;
}

void NhapDS(SVAL a[],int &n){
	cout<<"Nhap vao n sinh vien:";cin>>n;
	for(int i=0;i<n;i++){
		a[i].nhap();
	}
}

void Sapxep(SVAL a[],int n){
	SVAL temp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
				if(a[i].diem<a[j].diem){
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
		}
	
	}
}
void XuatDS(SVAL a[],int n){
	for(int i=0;i<n;i++){
		a[i].xuat();
	}
}
int main(){
	int n;
	SVAL sval[100];
	SV sv;
	sv.nhap();
	sv.xuat();
	NhapDS(sval,n);
	Sapxep(sval,n);
	XuatDS(sval,n);
	
}

