
#include<iostream>
#include<map>
#include<cmath>
#include<climits>
#include<algorithm>
#include<stack>
#include<queue>

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



bool fermat(LL p,int loop)
{
  if(p==1)  // 1 is not a prime
    return false;

  srand ( time(NULL) );


  for(int i=0;i<loop;i++)
    {
      // Choose a random integer between 1 and p-1 (inclusive)
      LL a = rand()%(p-1)+1;
      // fun is the function for modular exponentiation.
      if(fun(a,p-1,p)!=1)
	return false;  // pis definitely not prime
    }
  return true;   // p is prime with high probability
}

int main()
{

  int p;
  cout<<"Enter the no. to be tested (primality test): ";
  cin>>p;

  if(fermat(p,1000))
    cout<<"yes "<<p<<" is prime.....   :) \n";
  else
    cout<<"No "<<p<<" is not a prime .....   :( \n"; 


  return 0;
}
