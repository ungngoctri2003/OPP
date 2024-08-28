#include<iomanip>
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
class Media{
	private:
		float gia;
		string tengoi;
	public:
		Media(){
			gia=0;
			tengoi="";
		}
		~Media(){
			gia=0;
			tengoi="";
		}
	void nhap();
	void xuat();
	string getTengoi();
	void timkiem();
};

string Media::getTengoi(){
	return this->tengoi;
}
void Media::nhap(){
	cout<<"Nhap vao gia ban:";cin>>gia;fflush(stdin);
	cout<<"Nhap vao ten goi:";getline(cin,tengoi);
}

void Media::xuat(){
	cout<<"Gia ban cua san pham:"<<gia<<endl;
	cout<<"Ten goi cua san pham:"<<tengoi<<endl;
}

class Video: public Media{
	private:
		float time;
	public:
		Video(){
			time=0;
		}
	void nhap();
	void xuat();
	float gettime();
};

float Video::gettime(){
	return this->time;
}

void Timkiem(Video a[], int n){
	for(int i=0;i<n;i++){
		if(a[i].getTengoi()=="Huong dan lap trinh Python" && a[i].gettime()>10){
			cout<<"\nthong tin cuon lap trinh Python"<<endl;
			a[i].xuat();
		}
	}
}
void Video::nhap(){
	Media::nhap();
	cout<<"Nhap vao thoi gian chay:";cin>>time;fflush(stdin);
}

void Video::xuat(){
	Media::xuat();
	cout<<"Thoi gian chay:"<<time<<endl;
}

void NhapDS(Video a[], int &n){
	cout<<"Nhap n video can them:";cin>>n;fflush(stdin);
	for(int i=0;i<n;i++){
		cout<<"\nDang nhap media thu:"<<i+1<<endl;
		a[i].nhap();
	}
}

void XuatDS(Video a[], int n){
	for(int i=0;i<n;i++){
		cout<<"\nThong tin Media thu:"<<i+1<<endl;
		a[i].xuat();
	}
}

int main(){
	int n;
	Video vd[100];
	Media md;
	md.nhap();
	cout<<"\nThong tin cua mot sinh vien!!"<<endl;
	md.xuat();
	NhapDS(vd,n);
	XuatDS(vd,n);
	Timkiem(vd,n);
}
