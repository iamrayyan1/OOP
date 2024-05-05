#include <iostream>
using namespace std;

template <class T> class Pet{
protected:
  string name;
  int age;
public:
  Pet(string n, int a): name(n), age(a){}
  virtual void makeSound() = 0;
  virtual void display(){
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
  }
};

class Dog: public Pet<Dog>{
public:
  Dog(string n, int a): Pet<Dog>(n, a){}

  void makeSound() override{cout << "Woof!" << endl;}
  
  void display() override{
    Pet<Dog>::display();
    cout << "Sound: "; makeSound(); cout << endl;
  }
};


class Bird : public Pet<Bird>{
public:
  Bird(string n, int a): Pet<Bird>(n, a){}
  void makeSound() override{cout << "Chirp!" << endl;}
  
  void display() override{
    Pet<Bird>::display();
    cout << "Sound: "; makeSound(); cout << endl;
  }
};

class Cat : public Pet<Cat>{
public:
  Cat(string n, int a): Pet<Cat>(n, a){}
  void makeSound() override{cout << "Meow!" << endl;}

  void display() override{
    Pet<Cat>::display();
    cout << "Sound: "; makeSound(); cout << endl;
  }
};



int main(){
  Dog dog1("Oscar", 5);
  Bird bird1("Twitter", 2);
  Cat cat1("Rexy", 3);
  Pet<Dog>* d = &dog1;
  Pet<Bird>* b = &bird1;
  Pet<Cat>* c = &cat1;
  cout << "Dog Details: " << endl;
  d->display(); cout << endl;
  cout << "Bird Details: " << endl;
  b->display(); cout << endl;
  cout << "Cat Details: " << endl;
  c->display(); cout << endl;
  
}
