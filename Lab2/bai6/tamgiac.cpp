#include <bits/stdc++.h>
#include "tamgiac.h"
using namespace std;

void TamGiac::Nhap(){
    cout<<"Nhap toa do 3 dinh: ";
    cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy;
}
void TamGiac::Xuat(){
    cout<<"("<<Ax<<", "<<Ay<<")\n("<<Bx<<" "<<By<<")\n("<<Cx<<" "<<Cy<<")\n";
}
void TamGiac::TinhTien(float x, float y){
    Ax += x; Bx += x; Cx += x;
    Ay += y; By += y; Cy += y;
}
