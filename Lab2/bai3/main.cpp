#include <bits/stdc++.h>
using namespace std;

class Diem{
private:
    float iHoanh, iTung;
public:
    void Xuat(){
        cout<<"("<<iHoanh<<", "<<iTung<<")";
    }
    void Nhap(){
        cout<<"Nhap toa do x, y: ";
        cin>>iHoanh>>iTung;
    }
    void TinhTien(float dx, float dy){
        iHoanh += dx;
        iTung += dy;
    }
};
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
    }
    void Xuat(){
        cout<<"So dinh: "<<so_dinh<<"\n";
        cout<<"Cac dinh co toa do: ";
        for(Diem a:Dinh){
            a.Xuat();
            cout<<", ";
        }
    }
    void TinhTien(float x, float y){
        for(int i=0;i<so_dinh;i++){
            Dinh[i].TinhTien(x, y);
        }
    }
};

int main()
{
    DaGiac A;
    A.Nhap();
    A.TinhTien(1, 1);
    cout<<"Da tinh tien";
    A.Xuat();
    return 0;
}
