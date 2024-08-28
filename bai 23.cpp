#include<iomanip>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<string.h>
using namespace std;
class THISINH{
	private:
		int sobd;
		string hoten,diachi;
		float diemut;
	public:
		THISINH(){
			sobd=diemut=0;
			hoten=diachi="";
		}
		float Getdiemut();
		void Nhap();
		void Xuat();
};

float THISINH::Getdiemut(){
	return this->diemut;
}
void THISINH::Nhap(){
	cout<<"Nhap so bao danh:";cin>>sobd;
	cout<<"Nhap ho va ten:";fflush(stdin);getline(cin,hoten);
	cout<<"Nhap dia chi:";fflush(stdin);getline(cin,diachi);
	cout<<"Nhap diem uu tien:";cin>>diemut;
}

void THISINH::Xuat(){
	cout<<"So bao danh:"<<sobd<<endl;
	cout<<"Ho va ten:"<<hoten<<endl;
	cout<<"Dia chi:"<<diachi<<endl;
	cout<<"Diem uu tien:"<<diemut<<endl;
}

class THISINHKHOIA:public THISINH{
	friend void sapxep(THISINHKHOIA a[100], int n);
	private:
		float toan,li,hoa;
	public:
		THISINHKHOIA(){
			toan,li,hoa=0;
		}
		~THISINHKHOIA(){
			toan,li,hoa=0;
		}
		void Nhap();
		void Xuat();
	float tinhtong();
	float diemtb();
	friend bool operator <(THISINHKHOIA a,THISINHKHOIA b);


};

float THISINHKHOIA::tinhtong(){
	return toan+li+hoa+Getdiemut();
}
float THISINHKHOIA::diemtb(){
	return (toan+li+hoa)/3;
}
bool operator <(THISINHKHOIA a, THISINHKHOIA b){
	return a.diemtb()>b.diemtb();
}

void THISINHKHOIA::Nhap(){
	THISINH::Nhap();
	cout<<"Nhap diem toan:";cin>>toan;
	cout<<"Nhap diem li:";cin>>li;
	cout<<"Nhap diem hoa:";cin>>hoa;
}

void THISINHKHOIA::Xuat(){
	THISINH::Xuat();
	cout<<"Diem toan:"<<toan<<endl;
	cout<<"Diem li:"<<li<<endl;
	cout<<"Diem hoa:"<<hoa<<endl;
	cout<<"Tong diem:"<<tinhtong()<<endl;
}


void NhapDS(THISINHKHOIA a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nThi sinh thu:"<<i+1<<endl;
		a[i].Nhap();
	}
}

void XuatDS(THISINHKHOIA a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nThi sinh thu:"<<i+1<<endl;
		a[i].Xuat();
	}
}

void sapxep(THISINHKHOIA a[100], int n){
	THISINHKHOIA temp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[i].tinhtong()<a[j].tinhtong()){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	XuatDS(a,n);
}
int main(){
	THISINH ts;
	ts.Nhap();
	ts.Xuat();
	THISINHKHOIA a[100];
	int n;
	cout<<"Nhap vao so thi sinh muon them:";
	cin>>n;
	NhapDS(a,n);
	cout<<"\nThong tin cac thi sinh muon them:";
	XuatDS(a,n);
	cout<<"\nDanh sach cac thi sinh sap xem giam dan:";
	sapxep(a,n);
}

