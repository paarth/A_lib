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

void merge(int arr[],int l,int mid,int r)
{
  queue<int> q1,q2;
  
  for(int i=l;i<=mid;i++)
    q1.push(arr[i]);
  for(int i=mid+1;i<=r;i++)
    q2.push(arr[i]);

  int i=l;
  while( !(q1.empty()||q2.empty()) )
    {
      if(q1.front()<q2.front())
	{
	  arr[i++]=q1.front();
	  q1.pop();
	}
      else
	{
	  arr[i++]=q2.front();
	  q2.pop();
	}
    }

  while(!q1.empty())
    {
      arr[i++]=q1.front();
      q1.pop();
    }
  while(!q2.empty())
    {
      arr[i++]=q2.front();
      q2.pop();
    }
}

void merge_sort(int arr[],int l,int r)
{
  int mid;

  if(l<r)
    {
      mid=(l+r)/2;
      merge_sort(arr,l,mid);
      merge_sort(arr,mid+1,r);
      merge(arr,l,mid,r);
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

  merge_sort(arr,0,n-1);

  cout<<"The array after sort:\n";
  for(int i=0;i<n;i++)
    cout<<"arr["<<i<<"]: "<<arr[i]<<"\n";

  return 0;
}
