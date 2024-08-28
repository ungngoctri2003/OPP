#include<iomanip>
#include<iostream>
using namespace std;

class NGUOI{
	private:
		int ma;
		string hoten;
	public: 
	NGUOI(){
		ma=0;
		hoten="";
	}
	~NGUOI(){
		ma=0;
		hoten="";
	}
	void Nhap();
	void Hienthi();
};

void NGUOI::Nhap(){
	cout<<"Nhap vao ma dinh danh:";cin>>ma;
	cout<<"Nhap vao ho va ten:";cin>>hoten;
}

void NGUOI::Hienthi(){
	cout<<"------------THONG TIN NHAN VIEN---------------"<<endl;
	cout<<"Ma dinh danh:"<<ma<<endl;
	cout<<"Ho va ten:"<<hoten<<endl;
}

class NHANVIEN: public NGUOI{
	friend Sapxep(NHANVIEN a[], int );
	private:
		int namsinh;
		int hesoluong;
		int phucap;
	public:
		NHANVIEN(){
			
		}
		~NHANVIEN(){
			
		}
	void Nhap();
	void Hienthi();
	int Tinhluong();
};

void NHANVIEN::Nhap(){
	cout<<"Nhap vao nam sinh:";cin>>namsinh;
		cout<<"Nhap vao he so luong:";cin>>hesoluong;
		cout<<"Nhap vao tien phu cap:";cin>>phucap;

}
int NHANVIEN::Tinhluong(){
	return hesoluong*1550+phucap;
}

void NHANVIEN::Hienthi(){
	cout<<"---------------THONG TIN NHAN VIEN--------------------"<<endl;
	cout<<"Nam sinh:"<<namsinh<<endl;
	cout<<"He so luong:"<<hesoluong<<endl;
	cout<<"Tien phu cap:"<<phucap<<endl;
	cout<<"Luong cua nhan vien la :"<<Tinhluong()<<endl;
}


void NhapDS(NHANVIEN a[], int &n){
	cout<<"Nhap vao n:";cin>>n;
	for(int i=0;i<n;i++){
		a[i].Nhap();
	}
}

void XuatDS(NHANVIEN a[], int n){
	for(int i=0;i<n;i++){
		a[i].Hienthi();
	}
}

void SapxepDS(NHANVIEN a[], int n){
	NHANVIEN temp;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++)
		{
			if(a[i].Tinhluong()>a[j].Tinhluong()){
				temp=a[i];
				a[j]=a[i];
				a[j]=temp;
			}
		}
	}
}
int main(){
	int n;
	NGUOI ng;
	ng.	Nhap();
	ng.	Hienthi();
	NHANVIEN nv[100];
	NhapDS(nv,n);
	SapxepDS(nv, n);
	XuatDS(nv,n);
	return 0;
}

