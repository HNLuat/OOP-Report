#include <bits/stdc++.h>
#include "Fraction.h"
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    Fraction kMin(INT_MAX, 1);
    Fraction kMax(0, 1);
    vector<Fraction> vec_frac;
    for(int i=1;i<=n;i++){
        Fraction b;
        b.Enter();
        vec_frac.push_back(b);
    }
    if(k>n) return 0;
    sort(vec_frac.begin(), vec_frac.end());
    //So lon thu k la so tai vi tri n-k trong day tang dan
    vec_frac[n-k].Print();
    cout<<"\n";
    //So be thu k la so tai vi tri k-1 trong day tang dan
    vec_frac[k-1].Print();
    return 0;
}
