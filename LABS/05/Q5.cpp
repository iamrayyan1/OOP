
#include<iostream>
#include<string>
using namespace std;

class Engine
{
private:
  int power;

public:
  Engine(int power)
  {
    this->power = power;
  }
  int setPower(int power)
  {
    this->power = power;
  }
  int getPower()
  {
    return power;
  }

};

class Wheels
{
private:
  string wheels;

public:
  Wheels(string wheels)
  {
    this->wheels = wheels;
  }
  string setWheels(string wheels)
  {
    this->wheels = wheels;
  }
  string getWheels()
  {
    return wheels;
  }

};

class Headlights
{
private:
  string headlights;

public:
  Headlights(string headlights)
  {
    this->headlights = headlights;
  }
  string setHeadlights(string headlights)
  {
    this->headlights = headlights;
  }
  string getHeadlights()
  {
    return headlights;
  }
};


class Steering
{
private:
  string steering;

public:
  Steering(string steering)
  {
    this->steering = steering;
  }
  string setSteering(string steering)
  {
    this->steering = steering;
  }
  string getSteering()
  {
    return steering;
  }

};

class Car
{
private:
  Engine *engine;
  Wheels *wheels;
  Headlights *headlights;
  Steering *steering;

public:
  Car(Engine *engine, Wheels *wheels, Headlights *headlights, Steering *steering) : engine(engine), wheels(wheels), headlights(headlights), steering(steering) {}

  void setEngine(Engine *engine)
  {
    this->engine = engine;
  }
  Engine *getEngine()
  {
    return engine;
  }
  void setWheels(Wheels *wheels)
  {
    this->wheels = wheels;
  }
  Wheels *getWheels()
  {
    return wheels;
  }
  void setHeadlights(Headlights *headlights)
  {
    this->headlights = headlights;
  }
  Headlights *getHeadlights()
  {
    return headlights;
  }
  void setSteering(Steering *steering)
  {
    this->steering = steering;
  }
  Steering *getSteering()
  {
    return steering;
  }

};

int main()
{
  Engine *engine = new Engine(100);
  Wheels *wheels = new Wheels("4");
  Headlights *headlights = new Headlights("2");
  Steering *steering = new Steering("1");
  Car *car = new Car(engine, wheels, headlights, steering);
  cout << "Engine power: " << car->getEngine()->getPower() << endl;
  cout << "Wheels: " << car->getWheels()->getWheels() << endl;
  cout << "Headlights: " << car->getHeadlights()->getHeadlights() << endl;
  cout << "Steering: " << car->getSteering()->getSteering() << endl;
  return 0;
}

