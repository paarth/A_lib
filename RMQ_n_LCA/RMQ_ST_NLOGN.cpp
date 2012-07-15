/*
Complexity:  < O(NLOGN), O(1) > 
 */
#include<iostream>
#include<map>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<algorithm>
#include<stack>
#include<cmath>
#include<queue>

using namespace std;

int n;

int main()
{
  cout<<"Enter no. of elements of array: ";
  cin>>n;
  
  int a[n+1];
  cout<<"Enter the array elements:\n";
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }

  //...   Input taken :)

  int m[n+1][(int)log2(n)+1];   // i:[0-N]  and j:[0-log(N)]
                                // m[i][j]: min of range with start=i and range length=(2^j)

  /* Initialize min for all indices with length 1 */y
  for(int i=0;i<n;i++)
    m[i][0]=i;

  /* Now RMQ precomputation starts */
  for(int j=1;(1<<j)<=n;j++)             // for lengths 2 to logMax
    {
      for(int i=0;i+(1<<j)-1<n;i++)      // for all i: such that i+2^j-1 is in range
	{
	  if(a[m[i][j-1]]<a[m[i+(1<<(j-1))][j-1]])  // break [i][j] range in two equal log parts and compare for these previously computed log parts
	    m[i][j]=m[i][j-1];
	  else
	    m[i][j]=m[i+(1<<(j-1))][j-1];
	}
    }



  int q;
  cout<<"Enter the no. of queries: ";
  cin>>q;


  for(int tt=0;tt<q;tt++)
    {
      int s,e;
      cout<<"Enter the range (s,e): ";
      cin>>s>>e;

      int res;
      int k;
      k=log2(e-s+1);   // get lower bound of the 2^ range covering the required range.

      if(a[m[s][k]]<=a[m[e-(1<<k)+1][k]])   // compare the two parts covering the whole required range
	res=m[s][k];
      else
	res=m[e-(1<<k)+1][k];

      cout<<"Required value: "<<a[res]<<" And is at: "<<res<<"\n";
    }


  return 0;
}
