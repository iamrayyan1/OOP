#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout<<"Enter number of students: ";
    cin >>n;
    int marksMaths;
    int marksEnglish;
    int marksScience;
    char grade;
    for(int i=0;i<n;i++)
    {
        cout<<"Marks of student: "<<i+1<<"\n";
        cout<<"Marks in Mathematics: ";
        cin>> marksMaths;
        cout<<"Marks in English: ";
        cin>> marksEnglish;
        cout<<"Marks in Science: ";
        cin>> marksScience;
        int totalMarks= marksMaths+marksEnglish+marksScience;
        int avgMarks = totalMarks/3;
        if(avgMarks>90)
        {
            grade = 'A';
        }
        else if(avgMarks>=80 && avgMarks<90)
        {
            grade = 'B';
        }
        else if(avgMarks>=70 && avgMarks<80)
        {
            grade= 'C';
        }
        else if(avgMarks>=60 && avgMarks<70)
        {
            grade = 'D';
        }
        else if(avgMarks<60)
        {
            grade  = 'F';
        }
        cout<<"Total marks: "<<totalMarks<<"\n";
        cout<<"Average Marks: "<<avgMarks<<"\n";
        cout<<"Grade : "<<grade<<"\n\n";
    }
    return 0;
}
