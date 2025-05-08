#pragma once
#include <iostream>
#include <sstream>
using namespace std;

//整数父类 
class integer{
protected:
    int numerator;//分子
public:
    integer(){}//默认构造函数
    integer(int n):numerator(n){}//构造函数
};

//整数父类派生出分数子类 
class fraction:public integer{
private:
    int denominator;//分母
	//其分子继承父类  
    double result;//最后分数的数值结果 
    void simplify();//化为最简式 
public:
    fraction():denominator(1){}//构造函数，分母默认为1 
    fraction(int,int);
    fraction(string&);//构造函数，将输入的字符串除法表达式转化为分数  
    bool normal();//判断分母是否为0
    //以下是运算符重载的声明 
    friend fraction operator+(fraction&,fraction&);
    friend fraction operator-(fraction&,fraction&);
    friend fraction operator*(fraction&,fraction&);
    friend fraction operator/(fraction&,fraction&);
    friend ostream& operator<<(ostream&,fraction&);
    friend istream& operator>>(istream&,fraction&);
};


