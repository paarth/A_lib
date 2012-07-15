#include<map>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<climits>

using namespace std;

string str;
int dp[1000][1000];

int lps(int s,int e)
{
  if(s>e)
    return 0;
  if(s==e)
    return 1;

  if(str[s]==str[e])
    {
      return (2+lps(s+1,e-1));
    }
  else
    {
      return max(lps(s+1,e),lps(s,e-1));
    }

}


int main()
{

  cout<<"Enter the string to be operated on: ";
  cin>>str;

  int n=str.size();
  int res;
  res=lps(0,n-1);

  cout<<"The lenght of the longest palindromic subsequence is: "<<res<<"\n";

  return 0;
}
