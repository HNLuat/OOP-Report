#include<bits/stdc++.h>
#include "thoigian.h"
using namespace std;
void ThoiGian::TinhLaiGio(int s){
    gio = s/3600;
    s %= 3600;
    phut = s/60;
    s %=60;
    giay = s;
}
int ThoiGian::TinhGiay() const {
    return gio*3600 + phut*60 + giay;
}
ThoiGian ThoiGian::operator+(int s) {
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() + s);
    return result;
}
ThoiGian ThoiGian::operator-(int s) {
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() - s);
    return result;
}
ThoiGian ThoiGian::operator+(const ThoiGian tg){
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() + tg.TinhGiay());
    return result;
}
ThoiGian ThoiGian::operator-(const ThoiGian tg){
    ThoiGian result;
    result.TinhLaiGio(this->TinhGiay() - tg.TinhGiay());
    return result;
}
ThoiGian& ThoiGian::operator++(){
    return *this = *this + 1;
}
ThoiGian ThoiGian::operator++(int){
    ThoiGian temp = *this;
    *this = *this + 1;
    return temp;
}
ThoiGian& ThoiGian::operator--(){
    return *this = *this - 1;
}
ThoiGian ThoiGian::operator--(int){
    ThoiGian temp = *this;
    *this = *this - 1;
    return temp;
}
bool ThoiGian::operator==(const ThoiGian tg) const {
    return this->TinhGiay() == tg.TinhGiay();
}
bool ThoiGian::operator!=(const ThoiGian tg) const {
    return this->TinhGiay() != tg.TinhGiay();
}
bool ThoiGian::operator<(const ThoiGian tg) const {
    return this->TinhGiay() < tg.TinhGiay();
}
bool ThoiGian::operator>(const ThoiGian tg) const {
    return this->TinhGiay() > tg.TinhGiay();
}
bool ThoiGian::operator<=(const ThoiGian tg) const {
    return this->TinhGiay() <= tg.TinhGiay();
}
bool ThoiGian::operator>=(const ThoiGian tg) const {
    return this->TinhGiay() >= tg.TinhGiay();
}
istream& operator>>(istream &is, ThoiGian& tg){
    is >> tg.gio >> tg.phut >> tg.giay;
    return is;
}
ostream& operator<<(ostream &os, const ThoiGian tg){
    os << tg.gio << "h " << tg.phut << "m "<< tg.giay << "s";
    return os;
}
