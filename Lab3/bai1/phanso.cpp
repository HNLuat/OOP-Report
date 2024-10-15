#include<bits/stdc++.h>
#include "phanso.h"
using namespace std;

PhanSo::PhanSo(int Tu, int Mau){
    iTu = Tu;
    iMau = Mau;
    Rutgon();
}
PhanSo PhanSo::operator+(const PhanSo ps) const {
    return PhanSo(iTu*ps.iMau + iMau*ps.iTu, iMau * ps.iMau);
}
PhanSo PhanSo::operator-(const PhanSo ps) const {
    return PhanSo(iTu*ps.iMau - iMau*ps.iTu, iMau * ps.iMau);
}
PhanSo PhanSo::operator*(const PhanSo ps) const {
    return PhanSo(iTu*ps.iTu, iMau*ps.iMau);
}
PhanSo PhanSo::operator/(const PhanSo ps) const {
    return PhanSo(iTu*ps.iMau, iMau*ps.iTu);
}
bool PhanSo::operator==(const PhanSo ps) const {
    return iTu == ps.iTu && iMau == ps.iMau;
}
bool PhanSo::operator!=(const PhanSo ps) const {
    return iTu != ps.iTu || iMau != ps.iMau;
}
bool PhanSo::operator<(const PhanSo ps) const {
    return iTu * ps.iMau < ps.iTu * iMau;
}
bool PhanSo::operator>(const PhanSo ps) const {
    return iTu * ps.iMau > ps.iTu * iMau;
}
bool PhanSo::operator<=(const PhanSo ps) const {
    return iTu * ps.iMau <= ps.iTu * iMau;
}
bool PhanSo::operator>=(const PhanSo ps) const {
    return iTu * ps.iMau >= ps.iTu * iMau;
}
istream& operator>>(istream& is, PhanSo& ps){
    is >> ps.iTu >> ps.iMau;
    ps.Rutgon();
    return is;
}
ostream& operator<<(ostream& os, const PhanSo& ps) {
    os << ps.iTu << "/" << ps.iMau;
    return os;
}
