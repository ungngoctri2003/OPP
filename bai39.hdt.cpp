#include <iomanip>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <string.h>

using namespace std;
class Nguoi 
{
	private:
		string madd;
		string hoten;
	public:
		Nguoi ()
		{
			madd = hoten = "";
		}
		~Nguoi ()
		{
			madd = hoten = "";
		}
		void Nhap ();
		void Xuat ();
};

void Nguoi::Nhap()
{
	cout<<"Nhap ma dinh danh: ";
	fflush (stdin);
	getline (cin, madd);
	cout<<"Nhap ho ten: ";
	fflush (stdin);
	getline (cin, hoten);
}

void Nguoi::Xuat()
{
	cout<<"Ma dinh danh: "<<madd<<endl;
	cout<<"Ho ten: "<<hoten<<endl;
}

class Nhanvien :public Nguoi 
{
	friend void sapxep (Nhanvien a[], int n);
	private: 
		int namsinh;
		float hesoluong;
	public:
		int static tienphucap;
		Nhanvien ()
		{
			namsinh = hesoluong = 0;
		}
		void Nhap();
		void Xuat();
		float tinhluong();
		int gettinhluong ();
		friend operator > (Nhanvien a, Nhanvien b);
};

int Nhanvien::tienphucap = 3;
int Nhanvien::gettinhluong () 
{
	return this->hesoluong;
}

void Nhanvien::Nhap()
{
	Nguoi::Nhap();
	cout<<"Nhap nam sinh cua nhan vien: ";
	cin>>namsinh;
	cout<<"Nhap he so luong cua nhan vien: ";
	cin>>hesoluong;
}

void Nhanvien::Xuat() 
{
	Nguoi::Xuat();
	cout<<"Nam sinh cua nhan vien: "<<namsinh<<endl;
	cout<<"He so luong cua nhan vien: "<<hesoluong<<endl;
} 

float Nhanvien::tinhluong ()
{
	return hesoluong * 1550 + tienphucap;
}

void Nhapds (Nhanvien a[100], int &n)
{
	for (int i=0; i<n; i++)
	{
		cout<<"\n Nhan vien thu: "<<i+1<<endl;
		a[i].Nhap();
	}
}

void Xuatds (Nhanvien a[100], int n)
{
	for (int i=0; i<n; i++)
	{
		cout<<"\n Nhan vien thu: "<<i+1<<endl;
		a[i].Xuat();
	}
}

operator > (Nhanvien a, Nhanvien b)
{
	return a.hesoluong < b.hesoluong;
}

void sapxep (Nhanvien a[100], int n)
{
	Nhanvien temp;
	for (int i=0; i<n-1; i++)
	{
		for (int j=n+1; j<n; j++)
		{
			if (a[i].hesoluong < a[j].hesoluong)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	Xuatds (a, n);
}

int main ()
{
	Nguoi ng;
	ng.Nhap();
	ng.Xuat();
	int n;
	Nhanvien a[100];
	cout<<"So nhan vien duoc them vao danh sach: ";
	cin>>n;
	Nhapds (a, n);
	cout<<"\n Thong tin danh sach nhan vien sau khi them vao: "<<endl;
	Xuatds (a, n);
	cout<<"\n Thong tin nhan vien sau khi sap xep lai: "<<endl;
	sapxep (a, n);
}
