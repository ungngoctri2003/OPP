#include<iomanip>
#include<iostream>
using namespace std;
class DATE{
	private:
		int ngay,thang,nam;
	public:
		DATE(){
			ngay=thang=nam=0;

		}
		void Nhap();
		void Xuat();
		int getngay();
		int getthang();
		int getnam();
};

int DATE::getngay(){
	return this->ngay;
}

int DATE::	getthang(){
	return this->thang;
}

int DATE::getnam(){
	return this->nam;
}


void DATE::Nhap(){
	cout<<"Nhap vao ngay:";cin>>ngay;fflush(stdin);
	cout<<"Nhap vao thang:";cin>>thang;fflush(stdin);
	cout<<"Nhap vao nam:";cin>>nam;fflush(stdin);
}

void DATE::Xuat(){
	cout<<""<<ngay<<"/"<<thang<<"/"<<nam<<endl;
}

class MUONTRA:public DATE{
	private:
		string madg;
		string masach;
		int sl;
	public:
	float static phicuoc;
	MUONTRA(){
		madg="";
		masach="";
		sl=0;
	}
	void Nhap();
	void Xuat();
	float tinhtien();
};
float MUONTRA::phicuoc=0.2;
void MUONTRA::Nhap(){
	DATE::Nhap();
	cout<<"Nhap vao ma doc gia:";getline(cin,madg);fflush(stdin);
	cout<<"Nhap ma sach:";getline(cin,masach);fflush(stdin);
	cout<<"Nhap vap so luong:";cin>>sl;fflush(stdin);
}

float MUONTRA::tinhtien(){
	return sl*phicuoc;
}

void MUONTRA::Xuat(){
	DATE::Xuat();
	cout<<"Ma doc gia:"<<madg<<endl;
	cout<<"Ma sach:"<<masach<<endl;
	cout<<"So luong:"<<sl<<endl;
	cout<<"So tien cuoc muon tra:"<<tinhtien()<<endl;
}

void NhapDS(MUONTRA a[100], int &n){
	cout<<"Nhap vao so doi tuong muon tra:";cin>>n;fflush(stdin);
	for(int i=0;i<n;i++){
		cout<<"\nCuon sach thu:"<<i+1<<endl;
		a[i].Nhap();
	}
}

void XuatDS(MUONTRA a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nCuon sach thu:"<<i+1<<endl;
		a[i].Xuat();
	}
}
void Hienthidg(MUONTRA a[100], int n){
	for(int i=0;i<n;i++){
		if(a[i].getngay()<=31&& a[i].getthang()<=12&&a[i].getnam()<2020){
			a[i].Xuat();
		}
	}
}

void kiemtra(MUONTRA a[100], int n){
	float max=a[0].tinhtien();
	for(int i=0;i<n;i++){
		if(a[i].tinhtien()>max){
			max=a[i].tinhtien();
		}
		
	}
	for(int i=0;i<n;i++){
		if(a[i].tinhtien()==max){
			a[i].Xuat();
		}
	}
	
} 
int main(){
	DATE dt;
	int n;
	MUONTRA a[100];
	dt.Nhap();
	dt.Xuat();
	NhapDS(a,n);
	XuatDS(a,n);
	cout<<"Cac doc gia muon truoc ngay 1/1/2020:"<<endl;
	Hienthidg(a,n);
	kiemtra(a,n);
}
