using namespace std;
class NgayThangNam{
private:
    int ngay, thang, nam;
    static const int ngaytrongthang[13];
public:
    NgayThangNam() : ngay(0), thang(0), nam(0) {}
    NgayThangNam(int d, int m, int y) : ngay(d), thang(m), nam(y) {}
    int TinhNgay() const;
    void TinhLaiNgay(int d);
    NgayThangNam operator+(int d);
    NgayThangNam operator-(int d);
    NgayThangNam operator+(const NgayThangNam date);
    NgayThangNam operator-(const NgayThangNam date);
    NgayThangNam operator++(int);
    NgayThangNam operator--(int);
    NgayThangNam& operator++();
    NgayThangNam& operator--();
    bool operator==(const NgayThangNam date) const;
    bool operator!=(const NgayThangNam date) const;
    bool operator<(const NgayThangNam date) const;
    bool operator>(const NgayThangNam date) const;
    bool operator<=(const NgayThangNam date) const;
    bool operator>=(const NgayThangNam date) const;
    friend istream& operator>>(istream& is, NgayThangNam& date);
    friend ostream& operator<<(ostream& os, const NgayThangNam date);
};

