#include<iostream>
#include<map>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<queue>
#include<cmath>
#include<vector>

using namespace std;

int partition(int a[],int s,int e)
{
  int p; //for random pivot index

  /* initialize random seed */
  srand(time(NULL));
  /* gnerate random pivot index */
  p=rand()%(e-s+1);


  //...swap a[p] and a[e]
  swap(a[p],a[e]);

  p=e;
  int firsthigh=s;

  for(int i=s;i<e;i++)
    {
      if(a[i]<a[p])
	swap(a[i],a[firsthigh++]);
    }

  swap(a[firsthigh],a[p]);

  return firsthigh;

}

int select(int a[],int s,int e,int k)
{
  if(s==e)
    return a[s];
 
  int p;  //...for partition index
  p=partition(a,s,e);

  if(k<=p-s+1)
    {
      if(p-s+1==k)
	return a[p];
      else
	select(a,s,p-1,k);
    }
  else
    {
      select(a,p+1,e,k-(p-s+1));
    }

}



int main()
{
  int n;
  cout<<"Enter the no. of elements of the array to be selected from: ";
  cin>>n;

  int k;
  cout<<"Provided k should be <=n\n";
  cout<<"Enter the value of k (for kth min elemnet from the array to be selected from\n : ";
  cin>>k;  


  if(!(k<=n))
    {
      cout<<"k>n....fatal error..terminating.........";
      return 0;
   }

  int a[n];
  cout<<"Enter the array elements: \n";
  for(int i=0;i<n;i++)
    {
      cout<<"Arr["<<i<<"]: ";
      cin>>a[i];
    }


  int res;
  res=select(a,0,n-1,k);  // arguments as finding kth smallest from a[0...(n-1)]

  cout<<k<<"(k)th smallest element of the given array is: "<<res<<"\n";

  return 0;
}
