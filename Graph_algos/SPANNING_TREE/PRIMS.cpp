#include<iostream>
#include<map>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<climits>

using namespace std;

int n,m; // n: number of vertices, m: number of edges in the graph
vector< vector<int> > edge,weight;  // edge: adjacency list of given directed graph, weight: is weight of the edges in correspondence with the adjacency list.
bool ck[1000];  // ck : bool to check if that vertex has already been visited or processed
int p[1000];   // p: parent of the vertices in the final spanning tree.
int res;  // res: is the sum of alll edges in the final spanning tree.

struct node  // node struct: for storing one directed edge.
{
  int s,e;
  int w;
};

class mycmp   // class with operator defined to cmp. on weight of the edge as key
{
public:
  bool operator()(const node& l,const node& r) const
  {
    return (l.w<r.w);
  }
};

priority_queue< node , vector< node > , mycmp> q;   // priority_queue of edges with weight of edge as key 
vector< node > res_edge;  // res_edge: list of all edges in the final spanning tree.

int main()
{
  cout<<"Enter the no. of nodes: ";
  cin>>n;
  cout<<"Enter the no. of edges: ";
  cin>>m;

  int a,b,w;
  cout<<"Enter the edges: ";
  for(int i=0;i<m;i++)
    {
      cin>>a>>b>>w;
      edge[a].push_back(b);
      weight[a].push_back(w);
    }
  //......................   Input taken :)

  int d[n+1];  // d: sitance (vertex , instant basis)

  for(int i=1;i<n;i++)  // initialized to infinity except for the 0th node
    d[i]=INT_MAX;

  d[0]=0;  
  ck[0]=true;
  res=0;

  int cnt=1;
  node temp,temp2;

  for(int i=0;i<edge[0].size();i++)  // all adjacent vertices of node[0] is pushed in the priority_queue
    {
      temp.s=0;temp.e=edge[0][i];temp.w=weight[0][i];
      q.push(temp);
    }

  while(cnt<n)  // while all vertices are not visited
    {
      temp=q.top();  // get the smallest node keying on weight of the inserted edges in the prio_queue
      
      if(ck[temp.e]==false)
	{
	  res_edge.push_back(temp); // if the other end of the edge is not visited and since node.s is visited :: can be used for the spanning tree without cycles
	  res+=temp.w;
	  ck[temp.e]=true;
	  cnt++;
	  for(int i=0;i<edge[temp.e].size();i++)
	    {
	      temp2.s=temp.e;
	      temp2.e=edge[temp.e][i];
	      temp2.w=weight[temp.e][i];
	      /* push all adjacent nodes to the one now selected , only those which are not visited (of no use if visited), and pushed in the prio_queue */
	      if(ck[temp2.e]==false)
	      q.push(temp2);
	    }
	  
	}
      
    }



  cout<<"Total sum of the weights of the spanning tree is: "<<res;
  cout<<"The edges of the spanning tree are as follows:\n";
  for(int i=0;i<res_edge.size();i++)
    {
      cout<<res_edge[i].s<<" -> "<<res_edge[i].e<<"\n";
    }

  return 0;
}
