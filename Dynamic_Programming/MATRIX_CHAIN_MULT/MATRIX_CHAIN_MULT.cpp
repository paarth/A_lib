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
#define MAX_S 1002


int n; 
int m[MAX_S][MAX_S];//...storing the min cost of A[i..j]
int s[MAX_S][MAX_S];///stores the index where the optimal cost of A[i..j]

//....matrix A[i] has dimentions p[i-1]xp[i] for i=1...n
void matrix_chain_order(int p[])
{
  //..m[i][j]=minimum no. of scalar mult. 
  //..i.e. cost needed to compute the matrix A[i]A[i+1]...A[j]=A[i..j]
  

  //..cost is zero wen multiplying one matrix
  //...initializing with zero
  for(int i=1;i<=n;i++)
    m[i][i]=0;

  for(int L=2;L<=n;L++)//.. L is chain length
    {
      for(int i=1;i<=n-L+1;i++)//..i is start bracket
	{
	  int j=i+L-1;//..j=ending bracket
	  m[i][j]=INT_MAX;
	  for(int k=i;k<=j-1;k++)//.making iteration over the bracketed matrix chain
	    {
	      int q;//. cost of scalar mult.
	      q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
	      if(q<m[i][j])
		{
		  m[i][j]=q;// updating min (better) cost
		  //...updating the optimal cost index
		  s[i][j]=k;
		}
	    }
	}

    }
}


int main()
{
 
  cout<<"Enter the no. of matrices in chain multiplication: ";
  scanf("%d",&n);
  int p[n+1];

  cout<<"Enter p[i-1] p[i] as being dimentions of matrix A[i]:\n";
  cout<<"where p[i] starts with index 0 and A[i] starts with indexing i=1\n";
  for(int i=0;i<=n;i++)
    {
      scanf("%d",&p[i]);
    }
  //....function call to return get the optimal solution 
  matrix_chain_order(p);

  cout<<"Therefore the minimal cost of the given matrix chain mult. is:";
  cout<<m[1][n]<<"\n";

  return 0;
}
