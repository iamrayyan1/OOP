
#include <iostream>
using namespace std;
int main()
{
  int n;
  cout<<"Enter the size of array: ";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements of array: ";
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];   
  }
  int max=0;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      int area=min(arr[i],arr[j])*(j-i);
      if(area>max)
      {
        max=area;
      }
    }
  }
  cout<<"The maximum area of water is: "<<max;
}
