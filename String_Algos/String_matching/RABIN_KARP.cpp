#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<cstdlib>
#include<cmath>
#include<climits>


using namespace std;

#define ToNum(c) (c-'a')  //converts alphabets to numbers


int radix=10,prime=117;


int mod(int a,int p,int m)//(radix^m-1)%prime
{
  if (p == 0)
    return 1;
 
 int sqr = mod(a,p/2,m) % m;
 sqr = (sqr * sqr) % m;
 
 if (p & 1) 
   return ((a % m) * sqr) % m;
  else 
    return sqr;
}


int rbk(string text,string pattern)
{
  int n,m;
  n=text.size(); // text size 
  m=pattern.size(); // pattern size 

  int found;

  int h;
  h=mod(radix,m-1,prime);


  int pp,tt; // pp: pattern pointer value, tt: text pointer value
  pp=0;tt=0;

  for(int i=0;i<m;i++)
    {
      pp=(radix*pp + ToNum(pattern[i]))%prime;
      tt=(radix*tt + ToNum(text[i]))%prime;
    }
  
  for(int i=0;i<=n-m;i++)
    {
      if(pp==tt)  // only if pointer values are equal, we go on for matching strings at this pointer 
	{
	  found=1;
	  for(int j=0;j<m;j++)
	    {
	      if(pattern[j]!=text[i+j])
		{found=0; break;}
	    }
	  if(found)
	    return i;
	}
      else // else , compute next tt value 
	{
	  tt=(radix*(tt - (((int)(ToNum(text[i]))*h) % prime)) + (int)(ToNum(text[i+m]))) % prime;  // making the change for the new character came in and one that got out of window.
	}
      
    }
  return -1;
  
}



int main()
{
  string text,pattern; // text: to be searched from , pattern to be searched
  
  
  cout<<"enter the text: ";
  getline(cin,text);
    
  cout<<"enter the pattern: ";
  getline(cin,pattern);
    
  int res;
  
  res=rbk(text,pattern);  // call rabin-karp funtion with text and pattern as parameter
  
  if(res==-1)
    printf("\nnot found......\n");
  else
    printf("\nfound at pos: %d\n",res);
  
  
  
  
  return 0;
}
