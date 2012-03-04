
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<climits>

using namespace std;

int main()
{

  //..... Two string A and B of length 'n' and 'm' respectively

  string A,B;

  cout<<":Enter the first string: ";
  cin>>A;
  int n=A.size();
  
  cout<<"Enter the second string: ";
  cin>>B;
  int m=B.size();

  /////....inputs done :)
  
  int dp[n+2][m+2];//....'n+2' and 'm+2' :extra space jus 2 avoid errors

  for(int i=0;i<=n;i++)
    {
      dp[i][0]=0;
    }
  for(int i=0;i<=m;i++)
    {
      dp[0][i]=0;
    }
  //.................dp [][] initialized for "0th col" and "0th row"
  
  for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
	{
	  if(A[i-1]==B[j-1])
	    dp[i][j]=dp[i-1][j-1]+1;
         else
	   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	}
    }
//......dp states built ...res in "dp[n][m]"

cout<<"Length of the LCS is : "<<dp[n][m]<<"\n"; 
  
  
  







return 0;
}
