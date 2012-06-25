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

void dfs(vector< vector<int> > edge,int node)
{

  if(ck[node]==0)
    {
      ck[node]=1;

      for(int i=0;i<edge[node].size();i++)
	dfs(edge,edge[node][i]);

    }
  return;
}


int check(vector< vector<int> > edge)
{
  ck.resize(n+1);

  for(int i=0;i<n;i++)
    ck[i]=0;

  dfs(edge,0);

  int flag=1;
  for(int i=0;i<n;i++)
    if(ck[i]==0)
      {flag=0;break;}

  return flag;
}

int main()
{

  cout<<"Enter the no. of nodes: ";
  cin>>n;

  vector< vector<int> > edge,redge;
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



  int c1=check(edge);
  int res=0;

  if (c1==0)
    cout<<"c1 itself is 0: means the graph is note even connected<unidectly>\n";

  if(c1==1)
    {
      int c2=check(redge);
      if(c2==1)
	res=1;
    }   
  
  if(res==1)
    cout<<"The given graph IS strongly connected:\n";
  else
    cout<<"The given graph is NOT strongly connected:\n";


  return 0;

}  
