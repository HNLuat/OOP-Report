#include <bits/stdc++.h>
using namespace std;

struct phanso{
    int tu, mau;
};
// Kiem tra xem phan so nao lon hon trong 2 phan so
phanso phansolonhon(phanso a, phanso b){
    long c = 1L * a.tu * b.mau;
    long d = 1L * a.mau * b.tu;
    if (c > d) return a;
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
