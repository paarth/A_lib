#include<iostream>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdio>
#include<climits>
#include<vector>

using namespace std;


int mpos,mval; // mpos: position at which the max level is found
               // mval: the maximum lele/depth found

bool ck[10010]; // ck: check if the node is visited or not.

/*....  Adjacenecy List ....*/
vector< vector<int> > edge;  // vector of vector for edges


void dfs(int pos,int l)  //.. dfs: ( pos: present node position, l: present node level)
{
  ck[pos]=true;  // mark the node visited
  
  if(l>mval)      // if the level of present node is > found: update
    {
      mpos=pos;
      mval=l;
    }

  for(int i=0;i<edge[pos].size();i++)  // loop for all adjacent nodes
    {
      if(!ck[edge[pos][i]])  //.. if node not visisted yet
	dfs(edge[pos][i],l+1);   // .. make dfs for all adjacent nodes not visted yet
    }

  return;
}


int main()
{
  int n; //... No. of nodes of the tree
  scanf("%d",&n);

  /*....  Adjacenecy List Resized....*/
    edge.resize(n+1);

  /*  Now enter n-1 edges of the graph  */
  int a,b;
  for(int i=0;i<n-1;i++)
    {
      scanf("%d %d",&a,&b);
      edge[a].push_back(b);
      edge[b].push_back(a);
    }
  //.....  Graph input done :)

  mpos=1;mval=0;  //  initialize mpos to start node(say 1) and level to 0

  for(int i=1;i<=n;i++)  // mark all nodes initially unvisited
    ck[i]=false;

  dfs(1,0);  //.. make dfs from the start (say 1) node

  mval=0;  // again initialze the required max level to 0
  for(int i=1;i<=n;i++)
    ck[i]=0;

  dfs(mpos,0);  //  make dfs but strting at the node with previously max level


  printf("%d\n",mval); // res required

  return 0;
}
