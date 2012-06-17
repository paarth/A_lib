#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<climits>
#include<cstring>
#include<vector>

using namespace std;

#define Inf INT_MAX

int temp[16],n,ans[16],d;
int cost[16][16];
int dp[1<<16],cur[1<<16];

int calc(int mask,int x)
{
  int ret=0;

  for(int i=0;i<n;i++)
    {
      if(mask & (1<<i))
	{
	  ret+=cost[i][x];
	}

    }
  return ret;
}
 

void fun()
{
  int all=(1<<n)-1;  // all = no. of all possible subsets of the n candidates
  int temp,c,nw;
  
  /* Initialsing dp[] and cur[] : which are part of the dp solution */
  for(int i=0;i<=all;i++)
    {
      dp[i]=Inf;
      cur[i]=-1;
    }
  dp[0]=0;  // dp[0]=0 since no candidates in the subset choosen thus dp value=0

  for(int i=0;i<=all;i++) /// Iterating for all subsets possible
    {
      for(int k=0;k<n;k++) // iterating for all candidates to be excluded and solved for
	{
	  if(!(i & (1<<k)))  // If kth candidate is not present in i(present subset)
	    {
	      c=dp[i]+calc(i,k);  // calc(i,k) gives the sum of the costs of the present(in present subsets) candidates being ranked higher than the kth candidate
	      nw=i|(1<<k); // nw is the new subset including kth candidate

	      if(dp[nw]>c||(dp[nw]==c&&k<cur[nw])) // if the dp[nw] is costlier or the current pointer is pointing to greter than present kth candidate with same dp value update
		{
		  dp[nw]=c;
		  cur[nw]=k;
		}
	    }
         }
     }

      int k;
      k=all;

      for(int i=n-1;i>=0;i--)
	{
	  ans[i]=cur[k]+1;  // +1 is for the reason that the solution format indexing is starting from 1
	
	  k=k & (all-(1<<cur[k])); // excludes kth candidate: same as toggling kth bit to 0
	}
      d=dp[all]; // total distance or the cost is given by dp[all] as all contains all candidates and thus the req.
}



int main()
{
  int t;  // ....  No. of test cases:
  scanf("%d",&t);

  int m; 

  for(int tt=0;tt<t;tt++)
    {

      scanf("%d %d",&m,&n);  // number of voters and number of candidates resp.

      /* initialising cost matrix to 0 */
      for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	  cost[i][j]=0;

      /* Taking input from all voters */
      for(int i=0;i<m;i++)
	{
	  /* Taking the prefered order by each voter */
	  for(int j=0;j<n;j++)
	    scanf("%d",&temp[j]);
	  
	  /* Updating the cost matrix: cost[i][j] gives the number of times i is ranked higher than j */
	  for(int j=0;j<n;j++)
	    for(int k=j+1;k<n;k++)
	      cost[temp[k]-1][temp[j]-1]++;
	}

      fun(); // This function calls the function which is the solution patch

      /* Printing output */
      printf("%d: ",d);
      for(int i=0;i<n;i++)
	printf("%d ",ans[i]);
      printf("\n");
    }

  return 0;
}
