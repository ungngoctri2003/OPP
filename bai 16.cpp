#include<iomanip>
#include<iostream>

using namespace std;
class LOPHOC{
	private:
		string malop;
		string tenlop;
	public:
		LOPHOC(){
			malop=tenlop="";
		}
	void Nhap();
	void Xuat();
};

void LOPHOC::Nhap(){
	cout<<"Nhap vao ma lop hoc:";getline(cin,malop);fflush(stdin);
	cout<<"Nhap vao ten lop hoc:";getline(cin,tenlop);fflush(stdin);
}

void LOPHOC::Xuat(){
	cout<<"Ma lop hoc:"<<malop<<endl;
	cout<<"Ten lop hoc:"<<tenlop<<endl;
}

class GIANGDAY : public LOPHOC{
	private:
		string magv;
		string mamh;
		string malop;
		int sotin;
	public:
		int static sotiet;
		GIANGDAY(){
			magv=mamh=malop="";
			sotin=0;
		}
		void Nhap();
		void Xuat();
		float sotien();
		int getsotin();
		
};

int GIANGDAY::getsotin(){
	return this->sotin;
}

float GIANGDAY::sotien(){
	return  getsotin()*15-sotien
}

int GIANGDAY::sotien=14;
void GIANGDAY::Nhap(){
	LOPHOC::Nhap();
	cout<<"Nhap vao ma giang vien:";getline(cin,magv);fflush(stdin);
    cout<<"Nhap vao ma mon hoc:";getline(cin,mamh);fflush(stdin);
	cout<<"Nhap vao ma lop hoc:";getline(cin,malop);fflush(stdin);
}

void GIANGDAY::Xuat(){
	LOPHOC::Xuat();
	cout<<"Ma giang vien:"<<magv<<endl;
	cout<<"Ma mon hoc:"<<mamh<<endl;
	cout<<"Ma lop hoc:"<<malop<<endl;
}

void NhapDS(GIANGDAY a[100] , int &n){
	cout<<"Nhap vao so doi tuong muon them:";cin>>n;fflush(stdin);
	for(int i=0;i<n;i++){
	cout<<"Lop hoc giang day thu:"<<i+1<<endl;
	a[i].Nhap(); 
	}
}

void XuatDS(GIANGDAY a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"Lop hoc giang day thu:"<<i+1<<endl;
		a[i].Xuat();
	}
}
int main(){
	int n;7
	GIANGDAY a[100];
	LOPHOC lp;
	lp.Nhap();
	lp.Xuat();
	NhapDS(a,n);
	XuatDS(a,n);
}
