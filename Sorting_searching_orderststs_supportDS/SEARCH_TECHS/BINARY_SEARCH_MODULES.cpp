//  1) Simple Binary search module ::  

   /* For case take in a simple array or vector(though no difference it makes in this static mode) and task to be done is find the index of the target integer no. to be searched
    */
int binary_search(vector<in> arr,int target)
{
  int lo=0,hi=arr.size()-1;
  int mid;

  while(lo<=hi)
    {
      mid=lo+(hi-lo)/2;
      
      if(arr[mid]==target)
	return mid;
      else if(arr[mid]<target)
	lo=mid+1;
      else
	hi=mid-1;
    }
  return -1;  // symbolises ....target is not found in the given array
}

/* p can be understood as a search query function which might be passed as a pointer
 to a function but used as a function itslef for simplicity and focus on binary search */

//  2) Discrete Binary search 

   /* Discrete by nature provides the real power of the binary search:
instance taken of a system with  <no no no ....no yes yes.....yes yes> predicate output system and we need to trace the index of the 1st yes int the same.
   */

int binary_search(int lo.int hi,int* p)
{
  int mid;
  
  while(lo<hi)
   {
     mid=lo+(hi-lo)/2;

     if(p(mid)==true)
       hi=mid;
     else
       lo=mid+1;
   }

  if(p(lo)==false)
    return -1;  // symbolises that p(x) is false for all x in the given call range <lo-hi>

  return lo;
}


// 3)Binary search for real numbers:
    /* Although using the same concept ,this might get tricky sometimes. The possibilities of handling the decision making at the half selection and running into inifinite loop.

TESTS_FOR_CORRECTNESS_HELPS: <0-1> this case gives a good check
                             (similarly) <no yes> a two element search space      
			     also need to take care of the termination condition and precision issue over it.
    */


/* This case assumed the precision needed is of order e-6*/

double binary_search(double lo,double hi,int *p)  
{

  while(fabs(hi-lo)>1e-6)
    {
      double mid=lo+(hi-lo)/2;
      
      if(p(mid)==true)
	hi=mid;
      else 
	lo=mid;
    }
  return lo;  // Note: lo is close to the border between no and yes
}
