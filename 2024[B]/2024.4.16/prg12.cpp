/*
在这个示例中，Animal类被声明为虚基类,
这样无论 Dog和 Cat类分别继承 Animal类多少次,
最终在 DogCat类中 Animal类的成员都只有一份实例。
*/
#include<bits/stdc++.h>
using namespace std;
class Animal{
	public:
    	virtual void eat(){
    	    cout<<"Animal is eating"<<endl;
    	}
};
class Dog:virtual public Animal{
	public:
    	void bark(){
    	    cout<<"Dog is barking"<<endl;
    	}
};
class Cat:virtual public Animal{
	public:
  	  	void meow(){
   	  		cout<<"Cat is meowing"<<endl;
   		}
};
class DogCat:public Dog,public Cat{
	public:
    	void play(){
      		cout<<"DogCat is playing"<<endl;
    	}
};
int main(){
    DogCat dc;
    dc.eat();//调用从虚基类 Animal继承的eat函数
    dc.bark();//调用从类 Dog继承的bark函数
    dc.meow();//调用从类 Cat继承的meow函数
    dc.play();//调用类 DogCat自己的play函数
    return 0;
}
