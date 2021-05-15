#include<bits/stdc++.h>
using namespace std;
int dp[101][10001];
int main()
{
    int t;
    cin>>t;
    for(int l=0;l<t;l++)
    {
        int n,k;
        cin>>n>>k;
        int arr[105];
        memset(dp,-1,sizeof(dp));
        for(int j=1;j<=n;j++)
        {
            cin>> arr[j];
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=k;j++)
            {
                if(j==0)
                    dp[i][j]=1;
                else if(i==0)
                    dp[i][j]=0;
                else if(j-arr[i]<0)
                    dp[i][j]=dp[i-1][j]%100000007;
                else
                    dp[i][j]=(dp[i-1][j]+dp[i][j-arr[i]])%100000007;
                    cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"Case "<<l+1<<": "<<dp[n][k]<<endl;
    }
    return 0;
}
