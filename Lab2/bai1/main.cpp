#include <iostream>
#include "Diem.h"
using namespace std;

int main()
{
    Diem A, B(0, 1);
    A.TinhTien(1, 1);
    B.SetHoanhDo(10);
    B.SetTungDo(2);
    cout<<A.GetHoanhDo()<<" "<<A.GetTungDo()<<"\n";
    Diem C(B);
    C.TinhTien(-5, -5);
    C.Xuat();
    return 0;
}
