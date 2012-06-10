/*
  Instead of making 2n-2 comparisons for slecting min and max simultaiously out of an array.
  It can be done in 3(floor(n/2)) comparisons.
*/

#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#include<climits>


using namespace std;

int main()
{
  int n;
  
  cout<<"Enter the no. of elements of the array to find min_max from: ";
  cin>>n;

  int a[n];
  cout<<"Enter the elements of the arrat:\n ";
  for(int i=0;i<n;i++)
    {
      cout<<"Arr["<<i<<"]: ";
      cin>>a[i];
    }
  

  int mn,mx;  //...    these retain the min and max result 
  int i; // This is for the itterator of the soln: loop.

  //...  Initialization :: 
  if(n%2==0)
    {
      if(a[0]<a[1])
	{mn=a[0];mx=a[1];}
      else 
	{mx=a[0];mn=a[1];}
      i=2;
    }
  else
    {
      mn=mx=a[0];
      i=1;
    }

  for(;i<n;i+=2)
    {
      if(a[i]<a[i+1])
	{
	  if(mn>a[i])
	    mn=a[i];
	  if(mx<a[i+1])
	    mx=a[i+1];
	}
      else
	{
	  if(mn>a[i+1])
	    mn=a[i+1];
	  if(mx<a[i])
	    mx=a[i];
	}

    }

  cout<<"\n\nAnswer is: \n\t minimum element:"<<mn<<"  maximum element: "<<mx<<"\n";

  return 0;
}
