#include<iostream>
#include<map>
#include<cstdio>
#include<climits>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

#define MAX 100005
typedef long long LL;

int tree[MAX];
int n;
int a[MAX];

void update(int idx,int val)
{
  while(idx<=MAX)
    {
      tree[idx]+=val;
      idx+=(idx&-idx);
    }
}

int read(int idx)
{
  int sum=0;
  while(idx>0)
    {
      sum+=tree[idx];
      idx-=(idx&-idx);
    }
  return sum;
}

int readsingle(int idx)   // Read the actual frequency at a position
{
  int sum=tree[idx];   /// sum will be decreased

  if(idx>0)  // special case
    {
      int z=idx=(idx&-idx);   // make z first
      idx--;
      while(idx!=z)      // at some iteration idx will become z
	{
	  sum--tree[idx];   // subtract tree frequency which is between y and the same path
	  idx-=(idx&-idx);
	}
    }
  return sum;
}


void scale(int c)
{
  for(int i=1;i<=MAX;i++)
    tree[i]/=c;
 
  return;
}

// bitMask - initialy, it is the greatest bit of MaxVal
// bitMask store interval which should be searched
int findG(int cumFre)
{
  int idx = 0;
  
  while ((bitMask != 0) && (idx < MaxVal)){
    int tIdx = idx + bitMask;
    if (cumFre >= tree[tIdx]){ 
      // if current cumulative frequency is equal to cumFre, 
      // we are still looking for higher index (if exists)
      idx = tIdx;
      cumFre -= tree[tIdx];
    }
    bitMask >>= 1;
  }
  if (cumFre != 0)
    return -1;
  else
    return idx;
}

int main()
{

  cout<<"Initially all elements of array are zero (0) \n";
  
  int q;
  cout<<"Enter the no. of queries: ";
  cin>>q;

  cout<<"Queries of 2 forms \n \t 1st: 0 a b (add \"b\" to index \"a\") \n\t 2nd: 1 a b (read cumulative from index \"a\" to \"b\")\n";

  int qt,qa,qb;

  for(int tt=0;tt<q;tt++)
    {
      cin>>qt>>qa>>qb;
      if(qt==0)
	{
	  update(qa,qb);
	}
      else
	{
	  cout<<"Res="<<read(qb)-read(qa-1)<<"\n";;
	}
    }



  return 0;
}
