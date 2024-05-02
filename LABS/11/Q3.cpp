#include <iostream>
using namespace std;

class Vehicle{
protected:
  string make, model;
  int speed;

public:
  Vehicle(string m, string mod, int s) : make(m), model(mod), speed(s) {}

  string getMake(){return make;}
  string getModel(){return model;}
  int getSpeed(){return speed;}

  virtual void accelerate() = 0;
  virtual void brake() = 0;
  virtual void calculateFuelEfficiency() = 0;
};

class Car : public Vehicle{
  double fuelCapacity;

public:
  Car(string m, string mod, int s, double fc) : Vehicle(m, mod, s), fuelCapacity(fc) {}

  void accelerate(){
    speed += 10;
  }
  void brake(){
    speed -= 10;
  }
  void calculateFuelEfficiency(){
    cout << "Fuel efficiency: " << fuelCapacity / speed << " km/l" << endl;
  }
};

class Truck : public Vehicle{
  int cargoCapacity;
  double fuelCapacity;

public:
  Truck(string m, string mod, int s, int cc, double fc) : Vehicle(m, mod, s), cargoCapacity(cc), fuelCapacity(fc) {}
  void accelerate(){
    speed += 20;
  }
  void brake(){
    speed -= 20;
  }
  void calculateFuelEfficiency(){
    cout << "Fuel efficiency: " << fuelCapacity / speed << " km/l" << endl;
  }
};

int main(){
  Car car("Toyota", "Corolla", 120, 50);
  Truck truck("Ford", "truck", 80, 2000, 100);
  Vehicle* ptr = &car;
  ptr->calculateFuelEfficiency();
  ptr = &truck;
  ptr->calculateFuelEfficiency();
}
