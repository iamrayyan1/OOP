#include <iostream>
using namespace std;

class Shape {
private:
    int length;
    int breadth;
public:
    Shape(int l, int b) : length(l), breadth(b) {}
    int Area() const {
        return length * breadth;
    }
    friend int operator+(const Shape &obj1, const Shape &obj2);  
};

int operator+(const Shape &obj1, const Shape &obj2) { 
    int area = obj1.Area() + obj2.Area();
    return area;
}

int main() {
    Shape shape1(4, 6);
    Shape shape2(10, 2);
    cout << "Area of shape1: " << shape1.Area() << endl;
    cout << "Area of shape2: " << shape2.Area() << endl;
    cout << "Area of shape1 + shape2: " << (shape1 + shape2) << endl;
    return 0;
}
