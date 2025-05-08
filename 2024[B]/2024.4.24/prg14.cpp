/*
定义一个学生类Student作基类，在派生一个Graduate类，
学生类有学号，姓名和分数，研究生增加工资
它们有同名的函数display()，利用虚函数，
编程分别输出学生和研究生的数据，具体数据自拟。 
*/
#include<bits/stdc++.h>
using namespace std;
class Student{
	protected://声明数据成员的访问属性 
		int id;
		string name;
		int score;
	public:
		Student(int,string,int);
		virtual void display();
}; 
Student::Student(int i,string n,int cr){
	id=i;
	name=n;
	score=cr;
}
void Student::display(){
	cout<<id<<": "<<name<<endl;
	cout<<score<<endl;
}
class Graduate:public Student{//Graduate类共有继承Student类 
	protected:
		int salary;
	public:
		Graduate(int i,string n,int cr,int sa)//构造函数的定义
		:Student(i,n,cr),salary(sa){}
	void display();
};
void Graduate::display(){//Graduate类成员函数display()函数的定义 
	cout<<id<<": "<<name<<endl;
	cout<<score<<endl;
	cout<<salary<<endl;
}
int main(){
	Student stu(1,"John",99);
	stu.display();
	Graduate gra(2,"JOHNLIU",100,5000);
	Student *pstu=&gra; pstu->display();
	return 0;
}
