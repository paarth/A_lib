#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;

int main()
{
  int n;
  int s,e;

  cout<<"Enter the no. of elements of the array to be sorted: ";
  cin>>n;
  cout<<"Enter the range of the elements: <start> and <end> : ";
  cin>>s>>e;

  int a[n+1];
  int c[e-s+1];

  for(int i=0;i<e-s+1;i++)
    c[i]=0;

  cout<<"Enter the array elements: \n";
  for(int i=0;i<n;i++)
    {
      cout<<"arr["<<i<<"]: ";
      cin>>a[i];
      c[a[i]-s]++;
    }

  for(int i=1;i<e-s+1;i++)
    c[i]=c[i-1]+c[i];

  /*    =====
      debug  
      ======
  cout<<"====================================\n";
  for(int i=0;i<e-s+1;i++)
    cout<<c[i]<<"\n";
  cout<<"====================================\n";
  */

  int res[n+1];  
  for(int i=n-1;i>=0;i--)
    {
      res[c[a[i]-s]-1]=a[i];
	  c[a[i]-s]-=1;
    }

	cout<<"Array after sorting: \n";
      for(int i=0;i<n;i++)
	{
	  cout<<"arr["<<i<<"]: "<<res[i]<<"\n";
	}

  return 0;
}
