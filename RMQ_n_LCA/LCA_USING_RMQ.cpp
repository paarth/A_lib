#include<iostream>
#include<map>
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
#include<climits>
#include<cmath>
#include<vector>

using namespace std;

int n;                        // no. of vertices in the tree.sy 
vector< vector<int> > edge;   // adjacenecy list
vector<int> etv,etl;   // etv: euler tour value   ,  etl: euler tour level
int fo[1000];          // first occurrence of nodes in euler tour
int pntr=0;

void dfs(int node,int level)
{
  if(fo[node]==-1)
    {
      fo[node]=pntr;                        // mark the first occurence as dfs takes the first visit to this node.
      etv.push_back(node);                  // etv updated for node being visited
      etl.push_back(level);                // etl updated  "
      pntr++;

      for(int i=0;i<edge[node].size();i++)
	{
	  if(fo[edge[node][i]]==-1)         // if the adjacent nodes are not visited 
	    { 
	      dfs(edge[node][i],level+1);  // traverse for adjacent(children as this is a tree) nodes 
	      etv.push_back(node);         // etv updated as the node is revisited after children is visited once
	      etl.push_back(level);        //  same with etl
	      pntr++;
	    }
	}

    }
  return;
}

int main()
{
  cout<<"Enter the no. of nodes of tree: ";
  cin>>n;

  int s,e;
  edge.resize(n);

  /* Taking input of tree edges and updating in edge vector<vector<int>>:: */
  cout<<"Enter edges of tree (n-1):\n";
  for(int i=0;i<n-1;i++)
    {
      cin>>s>>e;
      edge[s].push_back(e);
      edge[e].push_back(s);
    }


  //  make a dfs with start node 0 to get euler tour array
  for(int i=0;i<n;i++)
    fo[i]=-1;

  dfs(0,0);


  for(int i=0;i<etv.size();i++)
    {
      cout<<etv[i]<<" ";
    }
  cout<<"\n";
  for(int i=0;i<etl.size();i++)
    {
      cout<<etl[i]<<" ";
    }
  cout<<"\n";

  cout<<"\nFirst occurence array: \n";
  for(int i=0;i<n;i++)
    cout<<fo[i]<<" ";
  cout<<"\n";

  //  ...   Tables for RMQ ready:  vector<int> etv,etl;  and int[] fo;
  int n=etl.size();
  int m[n+1][(int)log2(n)+1];   // i:[0-N]  and j:[0-log(N)]
                                // m[i][j]: min of range with start=i and range length=(2^j)

  /* Initialize min for all indices with length 1 */
    for(int i=0;i<n;i++)
      m[i][0]=i;

  /* Now RMQ precomputation starts */
  for(int j=1;(1<<j)<=n;j++)             // for lengths 2 to logMax
    {
      for(int i=0;i+(1<<j)-1<n;i++)      // for all i: such that i+2^j-1 is in range
        {
          if(etl[m[i][j-1]]<etl[m[i+(1<<(j-1))][j-1]])  // break [i][j] range in two equal log parts and compare for these previously computed log parts
            m[i][j]=m[i][j-1];
          else
            m[i][j]=m[i+(1<<(j-1))][j-1];
        }
    }
  
  //........   Pre-processing for RMQ done :)
  
  int q;
  cout<<"Enter the no. of queries: ";
  cin>>q;
  
  for(int tt=0;tt<q;tt++)
    {
      
      int qa,qb;
      cout<<"Enter the two node ID's to get LCA of: ";
      cin>>qa>>qb;
      
      int sa,sb;
      
      sa=fo[qa];
      sb=fo[qb];
      
      
      //  ..  Now RMQ to be done in range sa and sb for min in vector: etl
      
      int res;
      int k;
      
      k=log2(sb-sa+1);   // get lower bound of the 2^ range covering the required range                                                                            
      if(etl[m[sa][k]]<=etl[m[sb-(1<<k)+1][k]])   // compare the two parts covering the whole required range                   
	res=m[sa][k];                                                                     
      else                                                                               
        res=m[sb-(1<<k)+1][k];     
      
      // ....  RMQ done and res retains resultant pointer , etv of which contains the node id of required LCA
      

      cout<<"The required solution is: "<<etv[res]<<"\n";
      
    }
  
  return 0;
}
