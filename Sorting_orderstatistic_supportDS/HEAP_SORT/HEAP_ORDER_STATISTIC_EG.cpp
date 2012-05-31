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
#define pq_size 100000   // maximum  priority_queue size
 

struct pq{
  int q[pq_size+1];  // This shows the priority queue and the max buffer size.
  int n;            // This shows the present no. of queue elements
};

int pq_parent(int n)
{
  if(n==1) return (-1);    // This shows that the present node is root and thus no parent.
  else return ((int)(n/2));    //This returns the parent in pointer index
}

int pq_young_child(int n)
{
  return (2*n);  // This returns left child index
}

void pq_swap(pq *q,int a,int b)   // This function is simply to swap [a] and [b] of the pq
{
  int temp=q->q[a];
  q->q[a]=q->q[b];
  q->q[b]=temp;
}

void bubble_up(pq *q,int p)
{
  if(pq_parent(p)==-1) return;
  // i.e if the bubble up operation now presently at root// NOP further

  if(q->q[pq_parent(p)]>q->q[p])   // If the parent value is greater (needs bubble up op)
    {
      pq_swap(q,p,pq_parent(p));  // make a swap 
      bubble_up(q,pq_parent(p));  // again make the bubble up to satisfy and maintain heap property
    }
}


void pq_insert(pq *q,int x)  // to be inserted in prio_queue:"q" and to be inserted: "x"
{
  if(q->n >= pq_size)   // If overflow occures.
    cout<<"Error: This insertion makes the queue overflow:: Thus operation failure.";
  else
    {
      q->n = (q->n)+1;  // incrementing the no. of queue elements as the insertion possible.
      q->q[q->n]=x;
      bubble_up(q,q->n);  // make bubble up to satisfy and maintain heap property
    }
}

void pq_init(pq *q)  // Initialize the pq by no. of elements =0
{
  q->n=0;
}

void make_heap(pq *q,int store[],int n) // parameters: pq , array to be sorted, size of array
{

  pq_init(q);   
  for(int i=0;i<n;i++)        // repeatedly and sequencially insert the array elements.
    pq_insert(q,store[i]);
}


void bubble_down(pq *q,int p)
{
  int c;  // child index
  int min_index;  // index of lightest child

  c=pq_young_child(p); // child index given as the left child (and +1 will access right child)
  min_index=p; 

  for(int i=0;i<=1;i++)  // for both left and right child
    {
      if((c+i)<=q->n)    // get the index of the minimum of node and its both childrens
	{
	  if(q->q[min_index]>q->q[c+i])
	    min_index=c+i;
	}
    }
  
  // if need for swap ....swap and thus make bubble down recursively 
      if(min_index!=p)     
	{
	  pq_swap(q,p,min_index);
	  bubble_down(q,min_index);
	}

}


int extract_min(pq *q)
{
  int min=-1;

  if(q->n<=0)   // if queue is empty
    cout<<"Warning: queue is empty... extract_min operation failure. Further NOP";
  else
    {
      min=q->q[1];   // q[1] gives the min value.
      q->q[1]=q->q[q->n];   // get any value say ..last and thus maintain property by bubble down   
      q->n=(q->n)-1; 
      bubble_down(q,1);
    }
  return min;
}

int heap_compare(pq *q,int i,int count,int x)
{
  if((count<=0)||(i>q->n))
    return count;

  if(q->q[i]<x)
    {
      count=heap_compare(q,pq_young_child(i),count-1,x);
      count=heap_compare(q,pq_young_child(i)+1,count,x);
    }
  return count;
}


int construct_n_compare(int store[],int n,int k,int x)
{
  pq q;  // heap for HEAP_COMPARE

  make_heap(&q,store,n);   // construct heap from the array to be sorted
  int ret;
  ret=heap_compare(&q,1,k,x);

  return ret;
}


int main()
{

  int n;
  cout<<"Enter the no. of elements of the array(or key) to be created heap from:";
  cin>>n;

  int store[n+1];

  cout<<"Enter the elements of the array (or keys): \n";
  for(int i=0;i<n;i++)
    {
      cout<<"store["<<i<<"]=";
      cin>>store[i];
    }

  int k,x;

  cout<<"Enter the vvalue of K: ";
  cin>>k;
  cout<<"Enter the value of x(to be compared): ";
  cin>>x;

  int res;  // To store the result parameter

  res=construct_n_compare(store,n,k,x);    //,int n,int k,int x
  
    if(res>0)
      cout<<"The given no. "<<x<<" is "<<k-res+1<<"th smallest and thus smaller than "<<k<<"th smallest number\n";
    else
      cout<<"The given number "<<x<<" is greater than the "<<k<<"th smallest number\n";

  return 0;
}
