#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
  int accountId;
  double balance;
  int* transactionHistory;
  int numTransactions;

public:
  BankAccount(int accountId, double balance, int* transactionHistory, int numTransactions)
  {
    this->accountId = accountId;
    this->balance = balance;
    this->transactionHistory = new int[numTransactions];
    for (int i = 0; i < numTransactions; i++)
    {
      this->transactionHistory[i] = transactionHistory[i];
    }
    this->numTransactions = numTransactions;
  }

};
