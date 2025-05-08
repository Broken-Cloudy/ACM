#pragma once
#include <iostream>
#include <sstream>
using namespace std;

//�������� 
class integer{
protected:
    int numerator;//����
public:
    integer(){}//Ĭ�Ϲ��캯��
    integer(int n):numerator(n){}//���캯��
};

//���������������������� 
class fraction:public integer{
private:
    int denominator;//��ĸ
	//����Ӽ̳и���  
    double result;//����������ֵ��� 
    void simplify();//��Ϊ���ʽ 
public:
    fraction():denominator(1){}//���캯������ĸĬ��Ϊ1 
    fraction(int,int);
    fraction(string&);//���캯������������ַ����������ʽת��Ϊ����  
    bool normal();//�жϷ�ĸ�Ƿ�Ϊ0
    //��������������ص����� 
    friend fraction operator+(fraction&,fraction&);
    friend fraction operator-(fraction&,fraction&);
    friend fraction operator*(fraction&,fraction&);
    friend fraction operator/(fraction&,fraction&);
    friend ostream& operator<<(ostream&,fraction&);
    friend istream& operator>>(istream&,fraction&);
};


