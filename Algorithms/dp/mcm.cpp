#include<bits/stdc++.h>
using namespace std;
int arr[500];
int dp[500][500];
int mcm(int start,int last)
{
    if(last-start==1)
        return 0;
    if(dp[start][last]!=-1)
        return dp[start][last];
        int mn=1e9;
    for(int i=start+1;i<last;i++)
    {
        int left=mcm(start,i);
        int right=mcm(i,last);
        mn=min(mn,left+right+arr[start]*arr[i]*arr[last]);
    }
    return dp[start][last]=mn;
}
void pa(int start,int last)
{
    if(last-start==1)
    {
        cout<<"M"<<last;
        return;
    }
    int mn=1e9,left,right,index;
    for(int i=start+1;i<last;i++)
    {
        left=dp[start][i];
        right=dp[i][last];
        if(mn>left+right+arr[start]*arr[i]*arr[last])
        {
            mn=left+right+arr[start]*arr[i]*arr[last];
            index=i;
        }
    }
    if(index-start==1)
    {
        pa(start,index);
    }
    else
    {
        cout<<"(";
        pa(start,index);
        cout<<")";
    }
    if(last-index==1)
    {
        pa(index,last);
    }
    else
    {
        cout<<"(";
        pa(index,last);
        cout<<")";
    }
    return;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    cout<<mcm(0,n-1)<<endl;
    pa(0,n-1);
    return 0;
}
