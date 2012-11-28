#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

long long gcd_rec(int a,int b)
{
  if(b==0)
    return a;

  return gcd_rec(b,a%b);
}

long long gcd_itr(long long a,long long b)
{
  while(b)
    {
      int r=a%b;
      a=b;
      b=r;
    }
  return a;
}

int main()
{

  long long a,b;
  cout<<"Enter the 2 numbers whose gcd needed: ";
  cin>>a>>b;

  cout<<"GCD (a,b) _Recursive := "<<gcd_rec(a,b)<<"\n";
  cout<<"GCD (a,b) _Iterative := "<<gcd_itr(a,b)<<"\n";

  return 0;
}
