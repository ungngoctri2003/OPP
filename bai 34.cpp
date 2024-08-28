#include<iostream>
#include<iomanip>
using namespace std;
class  SACH{
	private:
		string masach;
		string tensach;

	public:
		SACH(){
			masach="";
			tensach="";

		}
	void Nhap();
	void Xuat();
};

void SACH::Nhap(){
	cout<<"Nhap vao ma sach:";getline(cin,masach);fflush(stdin);
	cout<<"Nhap vao ten sach:";getline(cin,tensach);fflush(stdin);
}

void SACH::Xuat(){
	cout<<"Ma sach:"<<masach<<endl;
	cout<<"Ten sach:"<<tensach<<endl;
}

class Muontra: public SACH{
	private:
		string madocgia;
		int soluong;
		float phicuoc;
	public:
	Muontra(){
		madocgia="";
		soluong=0;
		phicuoc=0;

	}
	void Nhap();
	void Xuat();
	int getsl();
	int getphicuoc();
	float Tinhtien();
};


void hienthi(Muontra a[100], int n){
	for(int i=0;i<n;i++){
		if(a[i].getsl()>10){
		a[i].Xuat();
	}
	}

}
int Muontra::getsl(){
	return this->soluong;
}

int Muontra::getphicuoc(){
	return this->phicuoc;
}

float Muontra::Tinhtien(){
	float tinh;
	return tinh=getsl()*getphicuoc();
}

void kiemtra(Muontra a[100], int n){
	float max=a[0].Tinhtien();
	for(int i=0;i<n;i++){
		if(a[i].Tinhtien()>max){
		    max=a[i].Tinhtien();
		}
	}
	for(int i=0;i<n;i++){
		if(a[i].Tinhtien()==max){
			a[i].Xuat();
		}
	}

}

void Muontra::Nhap(){
    SACH::Nhap();
	cout<<"Nhap vao ma doc gia:";getline(cin,madocgia);fflush(stdin);
	cout<<"Nhap vao so luong:";cin>>soluong;fflush(stdin);
	cout<<"Nhap vao phi cuoc muon tra:";cin>>phicuoc;fflush(stdin);
}

void Muontra::Xuat(){
	cout<<"Ma doc gia:"<<madocgia<<endl;
	cout<<"So luong:"<<soluong<<endl;
	cout<<"Phi cuoc:"<<phicuoc<<endl;
	cout<<"So tien phai tra:"<<Tinhtien()<<endl;
}

void NhapDS(Muontra a[100], int &n){
	cout<<"Nhap vao so cuon sach can them:";cin>>n;fflush(stdin);
	for(int i=0;i<n;i++){
		cout<<"\nCuon sach thu:"<<i+1<<endl;
		a[i].Nhap();
	}
}

void XuatDS(Muontra a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nCuon sach thu:"<<i+1<<endl;
		a[i].Xuat();
	}
}


int main(){
	int n;
	Muontra a[100];
	SACH sach;
	sach.Nhap();
	sach.Xuat();
	NhapDS(a,n);
	XuatDS(a,n);
	cout<<"\nCac doc gia co so luong  muon >10 cuon:"<<endl;
	hienthi(a,n);
	cout<<"\nCac doc gia co so tien cuoc nhieu nhat:"<<endl;
	kiemtra(a,n);
}
