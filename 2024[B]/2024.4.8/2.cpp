#include <iostream>
using namespace std;
class Complex{
    public:
        Complex():real(0),imag(0){}
		Complex(double r,double i):real(r),imag(i){}
		Complex(double d):real(d),imag(0){}
		Complex operator *=(const Complex &c);
		Complex operator =(const Complex &c);
		friend ostream& operator<<(ostream &output,const Complex &c);
    private:
        double real,imag;
};
Complex Complex::operator =(const Complex &c) {
    real = c.real;
    imag = c.imag;
    return *this;
}
Complex Complex::operator *=(const Complex &c) {
    *this=Complex(real*c.real-imag*c.imag,real*c.imag+imag*c.real);
    return *this;
}
ostream &operator<<(ostream &output,const Complex &c){
    output<<"("<<c.real;
    if (c.imag >= 0) output<<"+";
    output<<c.imag<<"i)";
    return output;
}
int main() {
    Complex c(2.0, 3.0), c1(4, 5), c2, c3;
    c3 = c2 = c;
    cout << "c=" << c << endl;
    c2 *= 5;
    cout << "c*=5, c=" << c2 << endl;
    c3 *= c1;
    cout << "c*=" << c1 << ", c=" << c3 << endl;
    return 0;
}
