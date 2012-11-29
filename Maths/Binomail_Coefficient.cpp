#include<iostream>
#include<map>
#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
#include<vector>
#include<set>
#include<climits>

using namespace std;

long long nck[1005][1005];
int p;

void prec()
{

  int n=1000;
  for(int i=0;i<=n;i++)
    nck[i][0]=1;
  for(int i=0;i<=n;i++)
    nck[i][1]=i;


  for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=i;j++)
	{
	  nck[i][j]=nck[i-1][j-1]+nck[i-1][j];
	}
    }

  return;
}

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

long long ncr_large_n(int n,int k)
{
  long long res=1;
  long long g;
  long long q,r;

  for(int i=0;i<k;i++)
    {
      res = (res * ((n-i)%p) )%p;
      
      //cout<<"res= "<<res<<"\n";
      // find (i^-1)(mod p) and multiply
      g=ext_euclidean_itr(i+1,p,q,r);
      
      //cout<<"g= "<<g<<"\n";
      res = (res * (mod(q,p) ) )%p;

      //cout<<"res= "<<res<<"\n";
    }
  return res;
}


int main()
{

  prec(); ///...pre-calculation done for finding all nCk in case of small n & k

  int n,k;
  cout<<"Enter the values of n and k :(for finding nCk):: ";
  cin>>n>>k;

  cout<<"So the solution for small n and k :: nCr= "<<nck[n][k]<<"\n";

  cout<<"Now Enter large (may be: Ur wish) 'n' value and small 'k' value: ";
  cin>>n>>k;
  cout<<"Also enter the prime to take modulo of: (nCk % p ) ::";
  cin>>p;
 
  cout<<"So the solution for the new input is: "<<ncr_large_n(n,k)<<"\n";

  return 0;
}
