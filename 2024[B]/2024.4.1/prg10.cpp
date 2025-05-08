#include<iostream>
using namespace std;
class Sample{
	public:
		int v;
		Sample(){}//默认构造函数,未指定初始化值
		Sample(int x):v(x){}//带参数的构造函数,初始化v为传入的参数x
		Sample(Sample &s){//拷贝构造函数,接受一个Sample对象的引用作为参数
			v=s.v+2;//将新对象的v设置为传入对象的v加2
		}
};
void PrintAndDouble(Sample o){
	cout<<o.v;//输出对象o的v值
	cout<<endl;//换行 
}
int main(){
	Sample a(5);//创建一个Sample对象a，使用带参数的构造函数初始化v为5
	Sample b=a;//使用拷贝构造函数创建对象b，将对象a的内容复制给b
	PrintAndDouble(b);//调用PrintAndDouble函数输出对象b的v值并换行
	Sample c(20);//创建一个Sample对象c，使用带参数的构造函数初始化v为20
	PrintAndDouble(c);//调用PrintAndDouble函数输出对象c的v值并换行
	Sample d;//创建一个Sample对象d，使用默认构造函数初始化
	d=a;//将对象a的内容复制给对象d
	cout<<d.v<<endl;//打印对象d的v值并换行
	return 0;
}
