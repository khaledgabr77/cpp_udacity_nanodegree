#include <iostream>
#include <string>
using std::string;

class Vehicle {
public:
    int wheels = 0;
    string color = "blue";
    string make  = "generic";
    
    void Print() const
    {
        std::cout << "This " << color << " " << make << " vehicle has " << wheels << " wheels!\n";
    }
};

class Car : public Vehicle {
public:
    bool sunroof = false;
};

class Bicycle : public Vehicle {
public:
    bool kickstand = true;
};

class Scooter : public Vehicle {
public:
    bool electric = false;
};

int main() 
{
    Scooter scooter;
    scooter.wheels = 2;
    scooter.Print();
};
