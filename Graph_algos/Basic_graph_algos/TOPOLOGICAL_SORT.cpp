#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<climits>
#include<cstdio>

using namespace std;

vector< vector<int> > edge; // edge <directed: a->b >

vector<int> res;  // sorted order of vertices
vector<int> ck;  // check vector  <for checking if the vertice is visited or not>

void dfs(int n)
{
  if(ck[n]==0)
    {
      ck[n]=1;
      
      for(int i=0;i<edge[n].size();i++) // loop for all adjacent nodes
	if(ck[edge[n][i]]==0)	// if not yet visited
	  dfs(edge[n][i]);   
      
      res.push_back(n);   // once the dfs branch returns making sure that all the nodes which depends on this node are viisted: push this node in the result
    }
}

void topological_sort(int n)  //  makes dfs from all nodes <only if the node is not visited yet>
{

  for(int i=0;i<n;i++)  // loop for all vertex indices
    if(ck[i]==0)    // make dfs only if not yet visited
      dfs(i);

  reverse(res.begin(),res.end());  // the result so obtained is oriented from right to left: reverse to change the orientation 
}

int main()
{
  int n; 
  cout<<"Enter the no. of nodes: ";
  cin>>n;

  edge.resize(n+1);
  ck.resize(n+1);
  /* initialize check to 0: not visited for all vertices initially */
  for(int i=0;i<=n;i++)
    ck[i]=0;

  int m;
  cout<<"Enter the no. of edges: ";
  cin>>m;

  cout<<"Enter the edges: \n";
  int a,b;
  for(int i=0;i<m;i++)
    {
      cin>>a>>b;
      edge[a].push_back(b);
    }


  topological_sort(n);

  cout<<"Printing the sorted order:\n";
  for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
  cout<<"\n";

  return 0;
}
