#include <cmath>
#include<iostream>
#include<iomanip>
#include<time.h>
#include<cstring>
#include<fstream>
#include<cstdlib>
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
void nhapChienDichThuCong(chien_dich a[], int &n);
void menu_thaotac(chien_dich a[], int n);
void xuatDanhsach(chien_dich a[], int n);
void tinhTongSLThanhVien(chien_dich a[], int n);
void DanhSachChienDichNhieuThanhVien(chien_dich a[], int n);
void kiemtradanhsachtangdan(chien_dich a[],int n);
void sapXepGiamDan_SoNgay(chien_dich a[], int n);
void timKiemChienDich(chien_dich a[],int n);
void chienDich5_10Ngay(chien_dich a[], int n);
int main()
{
    chien_dich cd[100];
    int soChienDich=0;
    string myText;
    menu_thaotac(cd, soChienDich);
    return 0;
}
void menu_thaotac(chien_dich a[], int n){
    int choice;
    do
    {
        cout<<"\tMENU\n============================\nChon Chuc Nang Can Thuc Hien:\n0. Ket Thuc.\n1. Nhap Danh Sach Chien Dich Thu Cong.\n2. Nhap Danh Sach Chien Dich Tu File Text.\n3. Xuat Danh Sach Chien Dich.\n4. Tinh Tong So Tinh Nguyen Vien Tham Gia."<<endl;
        cout<<"5. In Danh Sach 5 Chien Dich Co So Tinh Nguyen Vien Cao Nhat.\n6. Kiem Tra Danh Sach Cac Chien Dich Co Duoc Sap Xep Tang Dan Theo So Ngay Dien Ra.\n7. Sap Xep Danh Sach Giam Dan Theo So Ngay Dien Ra.\n8. \n9. \n10. Tim Chien Dich Bang Ten.\n11. Hien Thi Tat Ca Chien Dich Keo Dai 5 Den 10 Ngay"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            nhapChienDichThuCong(a, n);//Nguyễn Thiên Phúc
            break;
        case 2: 
            nhapChienDichFILE(a,n);
            break;
        case 3: 
            xuatDanhsach(a, n);//Nguyễn Thiên Phúc
            break;
        case 4:
            tinhTongSLThanhVien(a,n);//Nguyễn Thiên Phúc
            break;
        case 5:
            DanhSachChienDichNhieuThanhVien(a,n);//Nguyễn Thiên Phúc
            break;
        case 6:
            kiemtradanhsachtangdan(a,n);//Nguyễn Thiên Phúc
            break;
        case 7:
            sapXepGiamDan_SoNgay(a,n);//Nguyễn Thiên Phúc
            break;
        case 10:
            timKiemChienDich(a,n);
            break;
        case 11:
            chienDich5_10Ngay(a,n);
            break;
        default:
            cout<<"Chuc Nang Khong Hop Le! Vui Long Nhap Lai! "<<endl;
            break;
        }
    } while (choice!=0);
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
}void nhapChienDichThuCong(chien_dich a[], int &n)
{ 
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
void nhapChienDichFILE(chien_dich a[], int &n)
{    
    fflush(stdin);
    ifstream filegoc("chien_dich.txt", ios::in);
    filegoc>>setw(5)>>n;
    if (filegoc.fail())
    {
        cout<<"Nhap du lieu that bai do khong mo duoc file!"<<endl;
    }
    else{
        cout<<"Nhap Du Lieu Tu File Text Thanh Cong!"<<endl;
    }
    
    for (int i = 0; i < n; i++)
    {
        filegoc>>setw(10)>>a[i].ma_chiendich;
        filegoc>>setw(20)>>a[i].ten_chiendich;
        filegoc>>setw(10)>>a[i].ngay_dienra;
        filegoc>>setw(10)>>a[i].SL_thanhvien;
    }
    
    filegoc.close();
   
}

void xuatDanhsach(chien_dich a[], int n)
{
    cout<<"Id Chien Dich "<<setw(20)<<"Ten Chien Dich "<<setw(30)<<"So Luong Tinh Nguyen Vien"<<setw(20)<<"So Ngay Dien Ra"<<setw(20)<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<left<<a[i].ma_chiendich<<setw(20)<<a[i].ten_chiendich<<setw(30)<<a[i].SL_thanhvien<<setw(20)<<a[i].ngay_dienra<<setw(20)<<endl;
    }

}
void tinhTongSLThanhVien(chien_dich a[],int n)
{
    int TongTV=0;
    for (int i = 0; i < n; i++)
    {
        TongTV+=a[i].SL_thanhvien;
    }
    cout<<"Tong Tinh Nguyen Vien Tham Gia Cac Chien Dich La: "<<TongTV<<endl;
}
#define SWAP(type,x,y) do{type tmp = x; x = y; y = tmp;}while(0)
void DanhSachChienDichNhieuThanhVien(chien_dich a[], int n)
{
    chien_dich b[100];
    for (int i = 0; i < n; i++)
    {
        b[i]=a[i];
    }
     for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {

            if (b[i].SL_thanhvien < b[j].SL_thanhvien) 
            {
                SWAP(chien_dich , b[i] ,b[j]); 
            }
        }
    }
    int xephang = 5;
    cout<<"Danh Sach 5 chien dich co so tinh nguyen vien cao nhat la: "<<endl;
    xuatDanhsach(b,xephang);
}
bool kiemtraTangDan(chien_dich a[],int i)
{
        if (a[i].ngay_dienra>a[i+1].ngay_dienra)
        {
            return false;
        }
    return true;
}
void kiemtradanhsachtangdan(chien_dich a[],int n)
{
    int checked;
    for (int i = 0; i < n-1; i++)
    {
        if (kiemtraTangDan(a,i)==false)
        {
            checked = 0;
            break;
        }
        else
        {
            checked = 1;
        }
    }
    if (checked == 1)
    {
       cout<<"Danh sach cac chien dich duoc sap xep tang dan theo so ngay dien ra."<<endl;
    }
    else{
        cout<<"Danh sach cac chien dich khong duoc sap xep tang dan theo so ngay dien ra."<<endl;
    }
}
void sapXepGiamDan_SoNgay(chien_dich a[], int n)
{
    chien_dich c[100];
    for (int i = 0; i < n; i++)
    {
        c[i]=a[i];
    }
     for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {

            if (c[i].ngay_dienra < c[j].ngay_dienra) 
            {
                SWAP(chien_dich , c[i] ,c[j]); 
            }
        }
    }
    cout<<"Danh Sach Chien Dich Duoc Sap Xep Theo So Ngay Dien Ra Giam Dan: "<<endl;
    xuatDanhsach(c,n);
}
bool search (chien_dich a[], int n, string name);
void timKiemChienDich(chien_dich a[],int n)
{
    string name;
    int result = 0,found;
    cout<<"Nhap vao ten chien dich: "<<endl;
    rewind(stdin);
    getline(cin, name);
    for (int i = 0; i < n; i++)
    {
     if (search(a,i,name)==true)
     {
        result = 1;
        found= i;
        break;
     }
     else
     {
        result = 0;
     }
    }
      if (result==1)
       { 
            cout<<"Id Chien Dich "<<setw(20)<<"Ten Chien Dich "<<setw(30)<<"So Luong Tinh Nguyen Vien"<<setw(20)<<"So Ngay Dien Ra"<<setw(20)<<endl;
            cout<<left<<a[found].ma_chiendich<<setw(20)<<a[found].ten_chiendich<<setw(30)<<a[found].SL_thanhvien<<setw(20)<<a[found].ngay_dienra<<setw(20)<<endl;
            return;
       }
       else{
        cout<<"Khong tim thay ten chien dich nay!"<<endl;
        return;
       }
       
} 
bool search (chien_dich a[],int n, string name)
 {
    if (a[n].ten_chiendich==name)
   {
    return true;
   }
   else
   return false;
    
 }
 void chienDich5_10Ngay(chien_dich a[], int n)
 {
    chien_dich filter1[100];
    int neww=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i].ngay_dienra>=5&&a[i].ngay_dienra<=10)
        {
            filter1[neww]=a[i];
            neww++;
        }
        
    }
    cout<<"Nhung chien dich keo dai trong 5 den 10 ngay: "<<endl;
    xuatDanhsach(filter1, neww);
 }