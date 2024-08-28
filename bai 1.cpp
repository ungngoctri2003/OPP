#include<iostream>
#include<iomanip>
using namespace std;
class SV {
	private:
		string masv;
		string hoten;
	public:
	SV(){
		masv="";
		hoten="";
	}
	~SV(){
		masv="";
		hoten="";
	}
	void Nhap();
	void Hienthi();
};

void SV::Nhap(){
	cout <<"Nhap ma sv: "; fflush(stdin); getline(cin, masv);
    cout <<"Nhap ho ten: "; fflush(stdin); getline(cin, hoten);
}

void SV::Hienthi(){
	cout<<"-----------THONG TIN SINH VIEN---------------"<<endl;
	cout<<"Ma sinh vien: "<<masv<<endl;
	cout<<"Ten sinh vien:"<<hoten<<endl;
}
//lop ke thua
class TMDT: public SV{
	friend void Sapxep(TMDT [], int );
		private:
			float diem;
		public:
		TMDT(){
				diem=0;
		}
		~TMDT(){
		}
		void Nhap();
		void Hienthi();
};

void TMDT::Nhap(){
	SV::Nhap();
	cout<<"Nhap vao diem:";cin>>diem;
}

void TMDT::Hienthi(){
	SV::Hienthi();
	cout<<"Diem:"<<diem<<endl;
}

void NhapDS (TMDT a[], int &n){
	cout<<"Nhap n:";cin>>n;
	for(int i=0;i<n;i++){
		a[i].Nhap();
	}
}

void HienthiDS(TMDT a[], int n){
	for(int i=0;i<n;i++){
		a[i].Hienthi();
	}
}

	void Sapxep(TMDT a[], int n) {
		TMDT temp;
		for(int i=0;i<n-1;i++) {
			for(int j=i+1;j<n;j++) {
				if(a[i].diem<a[j].diem) {
					temp = a[i];
					a[i]= a[j];
					a[j] = temp;
				}
			}
		}
	}
int main(){
	int n;
	TMDT tmdt[100];
	SV sv;
	sv.Nhap();
	sv.Hienthi();
	NhapDS(tmdt,n);
	Sapxep(tmdt,n);
	HienthiDS(tmdt,n);
}
