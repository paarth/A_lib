#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<cstdio>
#include<climits>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;

struct edge_node  // edge_node structure: storing s: starting , e: ending vertex and w:weight of the edge;
{
  int s,e;
  int w;
}edge[1000];

int n,m;  // n: no of vertices in the graph, m: no. of edges in the graph given             
int p[1000],rank[1000];  // p is the parent of the set, rank: no. of nodes/vertices pointing to this node or this node parent to.
int res_weight; // weight of the resultant spanning tree.
vector< edge_node > res_edge; // resultant set of edges in tne spanning tree.


bool sortf(edge_node a,edge_node b)  // sort function defining the key of sorting as the weight of the edge.
{
  return (a.w<b.w);
}


void create_set(int x)   // create set by initiallizing 
{
  p[x]=x;
  rank[x]=0;
}

int find_set(int x)  // find the parent of the set it belong to
{
  if(x!=p[x])    // if present node is parent it will point to itself , so if not           
    p[x]=find_set(p[x]);     // recurse while updating the parent.
 
  return p[x];  
}

void merge_set(int x,int y)   // merge two sets with x and y as two nodes in sets respectively.............   without check, check for cycles and loop separately
{
  int px,py;

  px=find_set(x);  // parent of set of x
  py=find_set(y);  // parent of set of y

  /* choose the node parent with greater rank to make it even greater , enhancing the clustoring */
  if(rank[px]>rank[py])
    {
      p[py]=px;  // update parent , as in make it point 
      rank[py]+=rank[px]+1;  // and add the rank to correct after updating the pointing/parent 
    }
  else
    {             // same with nodes in reverse order for condition applied.
      p[px]=py;
      rank[px]+=rank[py]+1;
    }
}


int main()
{
  cout<<"Enter the no. of vertices: ";
  cin>>n;
  cout<<"Enter the no. of edges: ";
  cin>>m;

  for(int i=0;i<n;i++)
    create_set(i);

  cout<<"Enter the edges with weight: \n";
  for(int i=0;i<m;i++)
    {cout<<"Edge"<<i+1<<": ";cin>>edge[i].s>>edge[i].e>>edge[i].w;}

  /* Sort edges on the basis of weight of the edges */
  sort(edge,edge+m,sortf);

  int a,b;
  res_weight=0;
  for(int i=0;i<m;i++)
    {
      a=find_set(edge[i].s);  // parent of set 
      b=find_set(edge[i].e);   

      if(a==b);  // NOP:  if they belong to same set this will create a cycle so skip this edge.
      else
	{
	  merge_set(edge[i].s,edge[i].e);  // merge those two sets 
	  res_weight+=edge[i].w;   // update the resultant spanning tree's weight.
	  res_edge.push_back(edge[i]);  // update the set of edges in the resultant spanning tree.
	}

    }

  cout<<"The resultant spanning tree weighs: "<<res_weight<<"\n";

  cout<<"And the edges in the spanning tree are: \n";
  for(int i=0;i<res_edge.size();i++)
    {
      cout<<res_edge[i].s<<" -> "<<res_edge[i].e<<"\n";
    }


  return 0;
}
