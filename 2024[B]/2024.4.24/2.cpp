#include<iostream>
using namespace std;
const double PI=3.14;
class Circle{
	protected:
		double r;
	public:
		Circle(double radius=0):r(radius){}
		virtual double Area(); 
};
class Cylinder:public Circle{
	double h;
	public:
		Cylinder(double radius=0,double height=0):
			Circle(radius),h(height){}
		virtual double Area(){
			return 2*PI*r*(r+h);
		}
		
};
int main(){
	return 0;
}
