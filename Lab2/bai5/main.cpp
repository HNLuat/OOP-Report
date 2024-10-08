#include <bits/stdc++.h>
#include "Diem.h"
using namespace std;

int main()
{
    Diem A;
    A.Nhap();
    int n, x;
    cout<<"Nhap so luong chi thi: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Nhap chi thi: ";
        cin>>x;
        if(x==1){
            A.SetHoanhDo(A.GetHoanhDo()*2);
            A.SetTungDo(A.GetTungDo()*2);
        }
        if(x==2){
            A.SetHoanhDo(0);
            A.SetTungDo(0);
        }
        if(x==3){
            int k, d;
            cin>>k>>d;
            if(k==0)
                A.TinhTien(d, 0);
            else A.TinhTien(0, d);
        }
    }
    A.Xuat();
}
