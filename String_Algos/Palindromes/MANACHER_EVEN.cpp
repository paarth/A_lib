/*
Complexity:   O(N)
 */
#include<map>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<climits>

using namespace std;

int main()
{

  string str;
  cout<<"Enter the string for finding the maximal length (even)palin: ";
  cin>>str;

  /* Declarations and Initializations */

  int n=str.size();  // n: string length of the given string
  int i,j=0;        //  i: used for fixing center and then obtaining max len palin arnd it.    
                    // j: used for obtaining the length of the max len palin.
  int k;            // k: while manacher obtains results from precomputed data (memo) , this pointer is used to update max len palin with O(1) check and thus reducing the complexity significantly.  
  int re[n];  // re[i]: gives the length of the maximal even palin with center(left) as i
  //----------------------//

  for(int i=0;i<n;i++)  // considering all indices as centers
    {
      while(str[i-j]==str[i+j+1])  // if palin about present center
	j++;                         

      re[i]=j;    // update the max len palin obtained by iterating and checking
      k=1;        // initially go to next index i.e. i+1   (since i+k obtained from i-k)

      while((k<=re[i])&&(re[i]-k!=re[i-k])&&(i>=k))   // while k is in previously found circle of i, the radius of the previous data to be fed is not touching the bigger circle. (there is an anamoly here and thus at this point , the memoized data cannot be used for updating)
	{
	  re[i+k]=min(re[i-k],re[i]-k);   // min as to make sure , it should be palin.
	  k++;
	}

      j=max(j-k,0);  // start from the max possible (leave all what are updated) : this decreases complexity significantly.
    }


  //....  Manacher computation done  :)


  cout<<"The radii of maximal palindrome with all indices as center:\n";
  for(int i=0;i<n;i++)
    {
      cout<<"R["<<i<<"]: "<<re[i]<<"\n";
    }




  return 0;
}
