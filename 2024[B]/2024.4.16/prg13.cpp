#include<iostream>
#include"vehicle.h"
//���г���
class Bicycle:public Vehicle{
private:
    int high;//���߶�
public:
    //���캯��
    Bicycle(int h=0,int s=0,int w=0):high(h),Vehicle(s,w){}
    //��ȡ���߶�
    int getHigh()const{return high;}
    //���ó��߶�
    void setHigh(int h){high=h;}
};
// ������
class Car:public Vehicle{
	private:
 	   int seatNum;//��λ��
	public:
    	//���캯��
    	Car(int seat=0,int s=0,int w=0):seatNum(seat),Vehicle(s,w){}
    	//��ȡ��λ��
    	int getSeatNum()const{return seatNum;}
    	//������λ��
    	void setSeatNum(int seat){seatNum=seat;}
};
//Ħ�г��࣬�����г�����������
class Motorcycle:public Bicycle,public Car{
	public:
    	//���캯��
    	Motorcycle(int h=0,int seat=0, int s=0, int w=0):
			Bicycle(h,s,w),Car(seat,s,w){}
};
int main() {
    //��������в���
    Motorcycle moto(100,2,80,500);//���Ѹ߶�Ϊ100,��λ��Ϊ2,�ٶ�80,����500
    std::cout<<"Speed:"<<moto.getSpeed()<<std::endl;
    std::cout<<"Weight:"<<moto.getWeight()<<std::endl;
    std::cout<<"Handlebar Height:"<<moto.getHigh()<<std::endl;
    std::cout<<"Seat Number:"<<moto.getSeatNum()<<std::endl;
    return 0;
}

