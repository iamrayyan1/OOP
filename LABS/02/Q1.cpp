#include<iostream>
using namespace std;

void recursiveSwap(int& a, int& b, int n)
{
  if(n == 0)
  {
    return;
  }
  else
  {
    int temp = a;
    a = b;
    b = temp;
  }
  recursiveSwap(a, b, n-1);
}



int main()
{
  int a, b;
  cout << "Enter the value of a: ";
  cin >> a;
  cout << "Enter the value of b: ";
  cin >> b;
  int n;
  cout << "Enter the number of times to swap: ";
  cin >> n;
  cout << "Before swapping: a = " << a << ", b = " << b << endl;
  recursiveSwap(a, b, n);
  cout << "After swapping: a = " << a << ", b = " << b << endl;
  return 0;
}
