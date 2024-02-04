#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
      cout << "Marks of student " << i + 1 << ":\n";

      int marksMaths, marksEnglish, marksScience;

      cout << "Marks in Mathematics: ";
      cin >> marksMaths;

      cout << "Marks in English: ";
      cin >> marksEnglish;

      cout << "Marks in Science: ";
      cin >> marksScience;

      int totalMarks = marksMaths + marksEnglish + marksScience;
      int avgMarks = totalMarks / 3;

      char grade;

      if (avgMarks > 90) 
      {
            grade = 'A';
      } else if (avgMarks >= 80) 
      {
            grade = 'B';
      } else if (avgMarks >= 70) 
      {
            grade = 'C';
      } else if (avgMarks >= 60) 
      {
            grade = 'D';
      } else 
      {
            grade = 'F';
      }

      cout << "Total marks: " << totalMarks <<endl;
      cout << "Average Marks: " << avgMarks <<endl;
      cout << "Grade: " << grade <<endl;
    }

    return 0;
}
