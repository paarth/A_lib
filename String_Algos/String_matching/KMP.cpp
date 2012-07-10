#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<climits>
#include<cstring>

using namespace std;

int t[80];  // t :  tabulation array

void kmp_table(string p)   // funstion definition for KMP tabulation
{
  t[0]=-1;   
  t[1]=0;
  int pos=2,cnd=0;
  
  while(pos<p.size())
    {
      if(p[pos-1]==p[cnd])  // Shows a failure move back pos recognized and thus updated and both pos and cnd incrememted
	{cnd++;t[pos]=cnd;pos++;}
      else if(cnd>0) // since cnd>0 thus tabulation used to failure back to t[cnd] for further check for the same pos value as yet not updated
	{cnd=t[cnd];}
      else // else just make a reset and set t[pos] as 1st element and thus updated t[] value so increment pos but not cnd
	{t[pos]=0;pos++;}
    }
}

int kmp_search(string p,string s)
{
  int m=0;
  int i=0;
  while(m+i<=s.size())
    {
      if(p[i]==s[m+i])  // if characters matches go on increment i and go further untill last character matched and den return if so reached
	{
	  if(i==p.size()-1)
	    return m;
	  i++;
	}
      else   // else in case of failure use failure funtion tabulation and thus update m
	{
	  m=m+i-t[i];  // do not start all over again but from m+i-t[i]
	  
	  /* And thus accordingly update the value of i for further matching */
	  if(t[i]>-1)
	    i=t[i];
	  else
	    i=0;
	}
      
    }
  return -1;
}


int main()
{
  
  string p,s;  // s: source string from which pattern "p" has to be searched
  
  cout<<"enter string:";
  getline(cin,s);         
  
  cout<<"enter pattern:";
  getline(cin,p);
  
  
  
  kmp_table(p);  // kmp tabulation. precomputation for the given pattern
  
  /* Debug Or More into KMP */
  /*
    cout<<"\n";
    for(int i=0;i<s.size();i++)
    {
    cout<<t[i]<<" ";
    }
    cout<<"\n";
  */
  
  int res;
  res=kmp_search(p,s);  // function call to kmp search returning the index at which the pattern is found
  
  if(res>=0)
    cout<<"found at pos:"<<res<<"\n";
  else
    cout<<"not found\n";
  
  
  return 0;
}
