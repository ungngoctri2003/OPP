
#include<iomanip>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Dichvu{
	private:
		int madv;
		string tendv;
		float giacuoc;
	public:
		Dichvu(){
			madv=giacuoc=0;
			tendv="";
		}
		void Nhap();
		void Xuat();
		float Laygiacuoc();
};

void Dichvu::Nhap(){
	cout<<"Nhap ma dich vu:";cin>>madv;
	cout<<"Nhap ten dich vu:";fflush(stdin);getline(cin,tendv);
	cout<<"Nhap gia cuoc:";cin>>giacuoc;
}

void Dichvu::Xuat(){
	cout<<"Ma dich vu:"<<madv<<endl;
	cout<<"Ten dich vu:"<<tendv<<endl;
	cout<<"Gia cuoc:"<<giacuoc<<endl;
}

float Dichvu::Laygiacuoc(){
	return this->giacuoc;
}

class Nguoi{
	private:
		string hoten,diachi;
		int sodt;
	public:
		Nguoi(){
			hoten=diachi="";
			sodt=0;
		}
		void Nhap();
		void Xuat();
};

void Nguoi::Nhap(){
	cout<<"Nhap ho va ten:";fflush(stdin);getline(cin,hoten);
	cout<<"Nhap dia chi:";fflush(stdin);getline(cin,diachi);
	cout<<"Nhap so dien thoai:";cin>>sodt;
}

void Nguoi::Xuat(){
	cout<<"Ho va ten:"<<hoten<<endl;
	cout<<"Dia chi:"<<diachi<<endl;
	cout<<"So dien thoai"<<sodt<<endl;
}

class KhachHang:public Nguoi{
	private:
		int soluongdv;
		Dichvu dv[100];
	public:
		Khachhang(){
			soluongdv=0;
			Dichvu dv[100];
		}
		void Nhap();
		void Xuat();
		float Tonggiacuoc();

};

void KhachHang::Nhap(){
	Nguoi::Nhap();
	cout<<"Nhap so luong dich vu them:";cin>>soluongdv;
	for(int i=0;i<soluongdv;i++){
		cout<<"\nDich vu thu:"<<i+1<<endl;
		dv[i].Nhap();
	}
}

void KhachHang::Xuat(){
	Nguoi::Xuat();
	cout<<"\nSo luong dich vu khach hang them:"<<soluongdv<<endl;
	for(int i=0;i<soluongdv;i++){
		cout<<"\nDich vu thu:"<<i+1<<endl;
		dv[i].Xuat();
	}
}

float KhachHang::Tonggiacuoc(){
	float tong;
	for(int i=0;i<soluongdv;i++){
		tong=tong+dv[i].Laygiacuoc();
	}
	return tong;
}
int main(){
	Dichvu dv;
	dv.Nhap();
	dv.Xuat();
	KhachHang kh;
	cout<<"\nNhap vao thong tin cua khach hang"<<endl;
	kh.Nhap();
	cout<<"\nThong tin khach hang:"<<endl;
	kh.Xuat();
	cout<<"Tong gia cuoc khach hang da su dung la:"<<kh.Tonggiacuoc()<<endl;



}

