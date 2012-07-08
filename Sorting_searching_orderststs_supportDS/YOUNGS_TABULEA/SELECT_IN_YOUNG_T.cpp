/*
Either mutate or need extra copy of the young tabulaeu.
complexity:  O( s*(n+m) )    , where s is the rank of the element to be selected and n,m are dimentions of matrix
 */
#include<iostream>
#include<map>
#include<cstdio>
#include<climits>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

int a[1000][1000];
int n,m;


void swap(int &a,int &b)
{
  a=a+b;
  b=a-b;
  a=a-b;
}

void youngify(int i,int j)
{
  int si=i,sj=j;
  /* get the index of minimum among (i,j) , (i_1,j) and (i,j+1)  */
  if((i+1<n) && (a[i][j]>a[i+1][j]))
    {
      si=i+1;
      sj=j;
    }
  if((j+1<m) && (a[si][sj]>a[i][j+1]))
    {
      si=i;
      sj=j+1;
    }

  /* if the smalles is not (i,j) : present , so changes have to be made */  
  if((si!=i)||(sj!=j))
    { 
      swap (a[i][j],a[si][sj]);   //  swap the smallest to maintain young property and recall it for further depth property maintainance
      youngify(si,sj); 
    }
}

int main()
{
  cout<<"Enter the dimentions of the young tabulea matrix: (  \"n m\"  ) ";
  cin>>n>>m;


  cout<<"Enter the elements(int) of the matrix in the format of young's tabulae: \n";
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
	{
	  cout<<"Enter a["<<i<<"]["<<j<<"]: ";
	  cin>>a[i][j];
	}
    }

  int s;
  cout<<"Enter the rank of the element to be selected: ";
  cin>>s;


  int now=1;
  int sr,scc;

  while(now<=s)
    {
      if(now==s)
	{
	  cout<<"Required value is: "<<a[0][0]<<"\n";;
	  break;
	}
      else  // youngify
	{now++;
	  /*extract min :  analogous to heap */
	  a[0][0]=INT_MAX;  // deleted the smallest element and replaced by infinty
	  
	  /* Now youngify to push down the infinty: to maintain young's property */
	  youngify(0,0);
	 
	}

    }

  /*  Debug  */
  /*
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
	cout<<a[i][j]<<" ";
      cout<<"\n";
    }
  */
  return 0;
}
