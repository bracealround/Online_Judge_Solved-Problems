#include<bits/stdc++.h>
using namespace std;
int set_n(int n,int pos)
{
    return n=n|(1<<pos);
}
int reset_n(int n,int pos)
{
    return n=(n& ~(1<<pos));
}
bool check(int n,int pos)
{
    return n=(bool)(n& (1<<pos));
}
int arr[20][20];
int dp[(1<<15)+2];
int n;
int call(int x)
{
    if(x==(1<<n)-1)
        return 0;
    if(dp[x]!=-1)
        return dp[x];
    int mn=1<<28;
    for(int i=0;i<n;i++)
    {
        if(check(x,i)==0)
        {
            int p=arr[i][i];
            for(int j=0;j<n;j++)
            {
                if((i!=j) and check(x,j)!=0)
                    p+=arr[i][j];
            }
            int ret=p+ call(set_n(x,i));
            mn=min(mn,ret);
        }
    }
    return dp[x]=mn;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                cin>>arr[j][k];
          cout<<"Case "<<i+1<<": "<<call(0)<<endl;
    }
    return 0;
}
