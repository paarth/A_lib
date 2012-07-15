#include<map>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<climits>

using namespace std;

string str;                   // string to be operated upon          

int lps(int s,int e)
{
  if(s>e)                    // if lps query goes out of range
    return 0;
  if(s==e)                   // if only single character in lps query range
    return 1;

  if(str[s]==str[e])         // if the first and last characters are same , append both in the solution and recurse for the substring excluding both
    {
      return (2+lps(s+1,e-1));  
    }
  else                        // if the first and last charcter are not same , then it is max of either excluding first or last
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
