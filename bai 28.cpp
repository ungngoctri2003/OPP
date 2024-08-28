#include<iomanip>
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

class Media {
	private:
		string tengoi;
		float gia;
	public:
		Media(){
			tengoi="";
			gia=0;
		}
		~Media(){
			tengoi="";
			gia=0;
		}
	void nhap();
	void xuat();
	string gettengoi();
};

string Media::gettengoi(){
	return this->tengoi;
}


void Media::nhap(){
	cout<<"Nhap vao ten goi:";getline(cin,tengoi);
	cout<<"Nhap vao gia ban:";cin>>gia;fflush(stdin);
}

void Media::xuat(){
	cout<<"Ten goi san pham:"<<tengoi<<endl;
	cout<<"Gia ban san pham:"<<gia<<endl;
}

class Book: public Media{
	private:
		int sotrang;
		string tacgia;
	public:
	Book(){
		sotrang=0;
		tacgia="";
	}
	
	void nhap();
	void xuat();
	string gettacgia();
};


string Book::gettacgia(){
	return this->tacgia;
}
void Book::nhap(){
	Media::nhap();
	cout<<"Nhap vao so trang:";cin>>sotrang;fflush(stdin);
	cout<<"Nhap vao ten tac gia:";getline(cin,tacgia);
}

void Book::xuat(){
	Media::xuat();
	cout<<"So trang:"<<sotrang<<endl;
	cout<<"Ten tac gia:"<<tacgia<<endl;
}

void NhapDS(Book a[], int &n){
	cout<<"\nNhap vao n video:";cin>>n;fflush(stdin);
	for(int i=0;i<n;i++){
		cout<<"\nNhap thong tin video thu:"<<i+1<<endl;
		a[i].nhap();
	}
}

void XuatDS(Book a[], int n){
	for(int i=0;i<n;i++){
		cout<<"\nThong tin video thu:"<<i+1<<endl;
		a[i].xuat();
	}
}

void hienthi(Book a[], int n){
	cout<<"\nThong tin cuon sach lap trinh C++ cua tac gia  nguyen thanh thuy"<<endl;
	for(int i=0;i<n;i++){
		if(a[i].gettengoi()=="Lap trinh C++" && a[i].gettacgia()=="Nguyen Thanh Thuy"){
			a[i].xuat();
		}
	}
}
int main(){
	Book bk[100];
	int n;
	Media md;
	cout<<"Nhap vao 1 Media"<<endl;
	md.nhap();
	cout<<"\nThong tin cua 1 Media"<<endl;
	md.xuat();
	NhapDS(bk,n);
	XuatDS(bk,n);
	hienthi(bk,n);
	
	
}
