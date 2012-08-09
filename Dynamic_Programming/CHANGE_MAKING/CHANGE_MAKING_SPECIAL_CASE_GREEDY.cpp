/* This Greedy algorithm works fine only if "1" is also one of the given denominations
 so as to if nothing can fit in....  1 will fill it up 
*/
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


  sort(a.begin(),a.end());   //sort all the denominations 

  int m;
  cout<<"Enter the amount to be made from the given denominations: ";
  cin>>m;

  int res=0;

  for(int i=n-1;i>=0&&m>0;i--)
    {
      temp=m/a[i];
      res+=temp;
      m-=(temp*a[i]);
    }

  cout<<"Result= "<<res<<"\n";



  return 0;
}
