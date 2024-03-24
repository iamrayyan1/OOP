#include<iostream>
#include<string>
using namespace std;

class Vehicle{
private:
  string make;
  string model;
  int year;
public:
  Vehicle(string make, string model, int year) : make(make), model(model), year(year) {}
  void display(){
    cout << "Make: " << make << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
  }

};

class Car : public Vehicle{
private:
  int numDoors;
  int fuelEff;
public:
  Car(string make, string model, int year, int numDoors, int fuelEff) : Vehicle(make, model, year), numDoors(numDoors), fuelEff(fuelEff) {}
  void display(){
    Vehicle::display();
    cout << "Number of Doors: " << numDoors << endl;
    cout << "Fuel Efficiency: " << fuelEff << endl;
  }
};

class ElectricCar : public Car{
private:
  int battery;
public:
  ElectricCar(string make, string model, int year, int numDoors, int fuelEff, int battery) : Car(make, model, year, numDoors, fuelEff), battery(battery) {}
  void display(){
    Car::display();
    cout << "Battery Life: " << battery << endl;
  }
};

int main(){
  ElectricCar p1("Toyota", "Corolla", 2024, 4, 10, 95);
  p1.display();
}
