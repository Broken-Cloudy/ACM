/*
（1）程序中系统创建了三个对象：c1、c2和c3。
	析构函数会在程序结束时被调用，因为这些对象是在栈上创建的，它们的作用域是main函数内
	当main函数结束时，这些对象就会被销毁，因此析构函数会被调用3次。
（2）在函数重载中，重载运算符+、-、+=、<<都可以不使用引用&。 
	但为了提高效率和避免不必要的复制操作，通常应该使用引用&。
	如果去掉引用&，系统会增加创建临时对象。
（3）<<运算符重载可以设为成员函数，但不建议。
	因为它需要访问私有成员变量，所以一般情况下应该将其定义为友元函数。
	友元函数可以访问类的私有成员变量，而成员函数不需要显式传递对象，但只能访问其所属类的成员。
	因此，对于重载输出操作符<<来说，更合适的做法是将其定义为友元函数。
（4）运算符重载函数的返回类型是Ostream &，目的是为了支持链式调用。
	这样可以在同一行代码中连续使用输出操作符<<，
	例如：cout<<c1<<c2;返回类型为Ostream &允许将一个流插入到另一个流中，从而实现链式操作。
*/
#include<iostream>
using namespace std;
class Complex{
	private:
		double real,imag;
	public:
		Complex(double r=0.0,double i=0.0):real(r),imag(i){}
		~Complex(){
			cout<<"实部="<<real<<"虚部="<<imag<<endl; 
		}
		Complex operator +(const Complex &c){
			return Complex(real+c.real,imag+c.imag);
		}
		Complex operator -(const Complex &c){
			return Complex(real-c.real,imag-c.imag);
		}
		Complex operator *(const Complex &c){
			return Complex(real*c.real-imag*c.imag,real*c.imag+imag*c.real);
		}	
		Complex operator =(const Complex &c){
			if(this!=&c) {
            	real=c.real;
           		imag=c.imag;
        	}
        	return *this;
		}
		Complex operator +=(const Complex &c){
			return Complex(real+c.real,imag+c.imag);
		}
		Complex operator *=(const Complex &c){
			return Complex(real*c.real-imag*c.imag,real*c.imag+imag*c.real);
		}
		friend ostream& operator <<(ostream& os,const Complex &complex){
			if(complex.imag==0){
				os<<complex.real;
			}
			else if(complex.imag<0){
				os<<complex.real<<"-"<<-complex.imag<<"i";
			} 
			else os<<complex.real<<"+"<<complex.imag<<"i";
			return os;
		}
};
int main(){
	Complex c1(1.68,1.28);
	Complex c2(1.38,1.58);
	Complex c3;
	cout<<"c1="<<c1<<endl;
	cout<<"c2="<<c2<<endl;
	cout<<"c3="<<c3<<endl;
	c3=c1+c2;
	cout<<"c1+c2="<<c3<<endl;
	c3=c1-c2;
	cout<<"c1-c2="<<c3<<endl;
	c3=(0,0);
	c3+=c1;
	cout<<"c3+=c1:"<<c3<<endl;
	return 0;
}
