#include<iostream>
#include<string>
using namespace std;

class WeekDays
{
private:
  string Days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  int CurrentDay;

public:
  WeekDays()
  {
     CurrentDay = 1;
  }
  WeekDays(int day)
  {
    if(day > 6)
    {
      CurrentDay = day % 7;
    }
    else
    {
      CurrentDay = day;
    }
  }
    

  string getCurrentDay()
  {
    return Days[CurrentDay];
  }

  string getNextDay()
  {
    return Days[(CurrentDay + 1) % 7];
  }

  string getPreviousDay()
  {
    return Days[(CurrentDay - 1) % 7];
  }

  string getNthDayFromToday(int n)
  {
    return Days[(CurrentDay + n) % 7];
  }


};


int main()
{
  WeekDays weeks; 
  cout << "Current day: " << weeks.getCurrentDay() << endl;
  cout << "Next day: " << weeks.getNextDay() << endl;
  cout << "Previous day: " << weeks.getPreviousDay() << endl;

  int n;
  cout << "Enter the number of days from today: ";
  cin >> n;
  cout << "Nth day: " << weeks.getNthDayFromToday(n) << endl;
  return 0;
  
}
