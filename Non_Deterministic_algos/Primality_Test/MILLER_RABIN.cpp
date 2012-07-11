#include<iostream>
#include<map>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<climits>
#include<cmath>

using namespace std;
typedef long long LL;

LL mulmod(LL a,LL b,LL c)  // This function gives (a*b)%c taking care of overflow of a*b
{
  LL x=0,y=a%c;

  while(b>0)
    {
      if(b%2==1)
	x=(x+y)%c;
    
      y=(y*2)%c;
      b/=2;
    }
  return x%c;
}

LL fun(LL a,LL b,LL c)  // this function gives (a^b)%c taking care of overflow
{

  if(b==0)
    return 1;

  LL prod=1,temp=1;

  if(b%2==1)
    prod=mulmod(prod,a,c);

  temp=fun(a,b/2,c);

  temp=mulmod(temp,temp,c);

  prod=mulmod(prod,temp,c);
}

bool miller_rabin(LL p,int loop)
{
  if(p<2)
    return false;
  if(p!=2&&p%2==0)
    return false;

  srand ( time(NULL) );

  LL s=p-1;
  while(s%2==0)
    s/=2;

  for(int i=0;i<loop;i++)
    {
      LL a=rand()%(p-1)+1;
      LL temp=s;
      LL mod=fun(a,temp,p);

      while(temp!=p-1 && mod!=1 &&mod!=p-1)
	{
	  mod=mulmod(mod,mod,p);
	  temp*=2;
	}

      if(mod!=p-1 && temp%2==0)
	return false;
    }
  return true;
}

int main()
{
  int p;
  cout<<"Enter the no. to be tested (primality test): ";
  cin>>p;

  if(miller_rabin(p,1000))
    cout<<"yes "<<p<<" is prime.....   :) \n";
  else
    cout<<"No "<<p<<" is not a prime .....   :( \n"; 




  return 0;
}
