#include<iostream>
using namespace std;

int calculateLCM(int a, int b)
{
  static int lcm = 0;
  lcm += min(a,b); 
  if(lcm%max(a,b) == 0) 
  {
    return lcm;
  }
  else
  {
    return calculateLCM(a, b);
  }
}

int calculateGCD(int a, int b)   //used chatgpt for this.
{
  if(b == 0)
  {
    return a;
  }
  else
  {
    return calculateGCD(b, a%b);
  }
}

int main()
{
  int a, b;
  cout<<"Enter two numbers: ";
  cin>>a>>b;
  if(b)
  cout<<"LCM of "<<a<<" and "<<b<<" is "<<calculateLCM(a, b)<<endl;
  cout<<"GCD of "<<a<<" and "<<b<<" is "<<calculateGCD(a, b)<<endl;
}
