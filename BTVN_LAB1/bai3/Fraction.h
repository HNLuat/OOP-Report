
class Fraction{
private:
    int numerator, denominator;
public:
    Fraction();
    Fraction(int numer, int denom);
    void Enter();
    void Print();
    void Simplify();
    Fraction operator * (Fraction const b) const{
        return Fraction(numerator * b.numerator, denominator * b.denominator);
    }
    bool operator < (Fraction const b) const{
        return (long long) numerator * b.denominator
                < (long long)b.numerator * denominator;
    }
    bool operator == (Fraction const b) const{
        return numerator == b.numerator && denominator == b.denominator;
    }
};

