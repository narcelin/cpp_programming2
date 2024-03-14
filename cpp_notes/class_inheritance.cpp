#include <iostream>

using namespace std;

class Device {
    private: //Only Device class can access private here
    string model;
    string serialNumber;

    public:
    Device() : model("XXX"), serialNumber("000"){};
    Device(string initModel) : model(initModel), serialNumber("000"){};
    Device(string initModel, string initSerialNumber) : model(initModel), serialNumber(initSerialNumber){};

    string getModel(){
        return model;
    }

    string getSerialNumber(){
        return serialNumber;
    }

    void test3(){cout << "TEST#";}

    protected: //Only open to dirived classes. Usefulness is debaitable 
    void protectedFunctionInDeviceClass(){cout << "TEST";}

};

class DoorDevice : public Device {
    private:
    public:
        DoorDevice() : Device(){}; //Using parent Device 's constructor
        DoorDevice(string initModel);
        DoorDevice(string initModel, string initSerialNumber) : Device(initModel, initSerialNumber){};

        void usingProtectedParentFunction(){ //Accessing protected fuction in parent class. Usefulness is debaitable
            protectedFunctionInDeviceClass();
        }
};

DoorDevice::DoorDevice(string initModel) : Device(initModel){}; //Another way to set constructor. Outside of the class

int main(){
    DoorDevice doorDevice("APPLES");
    cout << doorDevice.getModel();
    Device test;
    doorDevice.usingProtectedParentFunction();
    return 0;
};