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
    void SetTungDo(float Tung);
    void SetHoanhDo(float Hoanh);
    void TinhTien(float dx, float dy);
};


