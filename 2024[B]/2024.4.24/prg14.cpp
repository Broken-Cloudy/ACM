/*
����һ��ѧ����Student�����࣬������һ��Graduate�࣬
ѧ������ѧ�ţ������ͷ������о������ӹ���
������ͬ���ĺ���display()�������麯����
��̷ֱ����ѧ�����о��������ݣ������������⡣ 
*/
#include<bits/stdc++.h>
using namespace std;
class Student{
	protected://�������ݳ�Ա�ķ������� 
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
class Graduate:public Student{//Graduate�๲�м̳�Student�� 
	protected:
		int salary;
	public:
		Graduate(int i,string n,int cr,int sa)//���캯���Ķ���
		:Student(i,n,cr),salary(sa){}
	void display();
};
void Graduate::display(){//Graduate���Ա����display()�����Ķ��� 
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
