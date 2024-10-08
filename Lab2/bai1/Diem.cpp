#include <bits/stdc++.h>
#include "Diem.h"
using namespace std;

Diem::Diem() : iHoanh(0), iTung(0) {}
Diem::Diem(float Hoanh, float Tung) : iHoanh(Hoanh), iTung(Tung) {}
Diem::Diem(const Diem& A) : iHoanh(A.iHoanh), iTung(A.iTung) {}
void Diem::Xuat(){
    cout<<"Toa do x = "<<iHoanh<<", toa do y = "<<iTung;
}
int Diem::GetHoanhDo() const {return iHoanh;}
int Diem::GetTungDo() const {return iTung;}
void Diem::SetTungDo(int Tung) {iTung = Tung;}
void Diem::SetHoanhDo(int Hoanh) {iHoanh = Hoanh;}
void Diem::TinhTien(int dx, int dy){
    iHoanh += dx;
    iTung += dy;
}
