#include <bits/stdc++.h>
#include "ngaythangnam.h"
using namespace std;
int main()
{
    NgayThangNam a;
    cin>>a;
    cout<<"a++: "<<a++<<endl;
    cout<<"++a: "<<++a<<endl;
    cout<<"a--: "<<a--<<endl;
    cout<<"--a: "<<--a<<endl;
    NgayThangNam b;
    cin>>b;
    cout<<"a = "<<a<<", b = "<<b<<endl;
    cout<<"Tong: "<<a+b<<endl;
    cout<<"Hieu: "<<a-b<<endl;
    cout<<"a + 100 = "<<a+100<<endl;
    cout<<"b - 100 = "<<b-100<<endl;
    cout<<"a lon hon b: "<<(a>b)<<endl;
    cout<<"a lon hon hoac bang b: "<<(a>=b)<<endl;
    cout<<"a be hon b: "<<(a<b)<<endl;
    cout<<"a be hon hoac bang b: "<<(a<=b)<<endl;
    cout<<"a bang b: "<<(a==b)<<endl;
    cout<<"a khac b: "<<(a!=b);
    return 0;
}
