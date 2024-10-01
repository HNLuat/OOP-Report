#include <bits/stdc++.h>
#include "Fraction.h"
using namespace std;
int main()
{
    int n;
    cout<<"Nhap so luong phan so: ";
    cin>>n;
    Fraction Min(INT_MAX, 1);
    Fraction Max(0, 1);
    for(int i=1;i<=n;i++){
        Fraction b;
        b.Enter();
        if(b < Min) Min = b;
        if(Max < b) Max = b;
    }
    cout<<"Phan so nho nhat: ";
    Min.Print();
    cout<<"\nPhan so lon nhat: ";
    Max.Print();
    return 0;
}
