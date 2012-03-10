
//                          O(n^3) solution
//........On^2)-> for eliminating one dimention and *O(n) for kadane's algo
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<climits>
#include<cstdio>


using namespace std;

int main()
{

  int n,m;
  cout<<"Enter the dimensions of matrix(n x m): ";
  cin>>n>>m;

  int dp[n+1][m+1];

  for(int i=0;i<m;i++)
    dp[0][i]=0;

  int temp;
  cout<<"Enter the matrix elements: ";
  for(int i=0;i<n;i++)
    {
      for(int j=1;j<=m;j++)
	{
	  scanf("%d",&temp);
	  dp[i][j]=dp[i][j-1]+temp;
	}
    }

  //.....input done....dp[][] stores cumulative of row-wise elements::

  //....getting the max sub-matrix sum

  long long res=(long long)INT_MIN;
  long long buf;


  for(int i=0;i<=m-1;i++)
    {
      for(int j=i+1;j<=m;j++)
	{
	  buf=0;
	  for(int k=0;k<n;k++)
	    {
	      buf+=(dp[k][j]-dp[k][i]);
	      if(buf<0)
		buf=0;
	      else
		res=max(res,buf);
	    }

	}

    }

  printf("Answer: %lld\n",res);




  return 0;
}
