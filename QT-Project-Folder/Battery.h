#ifndef BATTERY_H
#define BATTERY_H
class Battery{
public:
     Battery(int batteryLife);
    int getBatteryLife();
    void decreaseBatteryLife(int value);
    void resetBattery();
private:
    int batteryLife;

};

#endif // BATTERY_H
