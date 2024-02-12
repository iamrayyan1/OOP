#include<iostream>
#include<string>
using namespace std;

class Calendar
{
  private:
    string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int year;
    string task[12][31];

  public:
    Calendar(int currentYear)
    {
      year = currentYear;
    }

    void addTask(int date, int month)
    {
      if(date > 31 || date < 1)
      {
        cout << "Invalid date" << endl;
      }
      else if(month > 12 || month < 1)
      {
        cout << "Invalid month" << endl;
      }
      else
      {
        cout << "Enter the task: ";
        getline(cin, task[month - 1][date - 1]);
        cout << "Task added successfully" << endl;
      }
      
    }

    void removeTask(int date, int month)
    {
      if(date > 31 || date < 1)
      {
        cout << "Invalid date" << endl;
        return;
      }
      else if(month > 12 || month < 1)
      {
        cout << "Invalid month" << endl;
        return;
      }
      else
      {
        task[month - 1][date - 1] = "";
        cout << "Task removed successfully" << endl;
      }
      
    }

    void displayTasks()
    {
      for(int i = 0; i < 12; i++)
      {
        cout << month[i] << endl;
        for(int j = 0; j < 31; j++)
        {
          if(task[i][j] != "")
          {
            cout << j + 1 << ": " << task[i][j] << endl;
          }
        }
      }
      
    }
    

};


int main()
{
  int year;
  cout << "Enter the current year: ";
  cin >> year;
  Calendar calendar(year);

  int choice;
  do
  {
    cout << "1. Add a task" << endl << "2. Remove a task" << endl << "3. Display tasks" << endl << "4. Exit" << endl;
    cin >> choice;

    switch(choice)
    {
      case 1:
        int date, month;
        cout << "Enter the date: ";
        cin >> date;
        cout << "Enter the month: ";
        cin >> month;
        calendar.addTask(date, month);
        break;
      case 2:
        cout << "Enter the date: ";
        cin >> date;
        cout << "Enter the month: ";
        cin >> month;
        calendar.removeTask(date, month);
        break;
      case 3:
        calendar.displayTasks();
        break;
      case 4:
        cout << "Exiting" << endl;
        break;
      default:
        cout << "Invalid choice" << endl;
    }
    
  } while(choice > 4 || choice < 1);

  return 0;
}

  
