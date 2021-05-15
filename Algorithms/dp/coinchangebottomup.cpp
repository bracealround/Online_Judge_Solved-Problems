#include<bits/stdc++.h>
using namespace std;
int arr[6]={0,1,2,3,4,5};
int dp[6][5000];
int main()
{
    for(int i=0;i<=5;i++)
    {
        for(int j=0;j<=5;j++)
        {
            if(j==0)
                dp[i][j]=1;
            else if(i==0)
                dp[i][j]=0;
            else if(j-arr[i]<0)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-arr[i]];
                cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    //cout<<dp[5][2]<<endl;
    return 0;
}
