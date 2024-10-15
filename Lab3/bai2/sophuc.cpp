#include <bits/stdc++.h>
#include "sophuc.h"
using namespace std;

SoPhuc SoPhuc::operator+(const SoPhuc sp) const {
    return SoPhuc(Thuc + sp.Thuc, Ao + sp.Ao);
}
SoPhuc SoPhuc::operator-(const SoPhuc sp) const {
    return SoPhuc(Thuc - sp.Thuc, Ao - sp.Ao);
}
SoPhuc SoPhuc::operator*(const SoPhuc sp) const {
    double thuc = Thuc * sp.Thuc - Ao * sp.Ao;
    double ao = Thuc * sp.Ao + Ao * sp.Thuc;
    return SoPhuc(thuc, ao);
}
SoPhuc SoPhuc::operator/(const SoPhuc sp) const {
    double mau = sp.Thuc * sp.Thuc + sp.Ao * sp.Ao;
    double thuc = (Thuc * sp.Thuc + Ao * sp.Ao) / mau;
    double ao = (Ao * sp.Thuc - Thuc * sp.Ao) / mau;
    return SoPhuc(thuc, ao);
}
bool SoPhuc::operator==(const SoPhuc sp) const {
    return Thuc == sp.Thuc && Ao == sp.Ao;
}
bool SoPhuc::operator!=(const SoPhuc sp) const {
    return Thuc != sp.Thuc || Ao != sp.Ao;
}
istream& operator>>(istream& is, SoPhuc& sp) {
    is >> sp.Thuc >> sp.Ao;
    return is;
}
ostream& operator<<(ostream& os, const SoPhuc sp) {
    os << sp.Thuc;
    if(sp.Ao < 0){
        os << "-" << -sp.Ao;
    }
    else {
        os << "+" << sp.Ao;
    }
    os << "i";
    return os;
}
