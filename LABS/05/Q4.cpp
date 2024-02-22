#include<iostream>
using namespace std;

class BankAccount
{
private:
  int accountNumber;
  string accountHolderName;
  double balance;

public:
  BankAccount(int accountNumber, string accountHolderName, double balance)
  {
    this->accountNumber = accountNumber;
    this->accountHolderName = accountHolderName;
    this->balance = balance;
    
  }

  void deposit(double amount)
  {
    balance += amount;
    cout << "Deposited " << amount << " rupees into the account." << endl;
  }

  void withdraw(double amount)
  {
    if (balance >= amount)
    {
      balance -= amount;
      cout << "Withdrawn " << amount << " rupees from the account." << endl;
    }
    else
    {
      cout << "Insufficient balance. Cannot withdraw." << endl;
    }
  }

  void display()
  {
    cout << "Banck Account Details:" << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Holder Name: " << accountHolderName << endl;
    cout << "Balance: " << balance << " rupees" << endl;
  }

};


int main()
{
  BankAccount accounts[3] = {
    BankAccount(32432, "SIMRAN", 1000), 
    BankAccount(542224, "RAYYY", 59999),
    BankAccount(2525,"HANUU", 43535)
  };

  for (int i = 0; i < 3; i++)
  {
    accounts[i].display();
    accounts[i].deposit(500);
    accounts[i].withdraw(200);
    cout << endl;
    accounts[i].display();
    cout << endl;
  }
  return 0;
  
  
}
