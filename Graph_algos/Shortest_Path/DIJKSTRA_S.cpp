#include<map>
#include<cstdio>
#include<iostream>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;
typedef pair<int,int> pr;

int n,m; // n: no of vertices ,  m: no of edges
vector< vector<int> > edge,weight;  //  edge: adjacency list ,  weight: weight of edges in accordance with the adjacenecy list

set< pair<int,int> > st;  // set for the implementation of O(logn) key decrease in prio_queue
set< pair<int,int> >::iterator it;
vector<int> dist,parent; // dist[i]: relaxed dist of node "i" from its parent,till now
vector<bool> intree; // to check whether enetred in tree or not

void path(int n)  // function path trace backs the shortest path from the source to the parameter vertex
{
  if(parent[n]==-1)    // p[n]=-1 for source..  so when reached source. print value and stop recursion
    {
      cout<<n<<" ";
      return;
    }
 
  path(parent[n]);  // recurse for parent and then print current trace
  
  cout<<n<<" ";
}



int main()
{
  cout<<"Enter the no. of nodes: ";
  cin>>n;
  cout<<"Enter the no. of edges: ";
  cin>>m;


  edge.resize(n+1);
  weight.resize(n+1);
  dist.resize(n+1);
  parent.resize(n+1);
  intree.resize(n+1);

  cout<<"Enter the edges with weights: \n";
  int a,b,w;

  for(int i=0;i<m;i++)
    {
      cin>>a>>b>>w;
      edge[a].push_back(b);
      weight[a].push_back(w);
    } 

  // .......  Input taken  :)
  int cur,nxt,wt,dst;

  /*   Initialization    */
  for(int i=0;i<n;i++)
    {
      intree[i]=false;
      dist[i]=INT_MAX;
      parent[i]=-1;
    }

  char dbg;
  int s;
  int temp;
  cout<<"Enter the source node id: ";
  cin>>s;

  dist[s]=0;
  st.insert(make_pair((int)0,(int)s));  // as dist of s from s = 0, thus update customised prio_queue , implemented using set "st"
  cur=s;
  for(int i=1;i<n;i++)   // for rest vertices , initally their dist = infinity
    st.insert(make_pair(INT_MAX,i));
  

  while(intree[cur]==false)
    {
      intree[cur]=true;  // marked as entered tree.

      for(int i=0;i<edge[cur].size();i++)   // for all adjacent vertices of current node
	{
	  nxt=edge[cur][i];
	  wt=weight[cur][i];

	  if(dist[nxt]> dist[cur]+wt)
	    {
	      
	      it=st.find(make_pair(dist[nxt],nxt));  // get iterator to the previously existing entry
	      
	      st.erase(it);  // erase this , as the updated value would be inserted then, thus as such replaced or decreased the value of its key
	      
	      dist[nxt]=dist[cur]+wt;  
	      parent[nxt]=cur;  // mark parent
	      
	      st.insert(make_pair(dist[nxt],nxt));  // insert updated
	    }
	  
	}
      
      // find the vertex with smallest dist value and not into the tree
      do
	{
	  cur=((*st.begin()).second);
	  
	  if(intree[cur]==true)
	    st.erase(st.begin());

	}while(intree[cur]==true&&!st.empty());
      
      
    }
  
      cout<<"Now for all vertices, printing the path from the source and thus the cost:\n";

  for(int i=0;i<n;i++)
    {
      cout<<"---------"<<i<<"---------------\nPath: ";
      path(i);
      cout<<"\nCost: "<<dist[i]<<"\n";
    }
  
  
  
  return 0;
}
