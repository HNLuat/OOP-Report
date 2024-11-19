#include <iostream>
#include <string>
#include "nhanvien.h"
#include "quanly.h"
#include "kysu.h"
using namespace std;

int main() {
    string maSoQL, tenQL;
    double luongCoBanQL, tyLeThuong;
    cout << "Nhap thong tin Quan ly:" << endl;
    cout << "Ma so: "; cin >> maSoQL;
    cout << "Ten: "; cin.ignore(); getline(cin, tenQL);
    cout << "Luong co ban: "; cin >> luongCoBanQL;
    cout << "Ty le thuong: "; cin >> tyLeThuong;
    QuanLy ql(maSoQL, tenQL, luongCoBanQL, tyLeThuong);

    string maSoKS, tenKS;
    double luongCoBanKS;
    int soGioLamThem;
    cout << "\nNhap thong tin Ky su:" << endl;
    cout << "Ma so: "; cin >> maSoKS;
    cout << "Ten: "; cin.ignore(); getline(cin, tenKS);
    cout << "Luong co ban: "; cin >> luongCoBanKS;
    cout << "So gio lam them: "; cin >> soGioLamThem;
    KySu ks(maSoKS, tenKS, luongCoBanKS, soGioLamThem);

    cout << "\nThong tin chi tiet cua Quan ly va Ky su:\n";
    ql.Xuat();
    cout << endl;
    ks.Xuat();

    return 0;
}

