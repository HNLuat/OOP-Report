#include <bits/stdc++.h>
#include "TamGiac.h"
using namespace std;

void tamgiac::Nhap(){
    cout<<"Nhap toa do 3 dinh: ";
    cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy;
}
void tamgiac::Xuat(){
    cout<<"Tam giac co toa do 3 dinh: ("<<Ax<<", "<<Ay<<"), ("<<Bx<<" "<<By<<"), ("<<Cx<<" "<<Cy<<")\n";
}
void tamgiac::TinhTien(int x, int y){
    Ax += x; Bx += x; Cx += x;
    Ay += y; By += y; Cy += y;
    cout<<"Da tinh tien";
}
