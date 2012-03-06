/*
String a transformed to b....
operations can be perfoemed and respective cost: 

1) addition of a character : ca
2) Deletion of a character : cd
3) substitution of a charcter with any character : cs
//........all costs are constants regardless of the initial and 
final phase character
 */
#include<iostream>
#include<cstdio>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<climits>

using namespace std;

int main()
{
  string a,b;
  int cs,cd,ca;
  int n,m;

  cout<<"Enter 1st string: ";
  cin>>a;
  cout<<"Enter 2nd string: ";
  cin>>b;
  n=a.size();
  m=b.size();

  cout<<"Enter the cost of substitution: ";
  cin>>cs;
  cout<<"Enter the cost of deletion: ";
  cin>>cd;
  cout<<"Enter the cost of addition: ";
  cin>>ca;
  //..........input done :)

  ///making 2-d dp[0-n][0-m] :: n-length of a, m-length of b
  int dp[n+1][m+1];

  ////inittialization:

  for(int i=0;i<=n;i++)//..creating empty string out of a
    dp[i][0]=cd*i;//...deletion of all chars
  
  for(int i=0;i<=m;i++)//....creating string b from empty string
    dp[0][i]=cs*i;//........adding all chars
  
  //..............actual dp building -> bottom up approach :simple :D
  for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=m;j++)
	{

	  if(a[i]==b[j])
	    dp[i][j]=dp[i-1][j-1];
	  else
	    {
	      dp[i][j]=min(dp[i-1][j-1]+cs,min(dp[i-1][j]+ca,dp[i][j-1]+cd));
	      //...........Substitution...||..addition..||..deletion....,//
	    }

	}
    }


  cout<<"Ans: i.e. The total levenshtein cost is: "<<dp[n][m]<<"\n";

  return 0;
}
