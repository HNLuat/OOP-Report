#include <bits/stdc++.h>
using namespace std;

class ThiSinh{
private:
    string ten, MSSV;
    float Toan, Van, Anh;
public:
    ThiSinh() : ten(""), MSSV(""), Toan(0), Van(0), Anh(0) {}
    ThiSinh(float T, float V, float A) : Toan(T), Van(V), Anh(A) {}
    void Nhap(){
        cout<<"Nhap ten sinh vien: ";
        cin.ignore();
        getline(cin, ten);
        cout<<"Nhap MSSV: ";
        cin>>MSSV;
        cout<<"Nhap diem toan, van, anh: ";
        cin>>Toan>>Van>>Anh;
    }
    void Xuat(){
        cout<<"Ten: "<<ten<<", MSSV: "<<MSSV<<", Toan: "<<Toan<<", Van: "<<Van<<", Anh: "<<Anh;
    }
    float TongDiem(){
        return Toan + Van + Anh;
    }
};

int main()
{
    vector<ThiSinh> DanhSach;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        ThiSinh a;
        a.Nhap();
        DanhSach.push_back(a);
    }
    ThiSinh MAX(0, 0, 0);
    cout<<"Danh sach thi sinh co tong diem lon hon 15:";
    for(ThiSinh ts:DanhSach){
        float tong = ts.TongDiem();
        if(tong >= 15){
            ts.Xuat();
            cout<<"\n";
        }
        if(tong > MAX.TongDiem()) MAX = ts;
    }
    cout<<"Thi sinh co diem cao nhat: ";
    MAX.Xuat();
    return 0;
}
