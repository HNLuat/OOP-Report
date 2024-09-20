#include <bits/stdc++.h>
using namespace std;
struct Fraction{
    int numerator, denominator;
    Fraction(int numer = 0, int denom = 1){
        numerator = numer;
        denominator = denom;
        Simplify();
    }
    void Simplify(){
        int gcd = __gcd(numerator, denominator);
        numerator = numerator/gcd;
        denominator = denominator/gcd;
    }
    Fraction operator + (const Fraction& a) const {
        int denom = denominator*a.denominator;
        int numer = numerator*a.denominator + a.numerator*denominator;
        return Fraction(numer, denom);
    }
    Fraction operator - (const Fraction& a) const {
        int denom = denominator*a.denominator;
        int numer = numerator*a.denominator - a.numerator*denominator;
        return Fraction(numer, denom);
    }
    Fraction operator * (const Fraction& a) const {
        int numer = numerator*a.numerator;
        int denom = denominator*a.denominator;
        return Fraction(numer, denom);
    }
    Fraction operator / (const Fraction& a) const {
        int numer = numerator*a.denominator;
        int denom = denominator*a.numerator;
        return Fraction(numer, denom);
    }
};
int main()
{
    Fraction a, b;
    cin>>a.numerator>>a.denominator>>b.numerator>>b.denominator;
    cout<<"tong 2 phan so: "<<(a+b).numerator<<" "<<(a+b).denominator;
    cout<<"\nhieu 2 phan so: "<< (a-b).numerator<<" "<<(a-b).denominator;
    cout<<"\ntich 2 phan so: "<< (a*b).numerator<<" "<<(a*b).denominator;
    cout<<"\nthuong 2 phan so: "<< (a/b).numerator<<" "<<(a/b).denominator;
    return 0;
}
