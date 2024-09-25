#include <bits/stdc++.h>
using namespace std;
struct HocSinh{
    string ten;
    double toan, van, anh, diemtb;
    string phanloai;
    string tenmonhoc[3] = {"toan", "van", "anh"};
    // Nhap du lieu 1 hoc sinh
    void nhap(){
        cout<<"Nhap ho ten hoc sinh: ";
        cin.ignore();
        getline(cin, ten);
        while(!TenHopLe()){
            cout<<"Ho ten khong hop le, vui long nhap lai: ";
            getline(cin, ten);
        }
        for(int i=0;i<3;i++){
            cout<<"Nhap diem "<<tenmonhoc[i]<<": ";
            double diem = 0;
            cin>>diem;
            while(!DiemHopLe(diem)){
                cout<<"Diem "<<tenmonhoc[i]<<" khong hop le, vui long nhap lai: ";
                cin>>diem;
            }
            if(i==0) toan = diem;
            if(i==1) van = diem;
            if(i==2) anh = diem;
        }
        capnhatdiemtb();
        capnhatphanloai();
    }
    // Kiem tra dinh dang ten co hop le khong
    bool TenHopLe(){
        for(int i=0;i<ten.length();i++){
            if(ten[i] == ' ') continue;
            if(ten[i]<'A' || (ten[i]>'Z'&&ten[i]<'a') || ten[i]>'z')
                return false;
        }
        return true;
    }
    // Kiem tra diem co hop le khong
    bool DiemHopLe(double diem){
        return diem>=0&&diem<=10;
    }
    // ham cap nhat diem trung binh cua doi tuong
    void capnhatdiemtb(){
        diemtb = (2*toan + van + anh)/4;
    }
    // ham cap nhat phan loai cua doi tuong
    void capnhatphanloai(){
        if(diemtb>=9) phanloai = "Xuat sac";
        if(diemtb>=8&&diemtb<9) phanloai = "Gioi";
        if(diemtb>=6.5&&diemtb<8) phanloai = "Kha";
        if(diemtb>=5&&diemtb<6.5) phanloai = "Trung binh";
        if(diemtb<5) phanloai = "Yeu";
    }
};
// struct luu tru, quan li nhieu hoc sinh
struct NhieuHocSinh{
    vector<HocSinh> hocsinh;
    int soluong;
    // nhap du lieu cua nhieu hoc sinh
    void nhapdulieu(){
        cout<<"Nhap so luong hoc sinh: ";
        cin>>soluong;
        for(int i=0;i<soluong;i++){
            HocSinh a;
            a.nhap();
            hocsinh.push_back(a);
        }
    }
    // tim va in ra hoc sinh co diem trung binh cao nhat trong danh sach cac hoc sinh
    HocSinh diemtbcaonhat(){
        HocSinh HSDiemCaoNhat;
        HSDiemCaoNhat.diemtb = -1;
        for(HocSinh i:hocsinh)
            if(i.diemtb>HSDiemCaoNhat.diemtb)
                HSDiemCaoNhat=i;
        cout<<"Hoc sinh co diem trung binh cao nhat la:\n";
        cout<<"Ho ten: "<<HSDiemCaoNhat.ten<<"\n";
        cout<<"Diem trung binh: "<<HSDiemCaoNhat.diemtb<<"\n";
        cout<<"Diem toan: "<<HSDiemCaoNhat.toan<<"\n";
        cout<<"Diem van: "<<HSDiemCaoNhat.van<<"\n";
        cout<<"Diem anh: "<<HSDiemCaoNhat.anh<<"\n";
        cout<<"Phan loai: "<<HSDiemCaoNhat.phanloai<<"\n";
        return HSDiemCaoNhat;
    }
    // ham tim hoc sinh bang ten
    void timhocsinh(){
        cout<<"Nhap ho ten hoc sinh can tim: ";
        string TenhsCanTim;
        cin.ignore();
        getline(cin, TenhsCanTim);
        //chuyen ve ki tu thuong de de tim kiem
        for(int i=0;i<TenhsCanTim.length();i++)
            if(TenhsCanTim[i]>='A'&&TenhsCanTim[i]<='Z') TenhsCanTim[i]+=32;
        vector<HocSinh> DanhSach;
        //duyet qua toan bo hoc sinh
        for(HocSinh i:hocsinh){
            string ten = i.ten;
            //chuyen ve ki tu thuong
            for(int j=0;j<ten.length();j++)
                if(ten[j]>='A'&&ten[j]<='Z') ten[j]+=32;
            //tim kiem xau
            int num = int(ten.length()) - int(TenhsCanTim.length());
            for(int j=0; j<=num; j++){
                string s = ten.substr(j, TenhsCanTim.length());
                if(s==TenhsCanTim){
                    DanhSach.push_back(i);
                    break;
                }
            }
        }
        //Xuat ra thong tin hoc sinh da tim duoc
        for(HocSinh i:DanhSach){
            cout<<"Ho ten: "<<i.ten<<". Toan: "<<i.toan<<". Van: "<<i.van<<". Anh: "<<i.anh;
            cout<<". Diem tb: "<<i.diemtb<<". Phan loai: "<<i.phanloai<<"\n";
        }
        if(DanhSach.size()==0)
            cout<<"Khong tim thay bat ky hoc sinh nao";
    }
    // Ham in ra danh sach hoc sinh co diem toan thap nhat
    void diemtoanthapnhat(){
        vector<HocSinh> DanhSach;
        int DiemThapNhat = 11;
        for(HocSinh i:hocsinh){
            if(i.toan==DiemThapNhat)
                DanhSach.push_back(i);
            if(i.toan<DiemThapNhat){
                DanhSach.clear();
                DanhSach.push_back(i);
                DiemThapNhat=i.toan;
            }
        }
        //Xuat ra thong tin hoc sinh
        cout<<"Danh sach hoc sinh co diem toan thap nhat la: \n";
        for(HocSinh i:DanhSach){
            cout<<"Ho ten: "<<i.ten<<". Toan: "<<i.toan<<". Van: "<<i.van<<". Anh: "<<i.anh
                <<". Diem tb: "<<i.diemtb<<". Phan loai: "<<i.phanloai<<"\n";
        }
    }
};
int main()
{
    NhieuHocSinh s;
    s.nhapdulieu();
    s.diemtbcaonhat();
    s.timhocsinh();
    s.diemtoanthapnhat();
    return 0;
}
