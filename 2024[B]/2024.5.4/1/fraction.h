#pragma
#include <iostream>
#include <sstream>
using namespace std;
class integer{
protected:
    int numerator;//分子
public:
    integer(){}//构造函数
    integer(int n):numerator(n){}
};

class fraction:public integer{
private:
    unsigned int denominator;//分母
    double result;
    void simplify();//化简
public:
    fraction():denominator(1){}
    fraction(int,int);
    fraction(string&);
    bool normal();//判断分母是否为0
    friend fraction operator+(fraction&,fraction&);
    friend fraction operator-(fraction&,fraction&);
    friend fraction operator*(fraction&,fraction&);
    friend fraction operator/(fraction&,fraction&);
    friend ostream& operator<<(ostream&,fraction&);
    friend istream& operator>>(istream&,fraction&);
};
