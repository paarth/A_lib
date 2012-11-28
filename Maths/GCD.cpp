#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

long long gcd_(int a,int b)
{
  if(b==0)
    return a;

  return gcd_(b,a%b);
}

int main()
{

  long long a,b;
  cout<<"Enter the 2 numbers whose gcd needed: ";
  cin>>a>>b;

  cout<<"GCD (a,b) = "<<gcd_(a,b)<<"\n";

  return 0;
}
