#include<iomanip>
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class PhuongTienGiaoThong{
	private:
		string hangsx;
		string ten;
		int nam;
		float vmax;
	public:
		PhuongTienGiaoThong(){
			hangsx="";
			ten="";
			nam=0;
			vmax=0;
		}
	void Nhap();
	void Xuat();
	string gethangsx();

};

void PhuongTienGiaoThong::Nhap(){
	cout<<"Nhap hang san xuat:";cin>>hangsx;
	cout<<"Nhap ten nha san xuat:";cin>>ten;
	cout<<"Nhap nam san xuat:";cin>>nam;
	cout<<"van toc toi da:";cin>>vmax;
}

void PhuongTienGiaoThong::Xuat(){
	cout<<""<<endl;
	cout<<"Hang san xuat:"<<hangsx<<endl;
	cout<<"Ten nha san xuat:"<<ten<<endl;
	cout<<"Nam san xuat:"<<nam<<endl;
	cout<<"Van toc toi da:"<<vmax<<endl;
}


class OTo: public PhuongTienGiaoThong{
	private:
     	friend void Timkiem();
		int Socho;
		string Dongco;
	public:
	OTo(){
		Socho=0;
		Dongco="";
	}
	~OTo(){
		Socho=0;
		Dongco="";
	}
	void Nhap();
	void Xuat();
	friend void Timkiem();

};

void OTo::Nhap(){
	PhuongTienGiaoThong::Nhap();
	cout<<"Nhap vao so cho ngoi:";cin>>Socho;fflush(stdin);
	cout<<"Nhap vao kieu dong co:";getline(cin,Dongco);
}

void OTo::Xuat(){
	PhuongTienGiaoThong::Xuat();
		cout<<"So cho ngoi:"<<Socho<<endl;
		cout<<"Kieu dong co:"<<Dongco<<endl;
	
}


 
void NhapDS(OTo a[], int &n){
	cout<<"Nhap n:";cin>>n;
	for(int i=0;i<n;i++){
		a[i].Nhap();
	}
}

string PhuongTienGiaoThong::gethangsx(){
	return this->hangsx;
}
void Timkiem(OTo a[], int n){
	int kt=0;
	for(int i=0;i<n;i++){
		if(a[i].gethangsx()=="honda"){
			kt++;
		}
}	
	if(kt==0){
		cout<<"Khong co hang san xuat honda nao!!!";
		}
	
	else{
		cout<<"thong tin cac phuong tien cua hang san xuat honda"<<endl;
		for(int i=0;i<n;i++){
			a[i].Xuat();
		}
	}
}

void XuatDS(OTo a[],int n){
	for(int i=0;i<n;i++){
		a[i].Xuat();
	}
}


int main(){
	int n;
	OTo oto[100];
	PhuongTienGiaoThong ptgt;
	ptgt.Nhap();
	ptgt.Xuat();
	NhapDS(oto,n);
	cout<<"Thong tin vua nhap cho n phuong tien!!!"<<endl;
	XuatDS(oto,n);
	Timkiem(oto,n);

	
}
