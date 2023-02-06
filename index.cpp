#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
//khai bao cau truc cua chien dich
struct chien_dich
{
    char ma_chiendich[10];
    char ten_chiendich[20];
    int ngay_dienra;
    int SL_thanhvien;
};
//khai bao cac ham con 
void nhapThongTinChienDich(chien_dich &x);
void nhapMangChienDich(chien_dich a[], int &n);

int main()
{
    chien_dich cd[100];
    int soChienDich;
    string myText;

    nhapMangChienDich(cd, soChienDich);

    ifstream ifs("chien_dich.txt", ios::in);//doc file text chien dich

    ifs.close();//dong file text chien_dich
    return 0;
}
//nhap gia tri cua chien dich
void nhapThongTinChienDich(chien_dich &x)
{
    cout<<"Nhap ma cua chien dich: ";
    rewind(stdin);
    cin.getline(x.ma_chiendich,10);

    cout<<"Nhap ten cua chien dich: ";
    cin.getline(x.ten_chiendich,20);

    cout<<"Nhap ngay dien ra chien dich: ";
    cin>>x.ngay_dienra;

    cout<<"Nhap so luong tinh nguyen vien tham du: ";
    cin>>x.SL_thanhvien;
}
//nhap mot mang cac chien dich
void nhapMangChienDich(chien_dich a[], int &n)
{
    do
    {
        cout<<"Nhap so luong chien dich: ";
        cin>>n;
    }while(n<=0);

    for(int i=0; i<n; i++)
    {
        cout<<"\nNhap gia tri cua chien dich thu "<<i+1<<":"<<endl;
        nhapThongTinChienDich(a[i]);
    }
}

