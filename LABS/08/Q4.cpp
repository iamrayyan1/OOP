#include<iostream>
#include<string>
using namespace std;

class Person{
protected:
  string name;
  int age;
public:
  Person(string name, int age) : name(name), age(age) {}
  void display(){
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
  }
};

class Student : public Person{
protected:
  int id;
  int gradeLevel;
public:
  Student(string name, int age, int id, int gradeLevel) : Person(name, age), id(id), gradeLevel(gradeLevel) {}
  void display(){
    Person::display();
    cout << "ID: " << id << endl;
    cout << "Grade Level: " << gradeLevel << endl;
  }
};

class Teacher : public Person{
protected:
  string subject;
  int roomNum;
public:
  Teacher(string name, int age, string subject, int roomNum) : Person(name, age), subject(subject), roomNum(roomNum) {}
  void display(){
    Person::display();
    cout << "Subject: " << subject << endl;
    cout << "Room Number: " << roomNum << endl;
  }
};

class GraduateStudent : public Student, public Teacher{

public:
  GraduateStudent(string name, int age, int id, int gradeLevel, string subject, int roomNum) :     Person(name, age), Student(name, age, id, gradeLevel), Teacher(name, age, subject, roomNum) {}
void display() {
    Person::display();
    cout << "ID: " << Student::id << endl;
    cout << "Grade Level: " << Student::gradeLevel << endl;
    cout << "Subject: " << Teacher::subject << endl;
    cout << "Room Number: " << Teacher::roomNum << endl;
}
};

int main(){
  GraduateStudent p1("Rayyan", 19, 1, 11, "Math", 10);
  p1.display();
}
