#include<iostream>
#include<map>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
#include<set>
#include<climits>

using namespace std;

double f_expo_rec(double a, long long n)
{
  if(n==0)
    return 1;

  if(n==1)
    return a;

  double tmp;
  tmp=f_expo_rec(a,n/2);
  tmp*=tmp;
  
  if(n&1)
    tmp*=a;

  return tmp;
}

double f_expo_itr(double a, long long n)
{

  double res=1;

  while(n)
    {
      if(n%2)
	res*=a;

      a*=a;
      n/=2;
    }

  return res;
}


int main()
{

  double a;
  long long n;

  cout<<"Enter the double that needs to be raised to a power (a): ";
  cin>>a;
  cout<<"Enter the power to which the given double needs to be raised (n): ";
  cin>>n;


  double res1,res2;

  cout<<"Result from fast expo Recursive: "<<f_expo_rec(a,n)<<"\n";
  cout<<"Result from fast expo Iterative: "<<f_expo_itr(a,n)<<"\n";

  return 0;
}
