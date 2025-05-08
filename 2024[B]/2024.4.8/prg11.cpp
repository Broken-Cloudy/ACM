/*
��1��������ϵͳ��������������c1��c2��c3��
	�����������ڳ������ʱ�����ã���Ϊ��Щ��������ջ�ϴ����ģ����ǵ���������main������
	��main��������ʱ����Щ����ͻᱻ���٣�������������ᱻ����3�Ρ�
��2���ں��������У����������+��-��+=��<<�����Բ�ʹ������&�� 
	��Ϊ�����Ч�ʺͱ��ⲻ��Ҫ�ĸ��Ʋ�����ͨ��Ӧ��ʹ������&��
	���ȥ������&��ϵͳ�����Ӵ�����ʱ����
��3��<<��������ؿ�����Ϊ��Ա�������������顣
	��Ϊ����Ҫ����˽�г�Ա����������һ�������Ӧ�ý��䶨��Ϊ��Ԫ������
	��Ԫ�������Է������˽�г�Ա����������Ա��������Ҫ��ʽ���ݶ��󣬵�ֻ�ܷ�����������ĳ�Ա��
	��ˣ������������������<<��˵�������ʵ������ǽ��䶨��Ϊ��Ԫ������
��4����������غ����ķ���������Ostream &��Ŀ����Ϊ��֧����ʽ���á�
	����������ͬһ�д���������ʹ�����������<<��
	���磺cout<<c1<<c2;��������ΪOstream &����һ�������뵽��һ�����У��Ӷ�ʵ����ʽ������
*/
#include<iostream>
using namespace std;
class Complex{
	private:
		double real,imag;
	public:
		Complex(double r=0.0,double i=0.0):real(r),imag(i){}
		~Complex(){
			cout<<"ʵ��="<<real<<"�鲿="<<imag<<endl; 
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
