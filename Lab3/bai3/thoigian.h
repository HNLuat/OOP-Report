using namespace std;
class ThoiGian{
private:
    int gio, phut, giay;
public:
    ThoiGian() : giay(0), phut(0), gio(0) {}
    ThoiGian(int h, int m, int s) : gio(h), phut(m), giay(s) {}
    int TinhGiay() const;
    void TinhLaiGio(int s);
    ThoiGian operator+(int s);
    ThoiGian operator-(int s);
    ThoiGian operator+(const ThoiGian tg);
    ThoiGian operator-(const ThoiGian tg);
    ThoiGian operator++(int);
    ThoiGian operator--(int);
    ThoiGian& operator++();
    ThoiGian& operator--();
    bool operator==(const ThoiGian tg) const;
    bool operator!=(const ThoiGian tg) const;
    bool operator<(const ThoiGian tg) const;
    bool operator>(const ThoiGian tg) const;
    bool operator<=(const ThoiGian tg) const;
    bool operator>=(const ThoiGian tg) const;
    friend istream& operator>>(istream& is, ThoiGian& tg);
    friend ostream& operator<<(ostream& os, const ThoiGian tg);
};
