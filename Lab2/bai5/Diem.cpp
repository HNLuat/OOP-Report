#include <bits/stdc++.h>
#include "Diem.h"
using namespace std;

void Diem::Xuat(){
    cout<<"("<<iHoanh<<","<<iTung<<")";
}
void Diem::Nhap(){
    cout<<"Nhap toa do x, y: ";
    cin>>iHoanh>>iTung;
}
int Diem::GetHoanhDo() const {return iHoanh;}
int Diem::GetTungDo() const {return iTung;}
void Diem::SetTungDo(int Tung) {iTung = Tung;}
void Diem::SetHoanhDo(int Hoanh) {iHoanh = Hoanh;}
void Diem::TinhTien(int dx, int dy){
    iHoanh += dx;
    iTung += dy;
}
