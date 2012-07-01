#include<iostream>
#include<map>
#include<stack>
#include<cstdio>
#include<climits>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

vector< vector<int> > edge;   // vector of vector : adjacency list
bool discovered[1000],processed[1000];  // discovered: 1 if visited once, processed: 1 if all successors processed
int entry_tim[1000],parent[1000],exit_tim[1000]; 
int tim;  // universal time
int low[1001],scc[1001];  // low: oldest node in the strobgly connected component, scc: The index of the strongly connected component in which this node lies.
stack<int> active;  // stack to store the active nodes in consideration
int component_found;  // number of strongly connected components found.
int n;  // Number of nodes/vertices
vector< vector<int> > res; // Final result.    :D

void process_vertex_early(int pos)  // push the node in consideration just now activated in the stack
{
  active.push(pos);
}

int edge_classification(int x,int y)   // get the edge classification
{
  if(parent[y]==x) return 0; // TREE
  if(discovered[y] && !processed[y]) return 1; // BACK
  if(processed[y] && (entry_tim[y]>entry_tim[x])) return 2; //forward
  if(processed[y] && (entry_tim[y]<entry_tim[x])) return 3; // cross
}

void process_edge(int x,int y)   // updating low[x] based on the type of edge and entry time conditions.
{
  int clss;    /* edge class: which class of edges do this edge belong to */

  clss=edge_classification(x,y);

  if(clss==1)  // If class is BACK
    {
      if(entry_tim[y]<entry_tim[low[x]])
	low[x]=y;
    }
  if(clss==3)  // If class is CROSS
    {
      if(scc[y]==-1)   /* component not yet assigned */
	if(entry_tim[y]<entry_tim[low[x]])
	  low[x]=y;
    }
}

void pop_component(int v)
{
  int t;  /* vertex placeholder */

  component_found+=1;  // increment this count as one more strongly connected component discovered.


  scc[v]=component_found;  // assign the present node the SC_number

  /* pop and update scc till the range of this SC and onother SC recognized */
  //-------------------------------------------//
  t=active.top(); 
  active.pop();

  while(t!=v)
    {
      scc[t]=component_found;
      t=active.top();
      active.pop();
    }
  //--------------------------------------------//
}

void process_vertex_late(int v)   //  if after processing , low[v]=v then this is new SC
{
  if(low[v]==v)  // edge(parent[v],v) cuts  off scc
    {
      pop_component(v);
    }

  if(entry_tim[low[v]]<entry_tim[low[parent[v]]])  // update parent if a new SC is recognized
     low[parent[v]]=low[v];
}

void dfs(int pos)
{
  int y;

  discovered[pos]=true;  // visited bool

  tim=tim+1;
  entry_tim[pos]=tim;  // entry time noted

  process_vertex_early(pos);  

  for(int i=0;i<edge[pos].size();i++)
    {
      y=edge[pos][i];
      if(discovered[y]==false)
	{
	  parent[y]=pos;
	  process_edge(pos,y);
	  dfs(y);
	}
      else if (!processed[y])
	process_edge(pos,y);

    }

  process_vertex_late(pos);

  tim=tim+1;
  exit_tim[pos]=tim;

  processed[pos]=true;
}

  void strong_components()
  {
    for(int i=0;i<n;i++)
      {
	low[i]=i;  // Initialize all vertices as seperate SCC
	scc[i]=-1; /// Initialize all vertices with current SCC number -1 : as not been yet assigned
      }

    component_found=0;  // iniitally no SCC found

    for(int i=0;i<n;i++)
      if(discovered[i]==false)
	dfs(i);
  }

int main()
{
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
      //edge[b].push_back(a);
    }
  
  //  Input taken :)    
  
  tim=0;  // set universal initial (start) time = 0
  strong_components();

  /*
  for(int i=0;i<n;i++)
    cout<<"vectex["<<i<<"]: "<<scc[i]<<"\n";
  */

  res.resize(component_found);
  for(int i=0;i<n;i++)
    {
      res[scc[i]-1].push_back(i);
    }

  cout<<"Now printing the strongly connected components with the vertices including: \n";
  for(int i=0;i<component_found;i++)
    {
      cout<<"S_component"<<i+1<<": ";
      for(int j=0;j<res[i].size();j++)
	{
	  cout<<res[i][j]<<" ";
	}
      cout<<"\n";
    }



  return 0;
}
