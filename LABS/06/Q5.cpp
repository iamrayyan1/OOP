#include<iostream>
#include<string>
using namespace std;

class Course
{
public:
  string code;
  string name;
  int credit_hours;
public:
  Course(string code, string name, int credit_hours) : code(code), name(name), credit_hours(credit_hours) {}
};


class Student
{
private:
  string id;
  string name;
  Course *courses;

public:
  Student(string id, string name) : id(id), name(name) {}

  int enroll(Course course)
  {
    courses[i] = course;
    cout << "Course enrolled: " << course.code << " " << course.name << " " << course.credit_hours << endl;
  }
  int drop(Course course)
  {
    courses[i] = NULL;
    cout << "Course dropped: " << course.code << " " << course.name << " " << course.credit_hours << endl;
  }
  int getTotalCreditHours()
  {
    int total = 0;
    for(int i = 0; i < courses.size(); i++)
    {
      if(courses[i] != NULL)
      total += courses[i].credit_hours;
    }
    return total;
  }
  void printEnrolledCourses()
  {
    for(int i = 0; i < courses.size(); i++)
    {
      if(courses[i] != NULL)
      {
        cout << courses[i].code << " " << courses[i].name << " " << courses[i].credit_hours << endl;
      }
    }
  }

};

int main()
{
  Student s1("A123", "Rayyan");
  Course c1("CS", "Computer Science", 3);
  Course c2("Math", "Mathematics", 3);
  Course c3("Phy", "Physics", 3);
  s1.enroll(c1);
  s1.enroll(c2);
  s1.enroll(c3);
  s1.drop(c2);
  s1.printEnrolledCourses();
  cout << "Total credit hours: " << s1.getTotalCreditHours() << endl;
  
}
