#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>

using namespace std;

int main()
{
  int n;
  cout<<"Enter the no. of denominations we do have: ";
  cin>>n;

  vector<int> a;
  cout<<"Enter the denominations from which the amount is to be made: ";

  int temp;
  for(int i=0;i<n;i++)
    {
      cin>>temp;
      a.push_back(temp);
    }


  sort(abegin(),a.end());   //sort all the denominations 

  int m;
  cout<<"Enter the amount to be made from the given denominations: ";
  cin>>m;

  int dp[m+2];

  dp[0]=0;
  for(int i=1;i<=m;i++)
    dp[i]=INT_MAX;


  for(int i=1;i<=m;i++)   // for bottom_up approach : we go with small numbers first and from them make solution for bigger ones
    {
      for(int j=0;j<n;j++)   // for each number to be made ... iterate over all denominations present to see if using some denomination and previously calculated solution we can do better
	{
	  if(a[j]<=i)   // only if the denomination is less than the amount of total needed to make. 
	    {
	      dp[i]=min(dp[i],dp[i-a[j]]+1);
	    }
	}      


    }

  cout<<"Result= "<<dp[m]<<"\n";



  return 0;
}
