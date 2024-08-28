#include<iomanip>
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
class Phuongtiengiaothong
{
	private:
		string hangsx;
		string ten;
		int nam;
		float vmax;
	public:
		Phuongtiengiaothong ()
		{
			hangsx = "";
			ten = "";
			nam = 0;
			vmax = 0;
		}
	void Nhap ();
	void Xuat ();
	float getvmax();
};
float Phuongtiengiaothong::getvmax() {
	return this->vmax;
}
void Phuongtiengiaothong::Nhap ()
{
	cout<<"Nhap hang san xuat:";
	fflush (stdin);
	getline (cin, hangsx);
	cout<<"Nhap ten nha san xuat:";
	fflush (stdin);
	getline (cin, ten);
	cout<<"Nhap nam san xuat:";
	cin>>nam;
	cout<<"van toc toi da:";
	cin>>vmax;
}

void Phuongtiengiaothong::Xuat ()
{
	cout<<"Hang san xuat:"<<hangsx<<endl;
	cout<<"Ten nha san xuat:"<<ten<<endl;
	cout<<"Nam san xuat:"<<nam<<endl;
	cout<<"Van toc toi da:"<<vmax<<endl;
}

class Oto: public Phuongtiengiaothong
{
	private:
		int socho;
		string dongco;
	public:
	float static sobanhxe;
	Oto ()
	{
		socho = 0;
		dongco = "";
	}
	~Oto ()
	{
		socho = 0;
		dongco = "";
	}
	void Nhap ();
	void Xuat ();
	float vantoccoso ();
	friend operator < (Oto a, Oto b);
};

float Oto::sobanhxe = 4;

void Oto::Nhap ()
{
	Phuongtiengiaothong::Nhap ();
	cout<<"Nhap vao so cho ngoi: ";
	cin>>socho;
	fflush (stdin);
	cout<<"Nhap vao kieu dong co: ";
	getline(cin, dongco);
}

void Oto::Xuat ()
{
	Phuongtiengiaothong::Xuat ();
		cout<<"So cho ngoi:"<<socho<<endl;
		cout<<"Kieu dong co:"<<dongco<<endl;	
}

float Oto::vantoccoso ()
{
	return getvmax()/sobanhxe ;
}

void Nhapds (Oto a[], int &n)
{
	cin>>n;
	for (int i=0; i<n; i++) 
	{
		a[i].Nhap ();
	}
}

void Xuatds (Oto a[], int n)
{
	for (int i=0; i<n; i++)
	{
		a[i].Xuat();
	}
}

void sapxep (Oto a[100], int n)
{
	Oto temp;
	for (int i=0; i<n-1; i++)
	{
		for (int j=n+1; j<n; j++)
		{
			if (a[i].vantoccoso() < a[j].vantoccoso())
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	Xuatds (a, n);
}

int main()
{
	Phuongtiengiaothong ptgt;
	ptgt.Nhap ();
	ptgt.Xuat ();
	Oto oto[100];
	int n;
	cout<<"\n Nhap thong tin cho n phuong tien: "<<endl;
	Nhapds (oto, n);
	cout<<"\n Thong tin vua nhap cho n phuong tien: "<<endl;
	Xuatds (oto, n);
	cout<<"\n Danh sach phuong tien o to sau khi sap xep: "<<endl;
	sapxep (oto, n);	
}	

