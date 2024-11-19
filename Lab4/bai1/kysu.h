#ifndef KYSU_H
#define KYSU_H
#include <bits/stdc++.h>
#include "nhanvien.h"
using namespace std;

class KySu : public NhanVien {
private:
    int soGioLamThem;
public:
    KySu(string ms, string t, double lcb, int sgl) : NhanVien(ms, t, lcb), soGioLamThem(sgl) {}

    double TienThuong() const override;

    void Xuat() const override;
};
#endif
