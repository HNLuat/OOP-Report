#include <bits/stdc++.h>
#include "kysu.h"
#include "nhanvien.h"
using namespace std;

double KySu::TienThuong() const {
    return soGioLamThem * 100000;
}
void KySu::Xuat() const {
    cout << "Ky su: " << endl;
    NhanVien::Xuat();
}
