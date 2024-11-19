#ifndef NHANVIEN_H
#define NHANVIEN_H
#include <bits/stdc++.h>
using namespace std;

class NhanVien {
protected:
    string maSo;
    string ten;
    double luongCoBan;
public:
    NhanVien(string ms = "", string t = "", double lcb = 0) : maSo(ms), ten(t), luongCoBan(lcb) {}

    virtual double TienThuong() const = 0;

    virtual void Xuat() const;
};
#endif
