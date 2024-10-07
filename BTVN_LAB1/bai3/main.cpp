#include <bits/stdc++.h>
#include "Fraction.h"
using namespace std;
int n, min_length = 9999;
int x[30], ans[30];
Fraction Dich;
vector<Fraction> vec_frac;
void GO(int i){
    if(i==n+1){
        Fraction Tich(1,1);
        int active_length = 0;
        for(int j=1;j<=n;j++)
            if(x[j]==1) Tich = Tich*vec_frac[j-1], active_length ++;
        if(Dich == Tich){
            if(active_length < min_length){
                for(int j=0;j<=n;j++)
                    ans[j] = x[j];
                min_length = active_length;
            }
        }
        return ;
    }
    for(int j=0;j<=1;j++){
        x[i] = j;
        GO(i+1);
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        Fraction b;
        b.Enter();
        vec_frac.push_back(b);
    }
    cout<<"Nhap phan so dich: ";
    Dich.Enter();
    GO(1);
    if(min_length == 9999){
        cout<<"Khong tim thay";
        return 0;
    }
    vector<Fraction> frac_ans;
    for(int i=1;i<=n;i++)
        if(ans[i]==1)
            frac_ans.push_back(vec_frac[i-1]);
    sort(frac_ans.begin(), frac_ans.end());
    for(Fraction v: frac_ans){
        v.Print();
        cout<<endl;
    }
    return 0;
}
