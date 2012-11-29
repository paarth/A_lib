#include<iostream>
#include<map>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

long long fib[1000000];

long long fibo_(int n)
{

  if(fib[n]!=0)
    return fib[n];

  if(n==1)
    return 1;
  if(n==2)
    return 1;
  if(n==3)
    return 2;

  long long p1,p2,res;
  long long p11,p22,p33;

  if(n&1)
    {
      p1=fibo_(n/2);
      p2=fibo_(n/2+1);
      res=p1*p1+p2*p2;
    }
  else
    {
      p11=fibo_(n/2-1);
      p33=fibo_(n/2+1);

      res=(p33*p33)-(p11*p11);
    }

  return res;
}



int main()
{

  int n;
  cout<<"Enter the value of n: such that nth fibo. number is required: ";
  cin>>n;

  if(n==1)
    {
      cout<<"Fibo(1)="<<1<<"\n";
      return 0;
    }
  else if(n==2)
    {
      cout<<"Fibo(2)="<<1<<"\n";
      return 0;
    }
  else if(n==3)
    {
      cout<<"Fibo(3)="<<2<<"\n";
      return 0;
    }
  else
    {
      cout<<"Fibo("<<n<<")="<<fibo_(n)<<"\n";
    }

  return 0;
}
