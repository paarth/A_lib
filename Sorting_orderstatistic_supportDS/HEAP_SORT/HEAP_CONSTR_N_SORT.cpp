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
#define pq_size 100000


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

void pq_swap(pq *q,int a,int b)
{
  int temp=q->q[a];
  q->q[a]=q->q[b];
  q->q[b]=temp;
}

void bubble_up(pq *q,int p)
{
  if(pq_parent(p)==-1) return;
  // i.e if the bubble up operation now presently at root// NOP further

  if(q->q[pq_parent(p)]>q->q[p])
    {
      pq_swap(q,p,pq_parent(p));
      bubble_up(q,pq_parent(p));
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
      bubble_up(q,q->n);
    }
}

void pq_init(pq *q)
{
  q->n=0;
}

void make_heap(pq *q,int store[],int n)
{

  pq_init(q);
  for(int i=0;i<n;i++)
    pq_insert(q,store[i]);
}


void bubble_down(pq *q,int p)
{
  int c;  // child index
  int min_index;  // index of lightest child

  c=pq_young_child(p);
  min_index=p;

  for(int i=0;i<=1;i++)
    {
      if((c+i)<=q->n)
	{
	  if(q->q[min_index]>q->q[c+i])
	    min_index=c+i;
	}
    }

      if(min_index!=p)
	{
	  pq_swap(q,p,min_index);
	  bubble_down(q,min_index);
	}

}


int extract_min(pq *q)
{
  int min=-1;

  if(q->n<=0)
    cout<<"Warning: queue is empty... extract_min operation failure. Further NOP";
  else
    {
      min=q->q[1];
      q->q[1]=q->q[q->n];
      q->n=(q->n)-1;
      bubble_down(q,1);
    }
  return min;
}

void heap_sort(int store[],int n)
{
  pq q;  // heap for HEAP_SORT

  make_heap(&q,store,n);

  for(int i=0;i<n;i++)
    store[i]=extract_min(&q);
}


int main()
{

  int n;
  cout<<"Enter the no. of elements of the array(or key) to be sorted:";
  cin>>n;

  int store[n+1];

  cout<<"Enter the elements of the array (or keys): \n";
  for(int i=0;i<n;i++)
    {
      cout<<"store["<<i<<"]=";
      cin>>store[i];
    }

  heap_sort(store,n);

  cout<<"The required sorted array: \n";

  for(int i=0;i<n;i++)
    {
      cout<<"store["<<i<<"]= "<<store[i]<<"\n";
    }


  return 0;
}
