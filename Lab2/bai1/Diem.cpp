#include <bits/stdc++.h>
#include "Diem.h"
using namespace std;

Diem::Diem() : iHoanh(0), iTung(0) {}
Diem::Diem(float Hoanh, float Tung) : iHoanh(Hoanh), iTung(Tung) {}
Diem::Diem(const Diem& A) : iHoanh(A.iHoanh), iTung(A.iTung) {}
void Diem::Xuat(){
    cout<<"Toa do x = "<<iHoanh<<", toa do y = "<<iTung;
}
float Diem::GetHoanhDo() const {return iHoanh;}
float Diem::GetTungDo() const {return iTung;}
void Diem::SetTungDo(float Tung) {iTung = Tung;}
void Diem::SetHoanhDo(float Hoanh) {iHoanh = Hoanh;}
void Diem::TinhTien(float dx, float dy){
    iHoanh += dx;
    iTung += dy;
}
