/*
Complexity

For initializing: (init):   O(N)
For query: (query):   O(log2 N)
                                   < O(N) , O(log2 N) >
 */
#include<iostream>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<climits>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;


int n;
int a[1000];
int m[2010];

void init(int node,int s,int e)
{
  if(s==e)
    m[node]=s;
  else
    {
      /* Recurse and compute values in the left and right subtree */
      init(2*node,s,(s+e)/2);
      init(2*node+1,(s+e)/2+1,e);

      /* Now on the basis of precomputation (recursion) 
	 choose the smaller index from children */
      if(a[m[2*node]]<=a[m[2*node+1]])
	m[node]=m[2*node];
      else
	m[node]=m[2*node+1];
    }
}


int query(int node,int s,int e,int qa,int qb)
{
  int p1,p2;

  // If the current interval does'nt intersect the query interval
  if((qa>e) || (qb<s))
    return -1;

// If current interval is included in the query interval completely
  if((s>=qa) && (e<=qb))
    return m[node];

  // Compute the minimum in left and right part of interval
  p1=query(2*node,s,(s+e)/2,qa,qb);                            // min index of left subtree 
  p2=query(2*node+1,(s+e)/2+1,e,qa,qb);                        // min index of right subtree


  // Return the pos where the overall minimum is
  if(p1==-1)                                                   // if left subtree range was out of query range
    return m[node]=p2;
  if(p2==-1)                                                   // if right subtree range was out of query range
    return m[node]=p1;
  if(a[p1]<=a[p2])                                             // if left subtree min is smaller than right subtree min  
    return m[node]=p1;

  return m[node]=p2;                                          // if right subtree min is smaller than left subtree min
} 

int main()
{
  cout<<"Enter the no. of elements of array: ";
  cin>>n;

  cout<<"Enter the elements of array:\n";
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
    }

  //..........   Input taken :)

  /* This function initialized the segment tree and does the computation for making it ready for queries */
  init(1,0,n-1);       

  int q;
  cout<<"Enter the no. of queries: ";
  cin>>q;

  for(int tt=0;tt<q;tt++)
    {

      int qa,qb;
      cout<<"Enter the range (qa,qb): ";
      cin>>qa>>qb;

      int res;
      res=query(1,0,n-1,qa,qb);

      cout<<"The required value is: "<<a[res]<<" And is found at: "<<res<<"\n";
    }



  return 0;
}
