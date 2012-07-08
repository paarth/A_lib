/*
Complexity:   O(n^3)
Complexity is same as calling dijkstra's "n" times , but still this algorithm is compact enough and thus practically much better.
This is one of the rare algos. which work better with adjacency matric rather than adjacency list as the presentation of the graph
 */
#include<map>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>

using namespace std;

int n,m;
long long a[1000][1000];

int main()
{
  cout<<"Enter the no. of nodes: ";
  cin>>n;
  cout<<"Enter the no. of edges: ";
  cin>>m;

  for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
      if(i==j)
	a[i][j]=0;
      else      
	a[i][j]=INT_MAX;

  int s,e,w;
  cout<<"Enter the edges with weight: ";
  for(int i=0;i<m;i++)
    {
      cin>>s>>e>>w;
      a[s][e]=w;
    } 

  //.....   Input taken :)

  long long through_k;

  for(int k=0;k<n;k++)
    {
      for(int i=0;i<n;i++)
	{
	  for(int j=0;j<n;j++)
	    {
	      through_k=a[i][k]+a[k][j];
	      if(through_k<a[i][j])
		a[i][j]=through_k;
	    }
	}
    }


  cout<<"Printing All pair shortest path weight:\n";
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
	{
	  if(a[i][j]!=INT_MAX)
	  cout<<"a["<<i<<"]["<<j<<"]: "<<a[i][j]<<"  ";
	  else
	    cout<<"a["<<i<<"]["<<j<<"]: "<<" Not_Reachable ";
	}
      cout<<"\n";
    }



  return 0;
}







