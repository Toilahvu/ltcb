#include <cmath>
#include<iostream>
#include<iomanip>
#include<time.h>
#include<cstring>
#include<fstream>
using namespace std;
struct chien_dich
{
    char ma_chiendich[10];
    char ten_chiendich[20];
    int ngay_dienra;
    int SL_thanhvien;
};
//khai bao cac ham con 
void nhapThongTinChienDich(chien_dich &x);
void nhapChienDichFILE(chien_dich a[], int &n);
void nhapChienDichThuCong(chien_dich a[]);
void menu_thaotac(chien_dich a[], int n);
void xuatDanhsach(chien_dich a[]);
void tinhTongSLThanhVien(chien_dich a[]);
int main()
{
    chien_dich cd[100];
    int soChienDich;
    string myText;
    menu_thaotac(cd, soChienDich);
    return 0;
}
void nhapThongTinChienDich(chien_dich &x)
{
    cout<<"Nhap ma cua chien dich: ";
    rewind(stdin);
    cin.getline(x.ma_chiendich,10);

    cout<<"Nhap ten cua chien dich: ";
    cin.getline(x.ten_chiendich,20);

    cout<<"Nhap so ngay dien ra chien dich: ";
    cin>>x.ngay_dienra;

    cout<<"Nhap so luong tinh nguyen vien tham du: ";
    cin>>x.SL_thanhvien;
}
void nhapChienDichFILE(chien_dich a[], int &n)
{    
    ifstream ifs("chien_dich.txt", ios::in);
    ifs.close();
    do
    {
        cout<<"Nhap so luong chien dich: ";
        cin>>n;
    }while(n<=0);

    for(int i=0; i<n; i++)
    {
        cout<<"Nhap gia tri cua chien dich thu "<<i+1<<":"<<endl;
        nhapThongTinChienDich(a[i]);
    }
}
void menu_thaotac(chien_dich a[], int n){
int choice;
   
    do
    {
        cout<<"\tMENU\n============================\nChon Chuc Nang Can Thuc Hien:\n0. Ket Thuc.\n1. Nhap Danh Sach Chien Dich Thu Cong.\n2. Nhap Danh Sach Chien Dich Tu File Text.\n3. Xuat Danh Sach Chien Dich.\n4. Tinh Tong So Tinh Nguyen Vien Tham Gia."<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            nhapChienDichThuCong(a);
            break;
        case 2: 
            nhapChienDichFILE(a,n);
            break;
        case 3: 
            xuatDanhsach(a);
            break;
        case 4:
            tinhTongSLThanhVien(a);
            break;
        default:
            break;
        }
    } while (choice!=0);
}
void nhapChienDichThuCong(chien_dich a[])
{
    int cont,o;
    o=0;
    do
    {
    cout<<"Nhap ma chien dich: ";
    cin>>a[o].ma_chiendich;
    cout<<"Nhap ten chien dich: ";
    cin>>a[o].ten_chiendich;
    cout<<"Nhap so luong thanh vien tham gia: ";
    cin>>a[o].SL_thanhvien;
    cout<<"Nhap so ngay dien ra chien dich: ";
    cin>>a[o].ngay_dienra;
    cout<<"Tiep Tuc: 1 , Thoat: 0 ."<<endl;
    cin>>cont;
    o++;
    } while (cont!=0);
    
}
void xuatDanhsach(chien_dich a[])
{
    cout<<"Id Chien Dich\t\t\tTen Chien Dich\t\t\tSo Luong Tinh Nguyen Vien\t\tSo Ngay Dien Ra"<<endl;
    for (int i = 0; i < 99; i++)
    {
        cout<<a[i].ma_chiendich<<"\t\t\t"<<a[i].ten_chiendich<<"\t\t\t"<<a[i].SL_thanhvien<<"\t\t"<<a[i].ngay_dienra<<endl;
    }

}
void tinhTongSLThanhVien(chien_dich a[])
{
    int TongTV=0;
    for (int i = 0; i < 99; i++)
    {
        TongTV+=a[i].SL_thanhvien;
    }
    cout<<"Tong Tinh Nguyen Vien Tham Gia Cac Chien Dich La: "<<TongTV;
}