#include <iostream>
#include <string>
using namespace std;

inline int calculateBattingAverage(int runs, int dismissals)
{
  return runs / dismissals;
}

inline int calculateStrikeRate(int runs, int balls)
{
  return (static_cast<double>(runs) / balls) * 100;
}

int main()
{
  int runs, dismissals, balls;
  cout << "Enter the total number of runs scored: ";
  cin >> runs;
  cout << "Enter the total number of balls faced: ";
  cin >> balls;
  cout << "Enter the number of times player has been dismissed: ";
  cin >> dismissals;
  int battingAvg = calculateBattingAverage(runs, dismissals);
  int sRate = calculateStrikeRate(runs, balls);
  cout << "Batting average: " << battingAvg << endl;
  cout << "Strike rate: " << sRate << "%" << endl;
  
}
