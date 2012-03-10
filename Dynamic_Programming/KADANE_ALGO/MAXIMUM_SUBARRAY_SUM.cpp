///......           O(n)  solution



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

int main()
{
  int n;
  cout<<"Enter the no. of elements: ";
  scanf("%d",&n);

  int a[n];
  cout<<"Enter "<<n<<" Elements:\n";

  for(int i=0;i<n;i++)
    scanf("%d",&a[i]);

  long long buf=0;
  long long res=(long long)INT_MIN;

  for(int i=0;i<n;i++)
    {
      buf+=a[i];
      if(buf<0)
	buf=0;
      else
	res=max(buf,res);
    }

  cout<<"Answer: "<<res<<"\n";



  return 0;
}
