// vehicle.h
#ifndef VEHICLE_H
#define VEHICLE_H
// 车辆基类
class Vehicle{
private:
    int speed; // 速度
    int weight; // 重量
public:
    // 构造函数
    Vehicle(int s = 0, int w = 0) : speed(s), weight(w) {}
    // 获取速度
    int getSpeed() const { return speed; }
    // 获取重量
    int getWeight() const { return weight; }
    // 设置速度
    void setSpeed(int s) { speed = s; }
    // 设置重量
    void setWeight(int w) { weight = w; }
};
#endif // VEHICLE_H

