#include<iostream>
using namespace std;

bool hasSubsetSum(int arr[], int size, int targetSum)
{
  if(size == 0)
  {
    return (targetSum == 0);
  }
  else
  {
    return (hasSubsetSum(arr, size-1, targetSum) || hasSubsetSum(arr, size-1, targetSum-arr[size-1]));
  }
}




int main()
{
  int n;
  cout<<"Enter the size of the array: ";
  cin>>n;
  int arr[n];
  cout<<"Enter the elements of the array: ";
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int targetSum;
  cout<<"Enter the target sum: ";
  cin>>targetSum;

  if(hasSubsetSum(arr, n, targetSum))
  {
    cout<<"Yes, there is a subset with the given sum."<<endl;
  }
  else
  {
    cout<<"No, there is no subset with the given sum."<<endl;
  }
  return 0;
}
