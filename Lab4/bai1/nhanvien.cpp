#include <bits/stdc++.h>
#include "nhanvien.h"
using namespace std;

void NhanVien::Xuat() const {
    cout << "Ma so: " << maSo << endl;
    cout << "Ten: " << ten << endl;
    cout << "Luong co ban: " << luongCoBan << endl;
    cout << "Tien thuong: " << TienThuong() << endl;
}
