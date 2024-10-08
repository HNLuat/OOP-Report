class Diem{
private:
    float iHoanh, iTung;

public:
    void Xuat();
    void Nhap();
    int GetTungDo()const;
    int GetHoanhDo() const;
    void SetTungDo(int Tung);
    void SetHoanhDo(int Hoanh);
    void TinhTien(int dx, int dy);
};

