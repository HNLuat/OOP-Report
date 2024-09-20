#include <bits/stdc++.h>
using namespace std;

double approximated_sin(double x){
    double const pi = 3.1415926535897932;
    int temp = int(x/pi);
    if(temp%2 == 0)
        x = x - temp*pi;
    else x = x - (temp+1)*pi;
    double sum = x;
    long long fac = 1;
    for(int i=1; i<=7; i++){
        int sign = 1;
        if(i%2 == 1) sign = -1;
        fac *= (2*i)*(2*i+1);
        sum += sign*pow(x, (2*i + 1))/fac;
    }
    return sum;
}

int main() {
    double x;
    cin>>x;
    cout<<approximated_sin(x);
    return 0;
}
