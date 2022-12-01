using namespace std;
#include <iostream>

class Device
{
private:
    string make;
    string model;

public:
    Device(string make, string model) : make(make), model(model) {}

    Device(const Device& secondDevice) {
        this->make = secondDevice.make;
        this->model = secondDevice.model;
    }

    Device& operator=(const Device& secondDevice) {
        if (this != &secondDevice){
            this->make = secondDevice.make;
            this->model = secondDevice.model;
        }
        return *this;
    }

    void toString()
    {
        cout << '\n' << make << " " << model;
    }
};

class Phone : private Device
{
private:
    bool hasTouchScreen;

public:
    Phone(string make, string model, bool hasTouchScreen) : Device(make, model), hasTouchScreen(hasTouchScreen) {}

    Phone(const Phone& secondPhone) : Device(secondPhone) {
        this->hasTouchScreen = secondPhone.hasTouchScreen;
    }

    Phone& operator=(const Phone& secondPhone) {
        if (this != &secondPhone){
            Device::operator=(secondPhone);
            hasTouchScreen = secondPhone.hasTouchScreen;
        }
        return *this;
    }

    void toString()
    {
        Device::toString();
        if(hasTouchScreen)
        {
            cout << " - the phone also has touch screen ";
        }
        else
        {
            cout << " - the phone does not have touch screen ";
        }
    }
};
int main(int, char **)
{
    Device myDevice = Device("Samsung", "Galaxy S22");
    Phone myPhone = Phone("iPhone", "13", true);
    Phone myCopyPhone = Phone(myPhone);
    Phone myOperatorCopyPhone = myPhone;
    myDevice.toString();
    myPhone.toString();
    myCopyPhone.toString();
    myOperatorCopyPhone.toString();
}