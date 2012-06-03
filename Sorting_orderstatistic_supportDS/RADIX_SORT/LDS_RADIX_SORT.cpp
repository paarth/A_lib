#include<iostream>
#include<map>
#include<set>
#include<algorithm>
#include<cstring>
#include<climits>
#include<vector>
#include<cstdio>
#include<stack>
#include<queue>

using namespace std;

void lds_radix_sort(int a[],int n)
{

  int tmax;  //..  maximum element of the array
  tmax=*max_element(a,a+n);

  int p10=1;  // powers of 10 to divide and take the required digit of the elements
  int bckt_n;  //  This cvariable used for finding and retaining the bucket no. which the element should go in

  vector< vector<int> > bckt;  // vector of vector :: for maintaining buckets
  bckt.resize(10);   // Total 10 buckets for 10 digits in decimal syste


  for(;tmax!=0;tmax/=10,p10*=10)  // loop :: no of times = no. of digits in the largest element
    {
      for(int i=0;i<n;i++)
	{
	  bckt_n = (a[i]/p10)%10;  // getting the bucket no.
	  bckt[bckt_n].push_back(a[i]);  // push back element in that particular bucket no.
	}
      int i=0;  // iterator for the array to store_back output of this loop

      for(int bn=0;bn<10;bn++)  // looping over all buckets starting from 0'index
	{
	  for(int k=0;k<bckt[bn].size();k++)  // looping over in all buckets for its elements
	    a[i++]=bckt[bn][k]; // store back

	  bckt[bn].clear();  // clear the present bucket :: as no use further
	}

    }

}


int main()
{
  //...  Declaration , initialization and input ::
  int n;

  cout<<"Enter the no. of elements od the array to be sorted: ";
  cin>>n;

  int a[n+1];

  cout<<"Enter the array elements: \n";
  for(int i=0;i<n;i++)
    {
      cout<<"arr["<<i<<"]: ";
      cin>>a[i];
    }
  //...................................................


  //....  Sorting function call  ::
  lds_radix_sort(a,n);
  //..................................


  //.....   Output after sorting ::
  cout<<"Array after sorting is: \n";
  for(int i=0;i<n;i++)
    {
      cout<<"arr["<<i<<"]: "<<a[i]<<"\n";
    }
  //..................................
  return 0;;
}
