#include<iostream>
#include<map>
#include<stack>
#include<stack>
#include<queue>
#include<algorithm>
#include<climits>
#include<cmath>

using namespace std;

int a[1000];
int fa[1000];
int mu,lmd;
bool nc=false;

int f(int n)
{
  if(n==-1)
    return -1;

  return fa[n];
}

void brent(int x0)
{
  int power;
  int tor,har;  // tor: tortoise   har: hare
                // search successive powers of two
 
  power=1;
  lmd=1;

  tor=x0;
  har=f(x0);

  while(tor!=har)
    {
      if(power==lmd)   // time to update power of two by doubling it
	{
	  tor=har;
	  power*=2;
	  lmd=0;
	}

      har=f(har);
      lmd+=1;

      if(har==-1)
	{
	  nc=true;
	  return;
	}

    }


  /* Find the position of the first repetition of lenght lambda */
  mu=0;
  tor=x0;
  har=x0;

  for(int i=0;i<lmd;i++)
    har=f(har);

  while(tor!=har)
    {
      tor=f(tor);
      har=f(har);
      mu+=1;
    }
}


int main()
{

  int n;
  cout<<"Enter the no. of nodes in the linked list: ";
  cin>>n;


  cout<<"Enter value of each node data and index of the node to which its next points: < val[i], fa[i]>:\n";
  
  for(int i=0;i<n;i++)
    {
      cin>>a[i]>>fa[i];
    }

  //  To find: 1) If there is a cycle in this linked list
  //           2) if cycle there: 
  //                              a) mu: distance from start of the start of cycle
  //                              b) lmd: length of the cycle

  brent(0);

  if(nc)
    cout<<"No cycle detected.... \n";
  else
    cout<<"Thus mu= "<<mu<<" And lemda(lmd)= "<<lmd<<"\n";


  return 0;
}
