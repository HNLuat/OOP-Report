
class Fraction{
private:
    int numerator, denominator;
public:
    Fraction();
    Fraction(int numer, int denom);
    void Enter();
    void Print();
    bool operator < (Fraction const b) const{
        return (long long) numerator * b.denominator
                < (long long)b.numerator * denominator;
    }
};
