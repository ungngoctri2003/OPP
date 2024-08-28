
#include<iostream>
#include<iomanip>
using namespace std;
class NGUOI{
	private:
		string hoten;
		string gioitinh;
		int nam;
	public:
		NGUOI(){
			hoten="";
			gioitinh="";
			nam=0;
		}
		~NGUOI(){
			hoten="";
			gioitinh="";
			nam=0;
		}
	void Nhap();
	void Xuat();
	int getnam();
	int tinhtuoi();


};

void NGUOI::Nhap(){
	cout<<"Nhap vao ho ten:";getline(cin,hoten);fflush(stdin);
	cout<<"Nhap vao gioi tinh:";getline(cin,gioitinh);fflush(stdin);
	cout<<"Nhap vao nam sinh:";cin>>nam;
}

void NGUOI::Xuat(){
	cout<<"Ho va ten:"<<hoten<<endl;
	cout<<"Gioi tinh:"<<gioitinh<<endl;
	cout<<"Nam sinh:"<<nam<<endl;
	cout<<"Tuoi:"<<tinhtuoi()<<endl;
}
int NGUOI::getnam(){
	return this->nam;
}
int NGUOI::tinhtuoi(){

	int tuoi;
	return tuoi=2020-getnam();
}

class NHANVIEN: public NGUOI{
	private:
		float HSThamnien;
		float Mucluong;
		float Anca;
	public:
		~NHANVIEN(){
			HSThamnien=0;
			Mucluong=0;
			Anca=0;
		}
		void Nhap();
		void Xuat();

		float getML();
		float getHST();
		float getAnca();
		float tinhluong();
};

float NHANVIEN::getHST(){
	return this->HSThamnien;
}

float NHANVIEN::getML(){
	return this->Mucluong;
}
float NHANVIEN::getAnca(){
	return this->Anca;
}

float NHANVIEN::tinhluong(){
	float luong;
	int b=tinhtuoi();
	float c=getML();
	float d=getHST();
	float e=getAnca();
	if(b>=60){
		return luong=0.75*c*d;
	}
	else{
		return luong=c*d+e;
	}
}

void NHANVIEN::Nhap(){
	NGUOI::Nhap();
	cout<<"Nhap va he so tham nien:";cin>>HSThamnien;fflush(stdin);
	cout<<"Nhap vao muc luong:";cin>>Mucluong;fflush(stdin);
	cout<<"Nhap vao tien an ca:";cin>>Anca;fflush(stdin);
}
void NHANVIEN::Xuat(){
	NGUOI::Xuat();
	cout<<"He so tham nien:"<<HSThamnien<<endl;
	cout<<"Muc luong:"<<Mucluong<<endl;
	cout<<"Tien an ca:"<<Anca<<endl;
	cout<<"Luong:"<<tinhluong()<<endl;

}

void NhapDS(NHANVIEN a[100], int &n){
	cout<<"Nhap so nhan vien can them:";cin>>n;fflush(stdin);
	for(int i=0;i<n;i++){
		cout<<"\nNhan vien thu:"<<i+1<<endl;
		a[i].Nhap();
	}
}

void XuatDS(NHANVIEN a[100], int n){
	for(int i=0;i<n;i++){
		cout<<"\nNhan vien thu:"<<i+1<<endl;
		a[i].Xuat();
	}
}

void Kiemtra(NHANVIEN a[100], int n){
	for(int i=0;i<n;i++){
	if(a[i].tinhtuoi()>=60){
				a[i].Xuat();
		}

	}
}
int main(){
	int n;
	NGUOI ng;
	NHANVIEN a[100];
	ng.Nhap();
	ng.tinhtuoi();
	ng.Xuat();
	NhapDS(a,n);
	cout<<"\nThong tin cac nhan vien vua nhap:"<<endl;
	XuatDS(a,n);
	cout<<"\nThong tin cac nhan vien den tuoi nghi huu:"<<endl;
	Kiemtra(a,n);



}
