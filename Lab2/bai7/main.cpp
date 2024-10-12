#include <bits/stdc++.h>
using namespace std;

class Diem{
private:
    float iHoanh, iTung;
public:
    Diem(int x, int y) : iHoanh(x), iTung(y) {}
    Diem() : iHoanh(0), iTung(0) {}
    void Nhap(){
        cout<<"Nhap toa do x, y: ";
        cin>>iHoanh>>iTung;
    }
    float getx(){return iHoanh;}
    float gety(){return iTung;}
    friend float calc_angle(Diem A, Diem Tam);
};
float calc_angle(Diem A, Diem Tam){
    return atan2(A.iTung - Tam.iTung, A.iHoanh - Tam.iHoanh);
}
class DaGiac{
private:
    int so_dinh;
    vector<Diem> Dinh;
public:
    void Nhap(){
        cin>>so_dinh;
        for(int i=1;i<=so_dinh;i++){
            Diem a;
            a.Nhap();
            Dinh.push_back(a);
        }
        sapxep();
    }
    void sapxep(){
        Diem Tam = TinhTam();
        sort(Dinh.begin(), Dinh.end(), [Tam](Diem a, Diem b){
            return calc_angle(a, Tam) < calc_angle(b, Tam);
        });
    }
    Diem TinhTam(){
        int cx = 0, cy = 0;
        for(Diem i:Dinh){
            cx+=i.getx();
            cy+=i.gety();
        }
        return Diem(cx/so_dinh, cy/so_dinh);
    }
    float dientich(){
        float dt = 0;
        for(int i=0;i<so_dinh;i++){
            int next = (i+1)%so_dinh;
            dt += Dinh[i].getx()*Dinh[next].gety() - Dinh[i].gety()*Dinh[next].getx();
        }
        return abs(dt)/2;
    }
};

int main()
{
    DaGiac A;
    A.Nhap();
    cout<<A.dientich();
    return 0;
}
