#ifndef DIEM_H
#define DIEM_H
#endif // DIEM_H
class Diem{
private:
    float iHoanh, iTung;

public:
    Diem();
    Diem(float Hoanh, float Tung);
    Diem(const Diem& A);
    void Xuat();
    float GetTungDo()const;
    float GetHoanhDo() const;
    void SetTungDo(int Tung);
    void SetHoanhDo(int Hoanh);
    void TinhTien(int dx, int dy);
};


