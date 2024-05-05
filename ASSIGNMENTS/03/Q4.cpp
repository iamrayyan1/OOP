#include <iostream>
using namespace std;

class Drone{
protected:
  float latitude;
  float longitude;
  float altitude;
  float speed;

public:
  Drone(float lat, float lon, float alt, float s) : latitude(lat), longitude(lon), altitude(alt), speed(s) {}
  virtual void adjustAltitude(float alt) = 0;
  virtual void setSpeed(float s) = 0;
};

class Scannable{
  public:
    virtual void scanArea(float radius) = 0;
  
};

class Flyable{
  public:
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float lat, float lon, float alt) = 0;
};

class ReconDrone : public Drone, public Flyable, public Scannable{
  float cameraResolution;
  float maxFlightTime;
public:
  ReconDrone(float lat, float lon, float alt, float s, float cr, float mft) : Drone(lat, lon, alt, s), cameraResolution(cr), maxFlightTime(mft) {}
  void adjustAltitude(float alt) override{
    altitude += alt;
    cout << "Altitude adjusted to " << altitude << "m" << endl;
    if(altitude > 20000){
      cout << "Altitude exceeds maximum limit of 20,000m" << endl;
      cout << "Connection lost!!!" << endl;
    }
  }
  void setSpeed(float s) override{
    speed = s;
    cout << "Speed set to " << speed << "m/s" << endl;
  }
  void takeoff() override{
    cout << "Drone taking off..." << endl;
  }
  void land() override{
    cout << "Drone landing..." << endl;
  }
  void navigateTo(float lat, float lon, float alt) override{
    cout << "Current position: " << latitude << "m, " << longitude << "m, " << altitude << "m" << endl; 
    cout << "Navigating to (" << lat << ", " << lon << ", " << alt << ")" << endl;
    float distance = lat * lon * alt;
    float time = distance / speed;
    cout << "Estimated time to destination: " << time << "s" << endl;
  }
  void scanArea(float radius) override{
    cout << "Scanning area within the radius of " << radius << "m..." << endl;
    int objects = rand() % 10;
    cout << "Objects detected are: " << objects << endl;
    for(int i = 0; i < objects; i++){
      float x = rand() % 100;
      float y = rand() % 100;
      float z = rand() % 100;
      cout << "Object " << i+1 << " coordinates: (" << x << ", " << y << ", " << z << endl;
    }
  }
};

int main(){
  ReconDrone drone(200, 500, 0, 700, 64, 36);
  cout << endl;
  drone.takeoff();
  cout << endl;
  drone.adjustAltitude(1000);
  cout << endl;
  drone.setSpeed(500);
  cout << endl;  
  drone.navigateTo(1500, 170, 1800);
  cout << endl;  
  drone.scanArea(25);
  cout << endl;
  drone.land();
  return 0;
}
  
