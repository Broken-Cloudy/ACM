#include<iostream>
#include<cstring>//0�����ַ�������������
using namespace std;
class Student{//1����һ����ΪStudent����
	private://2�������η���˽�г�Աֻ�������ڲ�����
		char sNo[10];//3�洢ѧ��ѧ�ŵĳ�Ա����
		char* sName;//4�洢ѧ�������ĳ�Ա������C����ַ�����
		string sGender;//5�洢ѧ���Ա�ĳ�Ա������C++����ַ�����
		int sAge;
	public://6�������η������г�Ա�����������
		Student(char no[],const char* name,string gender,int age){//7���ṩ����Ϣ��ʼ��ѧ������Ĺ��캯��
			strcpy(sNo,no);//8��ѧ�Ÿ��Ƹ���Ա����
			int nameLength=strlen(name)+1;//9����ѧ�������ĳ���
			sName=new char[nameLength];//10��̬�����ڴ�洢ѧ������
			strcpy(sName,name);//11��ѧ���������Ƶ���̬������ڴ���
			sGender=gender;//12����ѧ���Ա�
			sAge=age;
		}
	void display(){//13��ʾѧ����ϸ��Ϣ�ĺ���(���ѧ��ѧ��)
		cout<<sNo<<endl;
	}
	~Student(){//14����̬�����ڴ����������
		delete[] sName;//15�ͷ�Ϊѧ������������ڴ�
	}
};//16�ඨ�����
int main(){
	Student s1("1001","Jenny","F",18);//17ʹ���ṩ����Ϣ����Student���ʵ��s1
	cout<<sizeof(s1)<<endl;//18���s1����Ĵ�С
	s1.display();//19����display������ʾѧ����ϸ��Ϣ
	Student s2=Student("1002","Bob","M",18);//20ʹ�ù��캯���﷨����Student�����һ��ʵ��s2
	cout<<sizeof(s2)<<endl;
	s2.display();
	Student *s3=new Student("1003","Stone","M",18);//21ʹ�ö�̬�ڴ���䴴��ָ��Student�����ָ��s3
	cout<<sizeof(s3)<<endl;
	s3->display();
	delete s3;//22�ͷ�Ϊs3���������ڴ�
	return 0;
}
