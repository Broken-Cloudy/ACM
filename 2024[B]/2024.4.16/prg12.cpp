/*
�����ʾ���У�Animal�౻����Ϊ�����,
�������� Dog�� Cat��ֱ�̳� Animal����ٴ�,
������ DogCat���� Animal��ĳ�Ա��ֻ��һ��ʵ����
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
    dc.eat();//���ô������ Animal�̳е�eat����
    dc.bark();//���ô��� Dog�̳е�bark����
    dc.meow();//���ô��� Cat�̳е�meow����
    dc.play();//������ DogCat�Լ���play����
    return 0;
}
