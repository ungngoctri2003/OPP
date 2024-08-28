#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdlib.h>

using namespace std;
class Nguoi 
{
	private:
		string madh;
		string hoten;
	public:
		sach () 
		{
			madh = hoten = "";
		}
		void Nhap ();
		void Xuat ();
};

void Nguoi::Nhap() 
{
	cout<<"Nhap ma dinh danh: "<<endl;
	fflush (stdin); 
	getline (cin, madh);
	cout<<"Nhap ho ten: "<<endl;
	fflush (stdin); 
	getline (cin, hoten);
}

void Nguoi::Xuat() 
{
	cout<<"Ma sach dinh danh: "<<madh<<endl;
	cout<<"Ho ten: "<<hoten<<endl;
}

class Nhanvien:public Nguoi 
{
	private: 
		string namsinh;
		int hesoluong;
	public:
		static int tienphucap;
		Nhanvien () 
		{
			namsinh = "";
			hesoluong = 0;
		}
		void Nhap ();
		void Xuat ();
		int tinhtien ();
		int gettinhluong ();
};
int Nhanvien::tienphucap = 2;
int Nhanvien::gettinhluong () 
{
	return this->hesoluong;
}

void Nhanvien::Nhap() 
{
	Nguoi::Nhap();
	cout<<"Nhap nam sinh: "; 
	fflush (stdin); 
	getline (cin, namsinh);
	cout<<"He so luong: "; 
	cin>>hesoluong;
}

void Nhanvien::Xuat() 
{
	Nguoi::Xuat();
		cout<<"Ma nam sinh: "<<namsinh<<endl;
		cout<<"He so luong: "<<hesoluong<<endl;
}

int Nhanvien::tinhtien() 
{
	return hesoluong * 1550 - tienphucap;
}

void Nhapds (Nhanvien a[], int &n) 
{
	cout<<"Nhap n: "<<endl; 
	cin>>n;
	for(int i =0; i<n; i++) 
	{
		a[i].Nhap();
	}
}

void Xuatds (Nhanvien a[], int n) 
{
	for(int i =0; i<n; i++) 
	{
		a[i].Xuat();
	}
}

void Nhanviencoluongcaonhat (Nhanvien a[], int n) 
{
	int max = a[0].tinhtien();
	for(int i =0; i<n; i++) 
	{
		if(a[i].tinhtien()>max) 
		{
		max = a[i].tinhtien();
		}
	}
	for(int i =0; i<n; i++) 
	{
		if(max == a[i].tinhtien()) 
		{
			a[i].Xuat();
		}
	}
}

int main () 
{
	Nguoi ng;
	ng.Nhap ();
	ng.Xuat ();
	Nhanvien a[100];
	int n;
	cout<<"Nhap danh sach: "<<endl;
	Nhapds (a, n);
	cout<<"Xuat danh sach: "<<endl;
	Xuatds (a, n);
	cout<<"Danh sach nhan vien co luong cao nhat: "<<endl;
	Nhanviencoluongcaonhat (a, n);
	return 0;
}
