#include<iostream>
#include<string>
using namespace std;

class Appointments
{
private:
  string name;
  string date;
  int duration;
  int cost;
  static int totalAppointments;
  static int totalEarnings;
  static int averageCost;

public:
  Appointments(string name, string date, int duration, int cost) : name(name), date(date), duration(duration), cost(cost) 
  {
    update(cost);
  }

  void display()
  {
    cout << "<--------------------->" << endl;
    cout << "Name: " << name << endl;
    cout << "Date: " << date << endl;
    cout << "Duration: " << duration << endl;
    cout << "Cost: " << cost << endl;
  }

  static int getTotalAppointments()
  {
    return totalAppointments;
  }
  static int getTotalEarnings()
  {
    return totalEarnings;
  }
  static int getAverageCost()
  {
    return averageCost;
  }

  static void update(int cost)
  {
    totalAppointments++;
    totalEarnings += cost;
    if (totalAppointments != 0)
      averageCost = totalEarnings / totalAppointments;
  }

};
int Appointments::totalAppointments = 0;
int Appointments::totalEarnings = 0;
int Appointments::averageCost = 0;

int main()
{
  Appointments p1("Rayyan","21-3-24", 30, 100);
  Appointments p2("simran","21-3-24", 50, 120);
  Appointments p3("rayyy","21-3-24", 60, 150);

  p1.display();
  p2.display();
  p3.display();

  cout << "Total Appointments: " << Appointments::getTotalAppointments() << endl;
  cout << "Total Earnings: " << Appointments::getTotalEarnings() << endl;
  cout << "Average Cost: " << Appointments::getAverageCost() << endl;
}

