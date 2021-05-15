#include<bits/stdc++.h>
using namespace std;
int arr[20];
int n;
int lis(int i,int lstind)
{
    if(i==n+1)
        return 0;
        int val1=0,val2=0;
    if(arr[i]>arr[lstind])
        val1=1+lis(i+1,i);
        val2=lis(i+1,lstind);
    return max(val1,val2);
}
int main()
{
    return 0;
}
