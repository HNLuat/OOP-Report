#include<bits/stdc++.h>
#include "ngaythangnam.h"
using namespace std;

const int NgayThangNam::ngaytrongthang[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void NgayThangNam::TinhLaiNgay(int d){
    nam = d / 365;
    d -= nam*365;
    for(int i=1;i<=12;i++){
        if(d - ngaytrongthang[i] > 0) d -=ngaytrongthang[i];
        else {
            thang = i;
            break;
        }
    }
    ngay = d;
}
int NgayThangNam::TinhNgay() const {
    int ans = nam * 365;
    for(int i=1;i<thang;i++) ans += ngaytrongthang[i];
    return ans + ngay;
}
NgayThangNam NgayThangNam::operator+(int d) {
    NgayThangNam result;
    result.TinhLaiNgay(this->TinhNgay() + d);
    return result;
}
NgayThangNam NgayThangNam::operator-(int d) {
    NgayThangNam result;
    result.TinhLaiNgay(this->TinhNgay() - d);
    return result;
}
NgayThangNam NgayThangNam::operator+(const NgayThangNam date){
    NgayThangNam result;
    result.TinhLaiNgay(this->TinhNgay() + date.TinhNgay());
    return result;
}
NgayThangNam NgayThangNam::operator-(const NgayThangNam date){
    NgayThangNam result;
    result.TinhLaiNgay(this->TinhNgay() - date.TinhNgay());
    return result;
}
NgayThangNam& NgayThangNam::operator++(){
    return *this = *this + 1;
}
NgayThangNam NgayThangNam::operator++(int){
    NgayThangNam temp = *this;
    *this = *this + 1;
    return temp;
}
NgayThangNam& NgayThangNam::operator--(){
    return *this = *this - 1;
}
NgayThangNam NgayThangNam::operator--(int){
    NgayThangNam temp = *this;
    *this = *this - 1;
    return temp;
}
bool NgayThangNam::operator==(const NgayThangNam date) const {
    return this->TinhNgay() == date.TinhNgay();
}
bool NgayThangNam::operator!=(const NgayThangNam date) const {
    return this->TinhNgay() != date.TinhNgay();
}
bool NgayThangNam::operator<(const NgayThangNam date) const {
    return this->TinhNgay() < date.TinhNgay();
}
bool NgayThangNam::operator>(const NgayThangNam date) const {
    return this->TinhNgay() > date.TinhNgay();
}
bool NgayThangNam::operator<=(const NgayThangNam date) const {
    return this->TinhNgay() <= date.TinhNgay();
}
bool NgayThangNam::operator>=(const NgayThangNam date) const {
    return this->TinhNgay() >= date.TinhNgay();
}
istream& operator>>(istream &is, NgayThangNam& date){
    is >> date.ngay>> date.thang >> date.nam;
    return is;
}
ostream& operator<<(ostream &os, const NgayThangNam date){
    os <<"ngay "<< date.ngay << " thang " << date.thang << " nam "<< date.nam;
    return os;
}
