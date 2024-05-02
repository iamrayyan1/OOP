#include <iostream>
using namespace std;

class Account{
protected:
  int accountNumber;
  double balance;

public:
  Account(int accNum, double bal) : accountNumber(accNum), balance(bal){}

  int getAccountNumber(){return accountNumber;}
  double getBalance(){return balance;}

  virtual void deposit(double amount) = 0;
  virtual void withdraw(double amount) = 0;
  virtual void calculateInterest() = 0;
};

class savingsAccount : public Account{
  double interestRate;
public:
  savingsAccount(int accNum, double bal, double intRate) : Account(accNum, bal), interestRate(intRate){}

  void deposit(double amount){
    balance += amount;
  }
  void withdraw(double amount){
    if(balance - amount >= 0){
      balance -= amount;
    }
  }
  void calculateInterest(){
    balance += balance * interestRate;
  }
};

class currentAccount : public Account{
  double overdraftLimit;
  double interestRate;
public: 
  currentAccount(int accNum, double bal, double overdraft, double interestRate) : Account(accNum, bal), overdraftLimit(overdraft), interestRate(interestRate) {}

  void deposit(double amount){
    balance += amount;
  }
  void withdraw(double amount){
    if(balance - amount >= 0){
      balance -= amount;
    }
  }
  void calculateInterest(){
    balance += balance * interestRate;
  }
};
int main(){
  currentAccount acc1(123, 1000, 500, 0.23);
  savingsAccount acc2(456, 2000, 0.05);
  Account *ptr = &acc1;
  ptr->deposit(500);
  ptr->withdraw(200);
  ptr->calculateInterest();
  cout << "Current account balance: " << ptr->getBalance() << endl;
  ptr = &acc2;
  ptr->deposit(1000);
  ptr->withdraw(500);
  ptr->calculateInterest();
  cout << "Savings account balance: " << ptr->getBalance() << endl;
}
