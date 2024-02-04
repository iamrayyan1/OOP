#include<iostream>
using namespace std;

void recursiveSwap(int& a, int& b, int swaps)
{
  if(swaps <= 0)
  {
    return;
  }
  else
  {
    int temp = a;
    a = b;
    b = temp;
    recursiveSwap(a, b, swaps-1);
  }
}

int main()
{
  int a, b, swaps;
  cout << "Enter the value of a: ";
  cin >> a;
  cout << "Enter the value of b: ";
  cin >> b;
  cout << "Enter the number of swaps: ";
  cin >> swaps;
  cout << "Before swapping: a = " << a << ", b = " << b << endl;
  recursiveSwap(a, b, swaps);
  cout << "After swapping: a = " << a << ", b = " << b << endl;
  return 0;
}
