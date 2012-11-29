#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<stack>
#include<vector>
#include<stack>
#include<climits>
#include<algorithm>

using namespace std;
long long B=1;


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

long long crt_(long long n,long long c[],long long b[])
{
  long long res=0ll;

  for(int i=0;i<n;i++)
    B*=b[i];
  
  for(int i=0;i<n;i++)
    {
      long long Bi=B/b[i];
      long long Xi;
      long long tmp;
      tmp=ext_euclidean_itr(Bi,b[i],Xi,tmp);
      res+=(Xi*c[i]*Bi);
    }

  return res;
}


int main()
{

  int n;
  cout<<"Enter the number of equations U want to give: ";
  cin>>n;

  long long c[n+2],b[n+2];
  cout<<"Enter all ci and bi: \n";

  for(int i=0;i<n;i++)
    {
      cout<<"c["<<i<<"]= ";
      cin>>c[i];
      cout<<"b["<<i<<"]= ";
      cin>>b[i];
    }

  //.. input for all equations taken :)
  
  cout<<"One of the solutions for the given set of equation is:"<<crt_(n,c,b)<<"\n";

  cout<<"And the other solutions reside at the distance of: "<<B<<" from the given solution(Z)\n";


  return 0;
}
