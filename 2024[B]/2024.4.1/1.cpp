#include<iostream>
#include<cstring>//0包含字符串操作函数库
using namespace std;
class Student{//1定义一个名为Student的类
	private://2访问修饰符，私有成员只能在类内部访问
		char sNo[10];//3存储学生学号的成员变量
		char* sName;//4存储学生姓名的成员变量（C风格字符串）
		string sGender;//5存储学生性别的成员变量（C++风格字符串）
		int sAge;
	public://6访问修饰符，公有成员可在类外访问
		Student(char no[],const char* name,string gender,int age){//7用提供的信息初始化学生对象的构造函数
			strcpy(sNo,no);//8将学号复制给成员变量
			int nameLength=strlen(name)+1;//9计算学生姓名的长度
			sName=new char[nameLength];//10动态分配内存存储学生姓名
			strcpy(sName,name);//11将学生姓名复制到动态分配的内存中
			sGender=gender;//12分配学生性别
			sAge=age;
		}
	void display(){//13显示学生详细信息的函数(输出学生学号)
		cout<<sNo<<endl;
	}
	~Student(){//14清理动态分配内存的析构函数
		delete[] sName;//15释放为学生姓名分配的内存
	}
};//16类定义结束
int main(){
	Student s1("1001","Jenny","F",18);//17使用提供的信息创建Student类的实例s1
	cout<<sizeof(s1)<<endl;//18输出s1对象的大小
	s1.display();//19调用display函数显示学生详细信息
	Student s2=Student("1002","Bob","M",18);//20使用构造函数语法创建Student类的另一个实例s2
	cout<<sizeof(s2)<<endl;
	s2.display();
	Student *s3=new Student("1003","Stone","M",18);//21使用动态内存分配创建指向Student对象的指针s3
	cout<<sizeof(s3)<<endl;
	s3->display();
	delete s3;//22释放为s3对象分配的内存
	return 0;
}
