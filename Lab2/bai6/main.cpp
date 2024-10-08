#include <bits/stdc++.h>
#include "tamgiac.h"
using namespace std;
float const Pi = 3.14;
int main()
{
    TamGiac A;
    A.Nhap();
    cout<<"Nhap goc tinh tien va do dai tinh tien: ";
    float goc, dai;
    cin>>goc>>dai;
    float TinhTienX = cos(goc*Pi/180)*dai;
    float TinhTienY = sin(goc*Pi/180)*dai;
    A.TinhTien(TinhTienX, TinhTienY);
    A.Xuat();
}
