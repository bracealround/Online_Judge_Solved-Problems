#include<bits/stdc++.h>
using namespace std;
int arrw[500];
int pro[500];
int dp[500][500];
int n,cap;
int knap(int i,int w)
{
    if(i>=n)
        return 0;
    if(dp[i][w]!=-1)
        return dp[i][w];
    int ret1=0,ret2=0;
    if(w+arrw[i]<=cap)
        ret1=pro[i]+knap(i+1,w+arrw[i]);
    ret2=knap(i+1,w);
    return dp[i][w]=max(ret1,ret2);
}
int main()
{
    cin>>n>>cap;
    for(int i=0;i<n;i++)
    {
        cin>>arrw[i]>>pro[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<knap(0,0)<<endl;
    return 0;
}
