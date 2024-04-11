#include<iostream>
#include<cmath>
using namespace std;

const double PI = 3.14159;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void displayProperties() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return PI * radius * radius;
    }
    double perimeter() const override {
        return 2 * PI * radius;
    }
    void displayProperties() const override {
        cout << "Circle Properties:" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override {
        return length * width;
    }
    double perimeter() const override {
        return 2 * (length + width);
    }
    void displayProperties() const override {
        cout << "Rectangle Properties:" << endl;
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
    double perimeter() const override {
        return 4 * side;
    }
    void displayProperties() const override {
        cout << "Square Properties:" << endl;
        cout << "Side: " << side << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class Triangle : public Shape {
protected:
    double base;
    double height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    double area() const override {
        return 0.5 * base * height;
    }
    double perimeter() const override {
        return base + 2 * sqrt(height * height + 0.5 * base * base);
    }
    void displayProperties() const override {
        cout << "Triangle Properties:" << endl;
        cout << "Base: " << base << ", Height: " << height << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

class EquilateralTriangle : public Triangle {
private: 
    double side;
public:
    EquilateralTriangle(double side) : Triangle(side, side) {}
    double area() const override {
        return 0.25 * sqrt(3) * side * side;
    }
    double perimeter() const override {
        return 3 * side;
    }
    void displayProperties() const override {
        cout << "Equilateral Triangle Properties:" << endl;
        cout << "Side: " << side << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimeter: " << perimeter() << endl;
    }
};

int main() {
    int choice;
    double radius, length, width, side, base, height;
    Shape* shape;
    cout << "Welcome to the Geometry Competition Calculator!" << endl;
    do {
        cout << "Please Select a Shape:" << endl;
        cout << "1. Circle" << endl << "2. Rectangle" << endl << "3. Square" << endl << "4. Triangle" << endl << "5. Equilateral Triangle" << endl << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                shape = new Circle(radius);
                break;
            case 2:
                cout << "Enter the length and width of the rectangle: ";
                cin >> length >> width;
                shape = new Rectangle(length, width);
                break;
            case 3:
                cout << "Enter the side of the square: ";
                cin >> side;
                shape = new Square(side);
                break;
            case 4:
                cout << "Enter the base and height of the triangle: ";
                cin >> base >> height;
                shape = new Triangle(base, height);
                break;
            case 5:
                cout << "Enter the side of the equilateral triangle: ";
                cin >> side;
                shape = new EquilateralTriangle(side);
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 6." << endl;
                break;
        }

        if (shape != nullptr) {
            shape->displayProperties();
            cout << "\n";
            delete shape;
            shape = nullptr;
        }
    } while (choice != 6);

    return 0;
}
