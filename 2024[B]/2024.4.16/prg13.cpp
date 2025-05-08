#include<iostream>
#include"vehicle.h"
//自行车类
class Bicycle:public Vehicle{
private:
    int high;//车高度
public:
    //构造函数
    Bicycle(int h=0,int s=0,int w=0):high(h),Vehicle(s,w){}
    //获取车高度
    int getHigh()const{return high;}
    //设置车高度
    void setHigh(int h){high=h;}
};
// 汽车类
class Car:public Vehicle{
	private:
 	   int seatNum;//座位数
	public:
    	//构造函数
    	Car(int seat=0,int s=0,int w=0):seatNum(seat),Vehicle(s,w){}
    	//获取座位数
    	int getSeatNum()const{return seatNum;}
    	//设置座位数
    	void setSeatNum(int seat){seatNum=seat;}
};
//摩托车类，从自行车和汽车派生
class Motorcycle:public Bicycle,public Car{
	public:
    	//构造函数
    	Motorcycle(int h=0,int seat=0, int s=0, int w=0):
			Bicycle(h,s,w),Car(seat,s,w){}
};
int main() {
    //在这里进行测试
    Motorcycle moto(100,2,80,500);//车把高度为100,座位数为2,速度80,重量500
    std::cout<<"Speed:"<<moto.getSpeed()<<std::endl;
    std::cout<<"Weight:"<<moto.getWeight()<<std::endl;
    std::cout<<"Handlebar Height:"<<moto.getHigh()<<std::endl;
    std::cout<<"Seat Number:"<<moto.getSeatNum()<<std::endl;
    return 0;
}

