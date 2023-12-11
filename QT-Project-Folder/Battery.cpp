#include "Battery.h"
Battery::Battery(int batteryLife):batteryLife(batteryLife){

};
int Battery::getBatteryLife(){
    return this->batteryLife;
};
void Battery::decreaseBatteryLife(int value){
    this->batteryLife -= value;
};
void Battery::resetBattery(){
    this->batteryLife  =100;
};
