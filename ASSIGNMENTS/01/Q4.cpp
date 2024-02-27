#include<iostream>
#include<string>
using namespace std;

class RollerCoaster
{
private:
  string name;
  int height, length, speed, capacity, currentNumRiders;
  bool rideInProgress;

public:
  RollerCoaster()
  {
    name = "roller coaster";
    height = 500;
    length = 2000;
    capacity = 20;
    currentNumRiders = 0;
    rideInProgress = false;
  }

  RollerCoaster(string name, int height, int length, int capacity)
  {
    this->name = name;
    this->height = height;
    this->length = length;
    if(capacity % 2 == 0 || capacity % 3 == 0)
    {
      this->capacity = capacity;
    }
    else
    {
      this->capacity = capacity + 1;
    }
    currentNumRiders = 0;
    rideInProgress = false;
  }

  //getters
  string getName()
  {
    return name;
  }
  int getHeight()
  {
    return height;
  }
  int getLength()
  {
    return length;
  }
  int getSpeed()
  {
    return speed;
  }
  int getCapacity()
  {
    return capacity;
  }
  int getCurrentNumRiders()
  {
    return currentNumRiders;
  }
  bool getRideInProgress()
  {
    return rideInProgress;
  }

  //setters
  void setName(string name)
  {
    this->name = name;
  }
  void setHeight(int height)
  {
    this->height = height;
  }
  void setLength(int length)
  {
    this->length = length;
  }
  void setSpeed(int speed)
  {
    this->speed = speed;
  }
  void setCapacity(int capacity)
  {
    if(capacity % 2 == 0 || capacity % 3 == 0)
    {
      this->capacity = capacity;
    }
    else
    {
      this->capacity = capacity + 1;
    }
  }
  void setCurrentNumRiders(int currentNumRiders)
  {
    this->currentNumRiders = currentNumRiders;
  }
  void setRideInProgress(bool rideInProgress)
  {
    this->rideInProgress = rideInProgress;
  }

  
  int loadRiders(int numRiders)
  {
    if(rideInProgress == false && currentNumRiders + numRiders <= capacity)
    {
      currentNumRiders += numRiders;
      cout << "Riders have been seated successfully." << endl;
      return 0;
    }
    else
    {
      currentNumRiders = capacity;
      cout << "Riders could not be seated." << endl;
      return capacity - (currentNumRiders+numRiders);
      
    }
  }

  int startRide()
  {
    if(rideInProgress == false && currentnumRiders == capacity) 
    {
      rideInProgress = true;
      cout << "Ride has started." << endl;
      return 0;
    }
    else
    {
      cout << "Ride could not be started." << endl;
      return -1;      
    }
  }

void stopRide()
{
  if(rideInProgress == true)
  {
    rideInProgress = false;
    cout << "Ride has stopped." << endl;
  }
}

void unloadRiders()
{
  if(rideInProgress == false)
  {
    currentNumRiders = 0;
    cout << "Riders have been unloaded." << endl;
  }
  else
  {
    cout << "Ride is in progress" << endl;
  }
}

void accelerate()
{
  if(rideInProgress == true)
  {
    speed += (rollNumber % 10);
    cout << "Speed has been increased by " << (rollNumber % 10) << endl;
  }
}

void applyBrakes()
{
  if(rideInProgress == true)
  {
    speed -= (rollNumber / 10);
    cout << "Speed has been decreased by " << (rollNumber / 10) << endl;
  }
}

};

int main()
{
  cout << "RAYYAN MERCHANT-23K-0073" << endl;

  RollerCoaster rollerCoaster1;
  RollerCoaster rollerCoaster2("fun ride", 100, 200, 20);
  rollerCoaster1.loadRiders(10);
  rollerCoaster1.startRide();
  rollerCoaster1.unloadRiders();
  rollerCoaster1.accelerate();
  rollerCoaster1.applyBrakes();
  rollerCoaster1.stopRide();

  //use getters and setters for rollercoaster2;
  rollerCoaster2.setHeight(150);
  rollerCoaster2.setLength(300);
  rollerCoaster2.setSpeed(50);
  rollerCoaster2.setCapacity(30);
  rollerCoaster2.setCurrentNumRiders(10);
  rollerCoaster2.setRideInProgress(true);
  cout << "Name: " << rollerCoaster2.getName() << endl;
  cout << "Height: " << rollerCoaster2.getHeight() << endl;
  cout << "Length: " << rollerCoaster2.getLength() << endl;
  cout << "Speed: " << rollerCoaster2.getSpeed() << endl;
  cout << "Capacity: " << rollerCoaster2.getCapacity() << endl;
  cout << "CurrentNumRiders: " << rollerCoaster2.getCurrentNumRiders() << endl;
  cout << "RideInProgress: " << rollerCoaster2.getRideInProgress() << endl;
  return 0;
  
}
