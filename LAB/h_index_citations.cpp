#include <iostream>
#include <math.h>
using namespace std;
int h_citation(int arr[],int len){
    int mid;
    if(len&1)mid=len/2;
    else  mid=len/2-1;
    
}
int main()
{
    ios::sync_with_stdio(false);
    int len;
    cin >> len;
    int citation[len];
    for (int i = 0; i < len; i++)
        cin >> citation[i];
    cout<<h_citation(citation,len);
    return 0;
}