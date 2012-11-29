#include<iostream>
#include<map>
#include<cstdio>
#include<vector>
#include<stack>
#include<set>
#include<algorithm>

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


int gcd_(int a,int b)
{
  if(!b)
    return a;
  return gcd_(b,a%b);
}


int mod_inverse(int a,int b)
{
  long long t1,t2;
  long long g;
  
  g=ext_euclidean_itr((long long)a,(long long)b,t1,t2);

  return mod(t1,b);
}

void linear_dophantine(int a,int b,int c,int &x,int &y)
{
  int d=gcd_(a,b);

  if(c%d)
    {
      x=y=-1;
    }
  else
    {
      x= (c/d) * mod_inverse(a/d,b/d);
      y=(c-a*x)/b;
    }
}

int main()
{
  int a,b,c;
  int x,y;

  cout<<"Enter the values of 'a','b'and 'c': for finding solutions of equation:\n\t\t ax + by = c  : ";
  cin>>a>>b>>c;

  linear_dophantine(a,b,c,x,y);

  cout<<"solution::\n";
  cout<<"x= "<<x<<" y= "<<y<<"\n";



  return 0;
}
