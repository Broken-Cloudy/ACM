#include<iostream>
using namespace std;
class Point{
	int x,y;
	public:
		Point(int xx=0,int yy=0):x(xx),y(yy){
			cout<<"����Point���캯��"<<endl;
		}
		~Point(){
			cout<<"����Point��������"<<endl;
		}
};
class Circle{
	Point center;
	int radius;
	public:
		Circle(int cx,int cy,int cz):center(cx,cy),radius(cz){
			cout<<"����Circle���캯��"<<endl;
		}
		void area(){
			cout<<3.14159*radius*radius<<endl;
		}
		~Circle(){
			cout<<"����Circle��������"<<endl;
		}
};
int main(){
	freopen("2.in","r",stdin);freopen("2.out","w",stdout);
	
	fclose(stdin);fclose(stdout);
	return 0;
}
