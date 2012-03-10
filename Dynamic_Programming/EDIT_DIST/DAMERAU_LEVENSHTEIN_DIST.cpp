#include<iostream>
#include<map>
#include<set>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<climits>
#include<cstdio>

using namespace std;

int main()
{
  string a,b;
  cout<<"Enter source string: ";
  cin>>a;
  cout<<"Enter goal/destination string: ";
  cin>>b;

  int n,m;
  n=a.size();
  m=b.size();

  int h[n+2][m+2];
  int INF=n+m+2;


  //...building the 
  h[0][0]=INF;

  for(int i=1;i<=n;i++)
    { 
      h[i+1][0]=INF;
      h[i+1][1]=i;
    }

  for(int i=0;i<=m;i++)
    {
      h[0][i+1]=INF;
      h[1][i+1]=i;
    }

  int C='z'+1;
  int DA[C];
  for(int i=0;i<C;i++)
    DA[i]=0;


  for(int i=1;i<=n;i++)
    {
      int DB=0;
      for(int j=1;j<=m;j++)
	{
	  int i1,j1;
	  i1=DA[b[j-1]-'a'];
	  j1=DB;
//................................	  
	  int d;
	  if(a[i-1]==b[j-1])
	    d=0;
	  else
	    d=1;
//................................
	  h[i+1][j+1]=min(h[i][j]+d,h[i+1][j]+1);
	  h[i+1][j+1]=min(h[i+1][j+1],h[i][j+1]+1);
	  h[i+1][j+1]=min(h[i+1][j+1],h[i1][j1]+(i-i1+1)+(j-j1+1)+1);
	}
      DA[a[i-1]-'a']=i;
    }
  printf("%d\n",h[n+1][m+1]);

  return 0;
}
