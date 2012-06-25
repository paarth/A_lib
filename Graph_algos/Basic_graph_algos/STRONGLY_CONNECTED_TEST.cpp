#include<map>
#include<iostream>
#include<vector>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<cstdio>
#include<cstring>

using namespace std;

int n;
vector<int> ck;

void dfs(vector< vector<int> > edge,int node) // simple dfs 
{

  if(ck[node]==0)  // if the node is not yet visited
    {
      ck[node]=1;  // mark it visited

      for(int i=0;i<edge[node].size();i++)  // loop for all adjacent nodes and do dfs
	dfs(edge,edge[node][i]);

    }
  return;
}


int check(vector< vector<int> > edge)  // To check according to the parameter edge: is the graph connected: all nodes can be reahced from any node say 0
{
  ck.resize(n+1);

  for(int i=0;i<n;i++)  // mark all not visited initially
    ck[i]=0;

  dfs(edge,0); // dfs to visit all reachable nodes

  int flag=1;
  for(int i=0;i<n;i++)  // check if any of the nodes are not visited
    if(ck[i]==0)  // if such node found thus the check fails and thus flag is set to 0 for return
      {flag=0;break;}

  return flag;
}

int main()
{

  cout<<"Enter the no. of nodes: ";
  cin>>n;

  vector< vector<int> > edge,redge; // edge: edges and redge: reverse edges    i.e. if a -> b is there in edge then b-> a will be there in redge
  edge.resize(n+1);
  redge.resize(n+1);

  int m;
  cout<<"Enter the no. of edges: ";
  cin>>m;


  cout<<"Enter the edges now:\n";
  int a,b;  
  for(int i=0;i<m;i++)
    {
      cin>>a>>b;
      edge[a].push_back(b);
      redge[b].push_back(a);
    }



  int c1=check(edge);   // check if all are connected according to the edges given for the graph : making dfs internally
  int res=0;

  if (c1==0)
    cout<<"c1 itself is 0: means the graph is note even connected<unidectly>\n";

  if(c1==1) // only if the graph is connected , the check for reverse edge is required else staright away its not strongly connected
    {
      int c2=check(redge);  // check if the graph is connected according to the reverse edges
      if(c2==1) 
	res=1;
    }   
  
  if(res==1)
    cout<<"The given graph IS strongly connected:\n";
  else
    cout<<"The given graph is NOT strongly connected:\n";


  return 0;

}  
