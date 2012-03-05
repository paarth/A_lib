#include<iostream>
#include<map>
#include<algorithm>
#include<cstdio>
#include<set>
#include<vector>
#include<climits>
#include<queue>
#include<stack>

using namespace std;

int main()
{
  ///......LIS

  int n;
  cout<<"Enter the no. of elements in the sequence: ";
  cin>>n;

  if(!n)
    {
      printf("0\n");
      return 0;
    }

  int a[n+1];//....n+1 to ensure no error of index changing:(0/1) 

  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
  //....input done :)

  int len[n+1],ptr[n+1];
  int resl=0,resp=-1;

  for(int i=0;i<n;i++)
    {
      len[i]=1;
      if(resl<1)
	{
	  resl=1;
	  resp=i;
	}

      ptr[i]=-1;

      for(int j=0;j<i;j++)
	{
	  if(a[j]<=a[i]&&len[j]+1>len[i])
	    {
	      len[i]=len[j]+1;
	      ptr[i]=j;

	      if(resl<len[i])
		{
		  resl=len[i];
		  resp=i;
		}

	    }
	}
    }

    /*.....debug code: glancing

  for(int i=0;i<n;i++)
    cout<<len[i]<<" ";
  cout<<"\n";
  for(int i=0;i<n;i++)
    cout<<ptr[i]<<" ";


   */





  //....we have the result in resl:result length and resp: result end pointer

  cout<<"The lenght of the LIS in the given sequence is: "<<resl<<"\n";
  //......now....backtrack to get one possible LIS

  int start=resp;
  vector<int> res_i;
  while(start>=0)
    {
      res_i.push_back(start);
      start=ptr[start];
    }

  reverse(res_i.begin(),res_i.end());
  //....got the indeices of one of he LIS
  cout<<"One of the possible LIS: ";
  for(int i=0;i<res_i.size();i++)
    {
      cout<<a[res_i[i]]<<" ";
    }
  cout<<"\n";
  ///........................End
  return 0;
}
