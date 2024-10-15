
using namespace std;

class PhanSo {
private:
    int iTu, iMau;
    void Rutgon(){
        int gcd = __gcd(iMau, iTu);
        iMau = iMau/gcd;
        iTu = iTu/gcd;
        if (iMau < 0) {
            iTu = -iTu;
            iMau = -iMau;
        }
    }

public:
    PhanSo(int Tu, int Mau);
    PhanSo() : iTu(0), iMau(1) {}

    PhanSo operator+(const PhanSo ps) const;
    PhanSo operator-(const PhanSo ps) const;
    PhanSo operator*(const PhanSo ps) const;
    PhanSo operator/(const PhanSo ps) const;

    bool operator==(const PhanSo ps) const;
    bool operator!=(const PhanSo ps) const;
    bool operator<(const PhanSo ps) const;
    bool operator>(const PhanSo ps) const;
    bool operator<=(const PhanSo ps) const;
    bool operator>=(const PhanSo ps) const;

    friend ostream& operator<<(ostream& os, const PhanSo& ps);
    friend istream& operator>>(istream& is, PhanSo& ps);
};
