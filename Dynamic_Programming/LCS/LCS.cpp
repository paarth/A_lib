
#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<climits>

using namespace std;

int n,m;

int dp[1005][1005];

void diff(string A,string B,int i,int j)
{
  if(i>0&&j>0&&A[i-1]==B[j-1])
    {
      diff(A,B,i-1,j-1);
      cout<<" "<<A[i-1];
    }
  else
    {
      if(j>0&&(i==0||dp[i][j-1]>=dp[i-1][j]))
	{
	  diff(A,B,i,j-1);
	  cout<<" +"<<B[j-1];
	}
	  else if( i>0 && (j==0||dp[i][j-1]<dp[i-1][j]) )
	    {
	      diff(A,B,i-1,j);
	      cout<<" -"<<A[i-1];
	    }
	  else cout<<"";
    } 
  //  cout<<"\n";
}


string backtrack(string A,string B,int i,int j)
{
  if(i==0||j==0)
    return "";
  else if(A[i-1]==B[j-1])
    {
      return backtrack(A,B,i-1,j-1)+A[i-1];
    }
  else
    {
      if(dp[i][j-1]>dp[i-1][j])
	return backtrack(A,B,i,j-1);
      else
	return backtrack(A,B,i-1,j);
    }
  
}



int main()
{

  //..... Two string A and B of length 'n' and 'm' respectively

  string A,B;

  cout<<":Enter the first string: ";
  cin>>A;
  n=A.size();
  
  cout<<"Enter the second string: ";
  cin>>B;
  m=B.size();

  /////....inputs done :)
    
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
  
//......Here We do backtracks -> getting us one of the possible LCS  
  
  cout<<"One of the LCs may be : "<<backtrack(A,B,n,m)<<"\n";

//..............diff functioned to get diff printed...

  diff(A,B,n,m);




return 0;
}
