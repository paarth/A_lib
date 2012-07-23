#include<map>
#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
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

void floyd(int x0)
{

  int tor,har; //tor: tortoise   and har:  hare   
               // finding a repitition x_mu = x_2mu, hare moves twice as quickly as the tortoise

  tor=f(x0);
  har=f(f(x0));

  while(tor!=har)
    {
      tor=f(tor);
      har=f(f(har));
      if(har==-1||tor==-1)
	{
	  nc=true;
	  return;
	}
    }

  // at this point the distance of present meeting point from x0 is divisible by the cycle lenth in 
  // addition the mod od the distance from the start of the cycle, so tortoise made to set at x0
  //  and both moved one step at a time and thus will meet at the start of the cycle.

  mu=0;
  tor=0;

  while(tor!=har)
    {
      tor=f(tor);
      har=f(har);
      mu+=1;
    }

  // now when the start of the cycle is also obtained this part pf code finds the lenght of the cycle
  // so hare moves while tortoise stays and thus meet again after travelling cycle length

  lmd=1;
  har=f(tor);

  while(tor!=har)
    {
      har=f(har);
      lmd+=1;
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


  floyd(0);
  if(nc)
    cout<<"No cycle detected.... \n";
  else
    cout<<"Thus mu= "<<mu<<" And lemda(lmd)= "<<lmd<<"\n";
    
  
  return 0;

}
