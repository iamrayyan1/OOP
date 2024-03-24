#include<iostream>
#include<string>
using namespace std;

class Position{
private:
  int x;
  int y;
  int z;
public:
  Position(int x, int y, int z) : x(x), y(y), z(z) {}
  void display(){
    cout << "X: " << x << endl;
    cout << "Y: " << y << endl;
    cout << "Z: " << z << endl;
  }
};

class Health{
private:
  int health;
public:
  Health(int health) : health(health) {}
  void display(){
    cout << "Health: " << health << endl;
  }
};

class Character : public Position, public Health{
private:
  string name;
public:
  Character(int x, int y, int z, int health, string name) : Position(x, y, z), Health(health), name(name) {}
  void display(){
    cout << "Name: " << name << endl;
    Health::display();
    Position::display();
  }

};


int main(){
  Character p1(1, 1, 5, 100, "rayyan");
  p1.display();
}
