#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  while(n--){
    int yr;
    cin>>yr;
    if(yr%400==0)
      cout<<"Yes"<<endl;
    else if(yr%100==0)
      cout<<"No"<<endl;
    else if(yr%4==0)
      cout<<"Yes"<<endl;
    else
      cout<<"No"<<endl;
  }
  
  return 0;
}