/*
Complexity of the algorithm:    O(n+m)
 */
#include<map>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<climits>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstring>

using namespace std;

int main()
{

  int n,m;
  cout<<"Enter the dimentions of the young tabulea matrix: (  \"n m\"  ) ";
  cin>>n>>m;


  int a[n][m];

  cout<<"Enter the elements(int) of the matrix in the format of young's tabulae: \n";
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
	{
	  cout<<"Enter a["<<i<<"]["<<j<<"]: ";
	  cin>>a[i][j];
	}
    }

  int s;  // element to be searched.
  cout<<"Enter the element(int) to be searched: ";
  cin>>s;

  //......  Input taken :)


  int sr=0,sc=m-1;    //  sr and sc are searching pointers in matrix (row and col. respectively)
  bool found=false;   // found : true if the entry found else false. Initially false 

  while(sr<n&&sc>=0)   // initial value of sr and sc to point it to right top element
    {
      if(a[sr][sc]==s)   /// if found print and update status breaking the loop.  (asumming distinct entries)
	{
	  cout<<"Entry found at: a["<<sr<<"]["<<sc<<"] \n";
	  found=true;
	  break;
	}
      else if(s<a[sr][sc])  // if element to be searched is smaller move left in the same row.
	{
	  sc--;
	}
      else if(s>a[sr][sc])  // if element to be searched is larger move down in the same column.
	{
	  sr++;
	}
    }


  if(found==false)
    cout<<"Entry not present in the given matrix: \n";

  return 0;
}
