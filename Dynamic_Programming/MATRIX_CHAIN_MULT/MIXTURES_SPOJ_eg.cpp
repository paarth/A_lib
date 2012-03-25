#include<cstring>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include<climits>
#include<bitset>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cassert>
 
using namespace std;
#define MAX_S 102

int m[MAX_S][MAX_S],c[MAX_S][MAX_S];
int p[MAX_S];

int main()
{
  int n;
  while(cin>>n)
    {
      for(int i=0;i<n;i++)
	scanf("%d",&p[i]);

      for(int i=0;i<n;i++)
	{
	  c[i][i]=p[i];
	  m[i][i]=0;
	}
      int j;

      for(int l=2;l<=n;l++)
	{
	  for(int i=0;i<=n-l;i++)
	    {
	      j=i+l-1;
	      m[i][j]=INT_MAX;
	      for(int k=i;k<j;k++)
		{
		  int q;
		  q=m[i][k]+m[k+1][j]+c[i][k]*c[k+1][j];
		  //...debug
		  //		  cout<<c[i][k]<<" "<<c[k+1][j]<<"\n";
		  //...............
		  if(q<m[i][j])
		    {
		      m[i][j]=q;
		      c[i][j]=(c[i][k]+c[k+1][j])%100;
		    }

		}



	    }

	}


      printf("%d\n",m[0][n-1]);
    }


  return 0;
}
