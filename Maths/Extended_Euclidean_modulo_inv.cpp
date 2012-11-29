#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;


void divide(long long a,long long b,long long &q,long long &r)
{
  q=a/b;
  r=a%b;
}

long long mod(long long a,long long b)
{
  return (a+b)%b;
}

long long ext_euclidean_itr(long long a,long long b,long long &x,long long &y)
{
  long long tmp;
  long long q,r;
  long long lx=y=0;
  long long ly=x=1;

  while(b)
    {
      divide(a,b,q,r);
      //........   (a,b) <--- (b,a%b)
      tmp=b;b=a%b;a=tmp;
      // .....  (x,lx) <---  (lx-q*x,x)
      tmp=lx;lx=x-q*lx;x=tmp;
      // .....  (y,ly) <---  (ly-q*y,y)
      tmp=ly;ly=y-q*ly;y=tmp;
    }

  return a;
}

long long gcd(long long a,long long b)
{
  if(!b)
    return a;
  return gcd(b,a%b);
}


int main()
{

  long long a,n;
  long long q,r;

  cout<<"Enter the values of a and n : (such to find :: (a^-1)mod n ): ";
  cin>>a>>n;

  if(gcd(a,n)!=1)
    {
      cerr<<"Well not cool to input these numbers :P \n";
      return 0;
    }

  cout<<"Gcd(a,b)= "<<ext_euclidean_itr(a,n,q,r)<<"\n";
  cout<<"Required answer is : "<<mod(q,n)<<"\n";


  return 0;
}
