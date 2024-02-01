// Q4: Your task is to implement a basic Student Registration System in C++. Define two
// structures, Register and Student, where Register includes attributes courseId and
// courseName, and Student inherits from Register while having additional attributes
// such as studentId, firstName, lastName, cellNo, and email. Your objective is to
// create an array of Student structures to store data

#include <iostream>
using namespace std;

struct Register
{
  int courseId;
  string courseName;
};
struct Student : public Register
{
  int studentId;
  string firstName;
  string lastName;
  string cellNo;
  string email;
};





int main() 
{
  Student student[5];
  for(int i = 0; i < 5; i++)
    {
      cout<< "Enter student id: ";
      cin>> student[i].studentId;
      cout<< "Enter first name: ";
      cin>> student[i].firstName;
      cout<< "Enter last name: ";
      cin>> student[i].lastName;
      cout<< "Enter cell no: ";
      cin>> student[i].cellNo;
      cout<< "Enter email: ";
      cin>> student[i].email;
      cout<< "Enter course id: ";
      cin>> student[i].courseId;
      cout<< "Enter course name: ";
      cin>> student[i].courseName;    
    }
  for(int i = 0; i < 5; i++)
    {
      cout<< "Student: "<< i+1 << endl;
      cout<< "Student id: "<< student[i].studentId<< endl;
      cout<< "First name: "<< student[i].firstName<< endl;
      cout<< "Last name: "<< student[i].lastName<< endl;
      cout<< "Cell no: "<< student[i].cellNo<< endl;
      cout<< "Email: "<< student[i].email<< endl;
      cout<< "Course id: "<< student[i].courseId<< endl;
      cout<< "Course name: "<< student[i].courseName<< endl;
    }
      
  
  
}
