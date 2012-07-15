
/*
Complexity:     < O(N) , O(sqrt(N)) >

pre-processing time: O(N) 
query processing time: O(sqrt(N))
 */
#include<iostream>
#include<map>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<climits>
#include<vector>
#include<cmath>

using namespace std;

int n;

int main()
{
  cout<<"Enter the no. of elemenets in array: ";
  cin>>n;

  int a[n];

  cout<<"Enter the elements of array:\n";
  for(int i=0;i<n;i++)
    cin>>a[i];

  //...   Input taken :)

  int wind_s;
  wind_s = (int)sqrt((double)n);  // window size: size of square root window for memoization for later query

  int m_s;
  m_s=(int)ceil((double)(n)/(double)(wind_s));  // size of the memo. array "m"

  int m[m_s];

  int sml=INT_MAX,smlp=-1;
  for(int i=0;i<n;i+=wind_s)
    {
      sml=INT_MAX;smlp=-1;
      for(int j=0;j<wind_s&&j+i<n;j++)
	{
	  if(sml>a[j+i])
	    {
	      sml=a[i+j];
	      smlp=i+j;
	    }
	}
      m[i/wind_s]=smlp;
    }

  // .... Pre-calc. done :)

  int q;
  cout<<"Enter the no. of queries: ";
  cin>>q;


  for(int tt=0;tt<q;tt++)
    {
      int s,e;   // start and end index of query
      cout<<"Enter start and end index: ";
      cin>>s>>e;
   
      int cs,ce;                                // cs and ce : continuous m[]-indeices (start and end respectively)
      cs=(int)ceil((double)s/(double)wind_s);
      ce=(int)floor((double)e/(double)wind_s);
      cout<<"cs= "<<cs<<" ce= "<<ce<<"\n";


      int res=INT_MAX,resp=-1;
      for(int i=s;i<cs*wind_s;i++)   // from start "s" to continuous start make iteration and find min from a[i]
	{
	  if(res>a[i])
	    {
	      res=a[i];resp=i;
	    }
	}
      for(int i=cs;i<ce;i++)  // in the continuous region find the min from m[i] : reduces the complexity significantly
	{
	  if(res>a[m[i]])
	    {
	      res=a[m[i]];resp=m[i];
	    }
	}
      for(int i=wind_s*(ce);i<=e;i++)  // from continuous end to the end of query "e" index make iteration over a[i[ and find min
	{
	  if(res>a[i])
	    {
	      res=a[i];resp=i;
	    }
	}

      cout<<"Result is : "<<res<<" and is at : "<<resp<<"\n";

    }


  return 0;
}
