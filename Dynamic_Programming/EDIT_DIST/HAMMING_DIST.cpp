/*
Hamming distance is the distance between two strings .....
::   The operations can be performed on those strings can be just "substitution" alone or might be called mutation "parameter-1" alone
 */
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

using namespace std;

int main()
{
  //......given two numbers; i.e. two binary strings 

  //...AIM:  find the hammig dist:trivial: get XOR and get builtinpopcount :)


  unsigned long long a,b;
  cout<<"Enter 1st no. :";
  cin>>a;
  cout<<"Enter the 2nd no. :";
  cin>>b;
  //...input done :)

  unsigned long long temp;

  temp=a^b;

  int res=0;

  res=__builtin_popcount(temp);

  cout<<"Ans: "<<res<<"\n";

  return 0;
}
