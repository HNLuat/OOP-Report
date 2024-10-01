#include <bits/stdc++.h>
#include "Fraction.h"
using namespace std;

Fraction::Fraction() : numerator(0), denominator(1){}
Fraction::Fraction(int numer, int denom) : numerator(numer), denominator(denom){}
void Fraction::Enter(){
    cout<<"Nhap tu phan so: ";
    cin>>numerator;
    cout<<"Nhap mau phan so: ";
    cin>>denominator;
    while(denominator==0){
        cout<<"Mau so khong hop le, vui long nhap lai: ";
        cin>>denominator;
    }
}
void Fraction::Print(){
    cout<<numerator<<"/"<<denominator;
}
