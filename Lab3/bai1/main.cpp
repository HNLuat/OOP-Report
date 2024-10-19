#include <bits/stdc++.h>
#include "phanso.h"
using namespace std;

int main() {
    PhanSo a,b;
    cin>>a>>b;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    cout<<"Tong: "<<a+b<<endl;
    cout<<"Hieu: "<<a-b<<endl;
    cout<<"Tich: "<<a*b<<endl;
    cout<<"Thuong: "<<"a/b"<<endl;
    cout<<"a lon hon b: "<<(a>b)<<endl;
    cout<<"a lon hon hoac bang b: "<<(a>=b)<<endl;
    cout<<"a be hon b: "<<(a<b)<<endl;
    cout<<"a be hon hoac bang b: "<<(a<=b)<<endl;
    cout<<"a bang b: "<<(a==b)<<endl;
    cout<<"a khac b: "<<(a!=b);
    return 0;
}
