#include<iostream>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<climits>
#include<cstdio>
#include<cstring>

using namespace std;

int med(int a[],int s,int e)
{
  sort(a+s,a+e);
  return a[s+(e-s)/2];
}


int dsel(int a[],int s,int e,int k)
{

  if(e-s+1<=5)
    {
      sort(a+s,a+e);
      return a[s+k-1];
    }


  int md[(e-s)/5+1];
  int temp;
 
  int l=0;
  for(int i=s;i<=e;i+=5)
    {
      temp=med(a,i,i+4);
      md[l++]=temp;
    }

  int mmd;
  mmd=dsel(md,0,(e-s)/5,(e-s+5)/10);

  //.....  now the partition step
  int p,firsthigh;
  // swap(a[e],a[mmd]);

  p=e;
  firsthigh=s;

  for(int i=s;i<=e;i++)
    {
      if(a[i]<mmd)
	swap(a[i],a[firsthigh++]);
    }

  swap(a[firsthigh],a[p]);

  //....  Now firsthigh is the index on the basis of which the partition is made 

  //...  Now decision of the recursion to be made.
  if(s-firsthigh+1>=k)
    {
      if(s-firsthigh+1==k)
	return a[firsthigh];
      else
	return dsel(a,s,firsthigh-1,k);
    }
  else
    {
      return dsel(a,firsthigh+1,e,k-(firsthigh-s+1));
    }
}


int main()
{
  int n;
  
  cout<<"Enter the no. of elements of the array to be selected(kth smallest element) from: ";
  cin>>n;

  int a[n],k;
  cout<<"Enter the value of k to be selected: ";
  cin>>k;

  cout<<"Enter the elements of the array: \n";
  for(int i=0;i<n;i++)
    {
      cout<<"Arr["<<i<<"]: ";
      cin>>a[i];
    }

  //...  Input done :)
  int res;
 res=dsel(a,0,n-1,k);

 cout<<k<<"(k)th smallest in the given array: "<<res<<"\n";

  return 0;
}
