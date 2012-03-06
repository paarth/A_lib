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
