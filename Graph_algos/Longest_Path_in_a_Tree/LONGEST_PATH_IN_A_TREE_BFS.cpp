#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>

using namespace std;

int ecnt[10001];
queue<int> q;

int main()
{
  int n;  //... No. of nodes of the tree
  scanf("%d",&n);
  
/*....  Adjacenecy List ....*/
  vector< vector<int> > edge;
  edge.resize(n+1);
  
  /* level of all nodes */
  vector<int> level(n+1,0);

  map<int,int> ck; // ck: check if the node is visited or not.
  
  /*  Now enter n-1 edges of the graph  */
  int v1,v2;
  for(int i=0;i<n-1;i++)
    {
      scanf("%d %d",&v1,&v2);
      edge[v1].push_back(v2);
      edge[v2].push_back(v1);
      ecnt[v1]++;
      ecnt[v2]++;
    }
  
  /* starting bfs with start node as 1 and level of that node= 0 */
  q.push(1);
  level[1]=0;

  /* initialize mpos to start node(say 1) and level to 0 */
  int mpos=1,mval=0;
  int temp;
  
  while(!q.empty())  // bfs
    {
      temp=q.front();  // get the front element of queue
      q.pop();
      if(level[temp]>mval)  // if the level of present node is > found: update
	{
	  mval=level[temp];
	  mpos=temp;
	}
      
      for(int i=0;i<ecnt[temp];i++) // loop for all adjacent nodes
	{
	  if((ck[temp]!=edge[temp][i])) //.. if node not visisted yet
	    {q.push(edge[temp][i]);  // push for bfs further
	      ck[edge[temp][i]]=temp;
	      level[edge[temp][i]]=level[temp]+1;
	    }
	}
    }
  
  
  //....got mval and mpos.....required was mpos...
  level.clear();
  ck.clear();

  //start 2nd bfs....
  q.push(mpos);  //  make dfs but strting at the node with previously max level
  level[mpos]=0;
  mval=0;
  
  while(!q.empty())
    {
      temp=q.front();
      q.pop();
      if(level[temp]>mval)
	{
	  mval=level[temp];
	  mpos=temp;
	}
      
      for(int i=0;i<ecnt[temp];i++)
	{
	  if((ck[temp]!=edge[temp][i]))
	    {q.push(edge[temp][i]);
	      ck[edge[temp][i]]=temp;
	      level[edge[temp][i]]=level[temp]+1;
	    }
	}
    }

  printf("%d\n",level[mpos]); // res required
  
  return 0;
} 
