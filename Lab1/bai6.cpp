#include <bits/stdc++.h>
using namespace std;
struct hocsinh{
    string ten;
    double toan, van, anh, diemtb;
    string phanloai;
    string subject[3] = {"toan", "van", "anh"};
    void nhap(){
        cout<<"Nhap ho ten hoc sinh: ";
        cin.ignore();
        getline(cin, ten);
        while(!legitname()){
            cout<<"Ho ten khong hop le, vui long nhap lai: ";
            getline(cin, ten);
        }
        for(int i=0;i<3;i++){
            cout<<"Nhap diem "<<subject[i]<<": ";
            double grades = 0;
            cin>>grades;
            while(!legitgrades(grades)){
                cout<<"Diem "<<subject[i]<<" khong hop le, vui long nhap lai: ";
                cin>>grades;
            }
            if(i==0) toan = grades;
            if(i==1) van = grades;
            if(i==2) anh = grades;
        }
        capnhatdiemtb();
        capnhatphanloai();
    }
    bool legitname(){
        for(int i=0;i<ten.length();i++){
            if(ten[i] == ' ') continue;
            if(ten[i]<'A' || (ten[i]>'Z'&&ten[i]<'a') || ten[i]>'z')
                return false;
        }
        return true;
    }
    bool legitgrades(double grades){
        return grades>=0&&grades<=10;
    }
    void capnhatdiemtb(){
        diemtb = (2*toan + van + anh)/4;
    }
    void capnhatphanloai(){
        if(diemtb>=9) phanloai = "Xuat sac";
        if(diemtb>=8&&diemtb<9) phanloai = "Gioi";
        if(diemtb>=6.5&&diemtb<8) phanloai = "Kha";
        if(diemtb>=5&&diemtb<6.5) phanloai = "Trung binh";
        if(diemtb<5) phanloai = "Yeu";
    }
};
struct nhieuhocsinh{
    vector<hocsinh> student;
    int soluong;
    void nhapdulieu(){
        cout<<"Nhap so luong hoc sinh: ";
        cin>>soluong;
        for(int i=0;i<soluong;i++){
            hocsinh a;
            a.nhap();
            student.push_back(a);
        }
    }
    hocsinh diemtbcaonhat(){
        hocsinh maxx;
        maxx.diemtb = -1;
        for(hocsinh i:student)
            if(i.diemtb>maxx.diemtb)
                maxx=i;
        cout<<"Hoc sinh co diem trung binh cao nhat la:\n";
        cout<<"Ho ten: "<<maxx.ten<<"\n";
        cout<<"Diem trung binh: "<<maxx.diemtb<<"\n";
        cout<<"Diem toan: "<<maxx.toan<<"\n";
        cout<<"Diem van: "<<maxx.van<<"\n";
        cout<<"Diem anh: "<<maxx.anh<<"\n";
        cout<<"Phan loai: "<<maxx.phanloai<<"\n";
        return maxx;
    }
    void timhocsinh(){
        cout<<"Nhap ho ten hoc sinh can tim: ";
        string pattern;
        cin.ignore();
        getline(cin, pattern);
        //chuyen ve ki tu thuong de de tim kiem
        for(int i=0;i<pattern.length();i++)
            if(pattern[i]>='A'&&pattern[i]<='Z') pattern[i]+=32;
        vector<hocsinh> match;
        //duyet qua toan bo hoc sinh
        for(hocsinh i:student){
            string name = i.ten;
            //chuyen ve ki tu thuong
            for(int j=0;j<name.length();j++)
                if(name[j]>='A'&&name[j]<='Z') name[j]+=32;
            //tim kiem xau
            int num = int(name.length()) - int(pattern.length());
            for(int j=0; j<=num; j++){
                if(j!=0&&name[j-1]!=' ') continue;
                string s = name.substr(j, pattern.length());
                if(s==pattern){
                    match.push_back(i);
                    break;
                }
            }
        }
        //Xuat ra thong tin hoc sinh da tim duoc
        for(hocsinh i:match){
            cout<<"Ho ten: "<<i.ten<<". Toan: "<<i.toan<<". Van: "<<i.van<<". Anh: "<<i.anh;
            cout<<". Diem tb: "<<i.diemtb<<". Phan loai: "<<i.phanloai<<"\n";
        }
        if(match.size()==0)
            cout<<"Khong tim thay bat ky hoc sinh nao";
    }
    void diemtoanthapnhat(){
        vector<hocsinh> danhsach;
        hocsinh minn;
        minn.toan = 11;
        for(hocsinh i:student){
            if(i.toan==minn.toan)
                danhsach.push_back(i);
            if(i.toan<minn.toan){
                danhsach.clear();
                danhsach.push_back(i);
                minn=i;
            }
        }
        //Xuat ra thong tin hoc sinh
        cout<<"Danh sach hoc sinh co diem toan thap nhat la: \n";
        for(hocsinh i:danhsach){
            cout<<"Ho ten: "<<i.ten<<". Toan: "<<i.toan<<". Van: "<<i.van<<". Anh: "<<i.anh;
            cout<<". Diem tb: "<<i.diemtb<<". Phan loai: "<<i.phanloai<<"\n";
        }
    }
};
int main()
{
    nhieuhocsinh s;
    s.nhapdulieu();
    s.diemtbcaonhat();
    s.timhocsinh();
    s.diemtoanthapnhat();
    return 0;
}
