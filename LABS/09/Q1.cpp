#include<iostream>
using namespace std;

const double pi = 3.14;
class Shape{

public:
  double area(double r){
    return 3.14*r*r;
  }
  double area(double l,double b){
    return l*b;
  }
  double area(double a,double b,double c){
    double s = (a+b+c)/2;
  }
  double perimeter(double r){
    return 2*3.14*r;
  }
  double perimeter(double l,double b){
    return 2*(l+b);
  }
  double perimeter(double a,double b,double c){
    return a+b+c;
  }
};

int main(){
  Shape s;
  cout<<"Area of circle: "<<s.area(5)<<endl;
  cout<<"Perimeter of circle: "<<s.perimeter(5)<<endl<<endl;
  cout<<"Area of rectangle: "<<s.area(5,6)<<endl;
  cout<<"Perimeter of rectangle: "<<s.perimeter(5,6)<<endl<<endl;
  cout<<"Area of triangle: "<<s.area(3,4,5)<<endl;
  cout<<"Perimeter of triangle: "<<s.perimeter(3,4,5)<<endl;
  
}
