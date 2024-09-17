#include <bits/stdc++.h>
using namespace std;

struct phanso{
    int tu, mau;
    void rutgon(){
        int temp = __gcd(tu, mau);
        tu /= temp;
        mau /= temp;
    }
};

int main() {
    phanso a;
    cin>>a.tu>>a.mau;
    a.rutgon();
    cout<<a.tu<<" "<<a.mau;
    return 0;
}
