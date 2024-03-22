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

  BankAccount(const BankAccount& other){
    this->accountId = other.accountId;
    this->balance = other.balance;
    this->numTransactions = other.numTransactions;
    this->transactionHistory = new int[other.numTransactions];
    for (int i = 0; i < other.numTransactions; i++)
    {
      this->transactionHistory[i] = other.transactionHistory[i];
    }
  }

  ~BankAccount()
  {
    delete[] transactionHistory;
  }

  void display()
  {
    cout << "Account ID: " << accountId << endl;
    cout << "Balance: " << balance << endl;
    cout << "Transaction History: ";
    for (int i = 0; i < numTransactions; i++)
    {
      cout << transactionHistory[i] << " ";
    }
    cout << endl;
  }

  void updateTransactionHistory(int* TransactionHistory, int NumTransactions)  
  {
    delete[] transactionHistory;
    transactionHistory = new int[NumTransactions];
    for (int i = 0; i < NumTransactions; i++)
    {
      transactionHistory[i] = TransactionHistory[i];
    }
    numTransactions = NumTransactions;
  }

};

int main()
{
  int transactionHistory1[] = {1300, 2000, 300};
  int transactionHistory2[] = {100, 200, 400};
  BankAccount account1(1, 1000, transactionHistory1, 3);
  BankAccount account2(2, 500, transactionHistory2, 3);
  account1.display();
  account2.display();
  account1.updateTransactionHistory(transactionHistory2, 3);
  account1.display();
  account2.display();
  return 0;
}
