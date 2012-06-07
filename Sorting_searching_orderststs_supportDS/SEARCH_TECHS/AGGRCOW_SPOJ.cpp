#include<iostream>
#include<algorithm>
#include<map>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;

#define MAX 1000050

int s[MAX];

int possible(int d,int n,int c) //... Function to check is the given solution is valid
{
  int cnt=1;
  for(int b=0,i=1;i<n&&cnt<c;i++)
    {
      if(s[i]-s[b]>=d) {cnt++;b=i;}
    }
  if(cnt>=c)
    return 1;
  
  return 0;
}

int main()
{
  int t;  //  number of test cases
  scanf("%d",&t);

  int n,c;   //  number of stalls and count of cows required to be distributed
 
  for(int tt=0;tt<t;tt++)
    {

      scanf("%d %d",&n,&c);

      for(int i=0;i<n;i++)
	scanf("%d",&s[i]);

      //.....sorting the stall points:
      sort(s,s+n);

      //....  binary search for the optimal soln:

      int lo=1,hi=s[n-1]-s[0]+1;
      int mid;

      while(lo<hi)
	{
	  mid=(lo+hi)/2;
	  if(possible(mid,n,c))
	    lo=mid+1;
	  else
	    hi=mid;
	}

      printf("%d\n",lo-!possible(lo,n,c));
    }

  return 0;
}
