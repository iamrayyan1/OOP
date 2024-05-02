#include <iostream>
using namespace std;

class convert{
protected:
  float val1;
  float val2;
public:
  convert(int v1, int v2) : val1(v1), val2(v2){}
  virtual float compute() = 0;
};

class l_to_g : public convert{
public:
  l_to_g(int v1, int v2) : convert(v1, v2){}
  float compute() override{
    return val2 = val1 * 0.264172;  // 1 liter = 0.264172 gallons (took from google)
  }
};


class f_to_c : public convert{
public:
  f_to_c(int v1, int v2) : convert(v1, v2){}
  float compute() override{
    return val2 = (val1 - 32) * 5 / 9;  // 1 Fahrenheit = (5/9) * (Celsius - 32) (took from google)
  }
};


int main(){
  l_to_g obj1(4, 0);
  f_to_c obj2(70, 0);

  convert* ptr = &obj1;
  cout << "4 liters to gallons: " << ptr->compute() << endl;
  ptr = &obj2;
  cout << "70 Fahrenheit to Celsius: " << ptr->compute()<< endl;
  return 0;
}
  
