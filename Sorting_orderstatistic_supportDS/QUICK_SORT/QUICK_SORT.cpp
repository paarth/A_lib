#include<iostream>
#include<map>
#include<algorithm>
#include<cstdio>
#include<set>
#include<vector>
#include<climits>
#include<queue>
#include<stack>

using namespace std;

int partition(int arr[],int l,int r)
{
  int p;  // pivot val :D
  int firsthigh; // divider position for pivot element

  p=r;
  firsthigh=l;

  for(int i=l;i<r;i++)
    {
      if(arr[i]<arr[p])
	swap(arr[i],arr[firsthigh++]);
    }
  swap(arr[firsthigh],arr[p]);

       return firsthigh;
}


void quick_sort(int arr[],int l,int r)
{
  int p;  // pivot val :D

  if(l<r)
    {
      p=partition(arr,l,r);
      quick_sort(arr,l,p-1);
      quick_sort(arr,p+1,r);
    }
}


int main()
{

  int n;
  cout<<"Enter the no. of elements of the array to be sorted: ";
  cin>>n;

  int arr[n];
  cout<<"Enter the elements of the array to be sorted: \n";

  for(int i=0;i<n;i++)
    {
      cout<<"arr["<<i<<"]: ";
      cin>>arr[i];
    }
  //..............   Input Done :D
  quick_sort(arr,0,n-1);


  cout<<"The array after sort:\n";
  for(int i=0;i<n;i++)
    cout<<"arr["<<i<<"]: "<<arr[i]<<"\n";

  return 0;
}
