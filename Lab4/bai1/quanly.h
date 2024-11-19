#ifndef QUANLY_H
#define QUANLY_H
#include <bits/stdc++.h>
#include "nhanvien.h"
using namespace std;

class QuanLy : public NhanVien {
private:
    double tyLeThuong;
public:
    QuanLy(string ms, string t, double lcb, double tl) : NhanVien(ms, t, lcb), tyLeThuong(tl) {}

    double TienThuong() const override;

    void Xuat() const override;
};
#endif
