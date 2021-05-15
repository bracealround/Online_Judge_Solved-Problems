#include<bits/stdc++.h>
using namespace std;
string a;
int n;
int dp[500][500];
int lis(int i,int lstind)
{
    if(i>=n)
        return 0;
    if(dp[i+1][lstind+1]!=-1)
        return dp[i+1][lstind+1];
    int ret1=0,ret2=0,ret=0;
    if(a[i]>a[lstind] || lstind==-1)
    {
        ret1=1+lis(i+1,i);
        ret2=lis(i+1,lstind);
        ret=max(ret1,ret2);
    }
    else
        ret=lis(i+1,lstind);
    return dp[i+1][lstind+1]=ret;
}
int main()
{
    cin>>a;
    n=a.size();
    memset(dp,-1,sizeof(dp));
    cout<<lis(0,-1)<<endl;
    return 0;
}
