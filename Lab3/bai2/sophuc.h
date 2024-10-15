using namespace std;
class SoPhuc {
private:
    double Thuc;
    double Ao;

public:
    SoPhuc(double thuc, double ao) : Thuc(thuc), Ao(ao) {}
    SoPhuc() : Thuc(0), Ao(0) {}

    SoPhuc operator+(const SoPhuc sp) const;
    SoPhuc operator-(const SoPhuc sp) const;
    SoPhuc operator*(const SoPhuc sp) const;
    SoPhuc operator/(const SoPhuc sp) const;

    bool operator==(const SoPhuc sp) const;
    bool operator!=(const SoPhuc sp) const;

    friend istream& operator>>(istream& is, SoPhuc& sp);
    friend ostream& operator<<(ostream& os, const SoPhuc sp);
};

