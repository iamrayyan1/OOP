#include<iostream>
using namespace std;

class WaterBottle{
  private:
    string company;
    string color;
    float waterCapacity;
public:
    WaterBottle(string company, string color, float waterCapacity) : 
    company(company), color(color), waterCapacity(waterCapacity) {}
    
    string getCompany(){
      return company;
    }
    string getColor(){
      return color;
    }
    float getWaterCapacity(){
      return waterCapacity;  
    }

    void setCompany(string company){
      this->company = company; 
    }
    void setColor(string color){
      this->color = color;
    }
    void setWaterCapacity(float waterCapacity){
      this->waterCapacity = waterCapacity;
    }

    void updateWaterCapacity(float waterConsumed){
      waterCapacity -= waterConsumed;
    }

    
};

int main(){
  WaterBottle waterBottle("Nestle", "Black", 500);
  cout << "Water Bottle Company: " << waterBottle.getCompany() << endl;
  cout << "Water Bottle Color: " << waterBottle.getColor() << endl;
  cout << "Water Bottle Capacity: " << waterBottle.getWaterCapacity() << " ml" << endl;
  float waterConsumed;
  cout << "Enter the amount of water consumed in ml: ";
  cin >> waterConsumed;
  waterBottle.updateWaterCapacity(waterConsumed);
  cout << "Updated Water Bottle Capacity: " << waterBottle.getWaterCapacity() << " ml" << endl;
  return 0;
}
