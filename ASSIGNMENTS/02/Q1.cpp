#include<iostream>
using namespace std;

class Square
{
private:
  float sideLength;
  float area;          
  static float allareas;

public:
  Square(float sideLength)
  {
    this->sideLength = sideLength;
  }
  Square() {}

  void calculateArea()
  {
    area = sideLength * sideLength;
    allareas += area;
  }

  float getSideLength()
  {
    return sideLength;
  }
  float getArea()
  {
    return area;
  }
  float getAllareas()
  {
    return allareas;
  }
  void setSideLength(float sideLength)
  {
    this->sideLength = sideLength;
  }
  void setArea(float area)
  {
    this->area = area;
  }
  void setAllareas(float allareas)
  {
    this->allareas = allareas;
  }

  void display()
  {
    cout << "Square Details:" << endl;
    cout << "Side Length: " << sideLength << endl;
    cout << "Area: " << area << endl;
    cout << "Total area: " << allareas << endl << endl;
  }

};

float Square::allareas = 0;

int main()
{
  Square s1(3);
  Square s2(6);
  Square s3(11);
  
  s1.calculateArea();
  s1.display();
  s2.calculateArea();
  s2.display();
  s3.calculateArea();
  s3.display();
  return 0;
  
  
}
