#include<iostream>
#include<map>
#include<cstdio>
#include<cmath>
#include<climits>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

int n,m;  // n: no. of vertices , m: no. of edges
vector< vector<int> > edge,weight;   // edge: adjacency list ,  weight is the weight of the edges in accordance with adjacency list
vector<int> p;  // parent of the final shortest path of the graph from the defined source

void path(int n)  // function path trace backs the shortest path from the source to the parameter vertex
{
  if(p[n]==-1)    // p[n]=-1 for source..  so when reached source. print value and stop recursion
    {
      cout<<n<<" ";
      return;
    }
 
  path(p[n]);  // recurse for parent and then print current trace
  
  cout<<n<<" ";
}


int main()
{
  cout<<"Enter the no. of vertices: ";
  cin>>n;
  cout<<"Enter the no. of edges: ";
  cin>>m;
  
  edge.resize(n+1);
  weight.resize(n+1);
  
  cout<<"Enter the edges with corresponding weight:\n";
  int a,b,w;
  for(int i=0;i<m;i++)
    {
      cin>>a>>b>>w;
      edge[a].push_back(b);
      weight[a].push_back(w);
    }

  int s;
  cout<<"Enter the source path: ";
  cin>>s;

  //.......  Input taken :)

  int d[n+1];  // d[i]: distance of "i" from source "s" in the shortest path
  p.resize(n+1);

  for(int i=0;i<n;i++)  // initialize
    {
      p[i]=-1;
      d[i]=INT_MAX;
    }
  d[s]=0;   // distance of source from itself = 0


  /*    TOPOLOGICAL SORT TO BE DONE HERE  */
  
  // Refer topological sort


  for(int i=0;i<n-1;i++)   // make n-1 iterations: as after i iterations shortest path of atmost i edges will be discovered and relaxed
    {
      for(int j=0;j<n;j++)   // the order is assumed to be the order after topological sort
	{                          

	  for(int k=0;k<edge[j].size();k++)
	    {
	      a=j;
	      b=edge[j][k];
	      w=weight[j][k];
	      
	      if(d[b]>d[a]+w)   // if relaxation possible.
		{
		  d[b]=d[a]+w;
		  p[b]=a;
		}   
	      
	    }

	}
    }

      cout<<"Now for all vertices, printing the path from the source and thus the cost:\n";
  

      for(int i=0;i<n;i++)
	{
	  path(i);
	  cout<<"\nCost: "<<d[i]<<"\n";
	}



  return 0;
}
