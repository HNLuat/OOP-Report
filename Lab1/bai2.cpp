#include <bits/stdc++.h>
using namespace std;

struct phanso{
    int tu, mau;
};
phanso phansolonhon(phanso a, phanso b){
    long temp1 = 1L * a.tu * b.mau;
    long temp2 = 1L * a.mau * b.tu;
    if (temp1 > temp2) return a;
    else return b;
}
int main()
{
    phanso a;
    cin>>a.tu>>a.mau;
    phanso b;
    cin>>b.tu>>b.mau;
    phanso temp = phansolonhon(a, b);
    cout<<temp.tu<<" "<<temp.mau;
    return 0;
}
