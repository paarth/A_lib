#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<climits>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>

using namespace std;
typedef long long LL;

/*
  Basic Idea:     
  a*b =
     (2*a)*(b/2)              if b is even and b > 0
     a + (2*a)*((b-1)/2)      if b is odd
     0                        if b = 0
 */
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

/*
  Basic Idea:
  (a2)(b/2)               if b is even and b > 0
  ab = a*(a2)((b-1)/2)    if b is odd
  1                       if b = 0
  
*/
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

int main()
{

  LL a,b,c;
  cout<<"Enter \"a\" , \"b\" and \"c\" (for (a^b)%c): ";
  cin>>a>>b>>c;

  cout<<"\nThe Required Value is: "<<fun(a,b,c)<<"\n";


  return 0;
}
