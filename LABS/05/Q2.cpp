#include<iostream>
using namespace std;

class LoanHelper
{
private:
  float interestRate;
  float Amount;
  int months;

public:
  LoanHelper(float interestRate, float Amount, int months) : interestRate(interestRate), Amount(Amount), months(months) 
  {
    if(interestRate < 0 || interestRate > 0.5)
    {
      cout << "Invalid interest rate" << endl;
      return;
    }
  }

  float calculateMonthlyPayment()
  {
    float monthlyPayment = Amount / months;
    float interest = monthlyPayment * interestRate;
    monthlyPayment += interest;
    return monthlyPayment;
  }


};

int main()
{
  float interestRate;
  float Amount;
  int months;

  cout << "Enter the interest rate(0-0.5%): ";
  cin >> interestRate;
  cout << "Enter the loan amount: ";
  cin >> Amount;
  cout << "Enter the number of months: ";
  cin >> months;
  LoanHelper user1(interestRate, Amount, months);
  cout << "You have to pay " << user1.calculateMonthlyPayment() << "every month for " << months << "months to repay your loan" << endl;

}
