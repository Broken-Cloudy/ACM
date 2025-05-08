// vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H
// ��������
class Vehicle{
private:
    int speed; // �ٶ�
    int weight; // ����
public:
    // ���캯��
    Vehicle(int s = 0, int w = 0) : speed(s), weight(w) {}
    // ��ȡ�ٶ�
    int getSpeed() const { return speed; }
    // ��ȡ����
    int getWeight() const { return weight; }
    // �����ٶ�
    void setSpeed(int s) { speed = s; }
    // ��������
    void setWeight(int w) { weight = w; }
};
#endif // VEHICLE_H

