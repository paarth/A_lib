#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<climits>
#include<cstdio>
#include<cmath>

using namespace std;

vector< vector<int> > edge;
bool discovered[10000],processed[10000];
int entry_tim[10000],parent[10000],exit_tim[10000];
int reachable_ancestor[10000];
int tree_out_degree[10000];
int tim;

void process_vertex_early(int pos)
{
  reachable_ancestor[pos]=pos;
}

int edge_classification(int x,int y)
{
  if(parent[y]==x) return 0; // TREE
  if(discovered[y] && !processed[y]) return 1; // BACK
  if(processed[y] && (entry_tim[y]>entry_tim[x])) return 2; //forward
  if(processed[y] && (entry_tim[y]<entry_tim[x])) return 3; // cross
}

void process_edge(int x,int y)
{
  int clss=edge_classification(x,y);
  
  if(clss==0) //...TREE edge
    {
      tree_out_degree[x]+=1;
    }
  else if(parent[x]!=y) // Back
     {
      if(entry_tim[y]<entry_tim[reachable_ancestor[x]])
	reachable_ancestor[x]=y;
    }
}

void process_vertex_late(int v)
{
  bool root;
  int tim_v;
  int tim_parent;
  
  if(parent[v]<1) // test if v is the root
    {
      if(tree_out_degree[v]>1)
	printf("root articulation vertex: %d\n",v);
      return;
    }
  
  root=(parent[parent[v]]<1); /* is parent[v] the root? */
  
  if((reachable_ancestor[v]==parent[v])&&(!root))
    printf("parent articulation vertex: %d\n",parent[v]);
  
  if(reachable_ancestor[v]==v)
    {
      printf("Bbridge articulation vertex: %d\n",parent[v]);
      
      if(tree_out_degree[v]>0)
	printf("bridge articulation vertex: %d\n",v);
    }
  
  tim_v = entry_tim[reachable_ancestor[v]];
  tim_parent = entry_tim[reachable_ancestor[parent[v]]];
  
  if(tim_v < tim_parent)
    reachable_ancestor[parent[v]]=reachable_ancestor[v];
}

void dfs(int pos)   
{
  int y;
  
  discovered[pos]=true;  // mark the node discovered
  
  tim = tim+1;  /// increment time counter by one
  entry_tim[pos]=tim; // update entry time of present node
  
  process_vertex_early(pos);  // initialize the reachable ancestor as itself initially
  
  for(int i=0;i<edge[pos].size();i++) // loop for all adjacent nodes
    {
      y=edge[pos][i]; // y = present adjacent node     
      if(discovered[y]==false)  // if the adjacent node is not yet discovered
	{
	  parent[y]=pos;    // set its parent as present node
	  process_edge(pos,y); 
	  dfs(y); 
	}
      else if(!processed[y]) // if the adjacent node is discovered but not yet finished processing 
	{	  
	  process_edge(pos,y);	      
	}
      
    }
  
  process_vertex_late(pos);  // important function call for the articulation point discovery
  
  /* although no relevance with the present problem... good to find the exit time too */
  tim=tim+1;  
  exit_tim[pos]=tim;
  /*--------------------------------------------------------------------------------- */  

  processed[pos]=true;
}


int main()
{
  int n;  // Number of nodes/vertices
  cout<<"Enter the no. of nodes: ";
  cin>>n;
  
  edge.resize(n+1);
  
  for(int i=0;i<n;i++)
    discovered[i]=false;    
  
  int m; // no. of edges
  cout<<"Enter the no. of edges: ";
  cin>>m;
  
  int a,b;
  cout<<"Enter the edges now:(virtices indexed from 0)\n";
  for(int i=0;i<m;i++)
    {
      cin>>a>>b;
      edge[a].push_back(b);
      edge[b].push_back(a);
    }
  
  //  Input taken :)    
  
  tim=0;  // set universal initial (start) time = 0
  dfs(0); // make dfs starting from vertex endexed 0
  
  
  return 0;
}

