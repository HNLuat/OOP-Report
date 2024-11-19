#include <bits/stdc++.h>
#include "quanly.h"
#include "nhanvien.h"
using namespace std;

double QuanLy::TienThuong() const {
    return luongCoBan * tyLeThuong;
}
void QuanLy::Xuat() const {
    cout << "Quan ly: " << endl;
    NhanVien::Xuat();
}
