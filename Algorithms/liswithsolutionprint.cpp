#include<bits/stdc++.h>
using namespace std;
int dp[50000];
int dir[50000];
int arr[50000];
int n;
/*int longest(int i)
{
    if(dp[i]!=-1)
        return dp[i];
        int maxl=0;
        cout<<i<<endl;
    for(int j=i+1;j<=n;j++)
    {
        cout<<j<<endl;
        if(arr[j]>arr[i])
        {
            if(longest(j)>maxl)
            {
                maxl=longest(i);
                dir[i]=j;
            }
        }
    }
    return dp[i]=1+maxl;
}*/
int longest(int u)
{
	if(dp[u]!=-1)
        return dp[u];
	int maxi=0;
	for(int v=u+1;v<=n+1;v++)
	{
		if(arr[v]>arr[u])
		{
            if(longest(v)>maxi)
			{
				maxi=longest(v);
                dir[u]=v;

			}
		}
	}
	dp[u]=1+maxi;
	return dp[u];
}
void print(int start)
{
    while(1)
    {
        //cout<<start<<endl;
        //cout<<dir[start]<<endl;
        cout<<arr[start]<<endl;
        if(dir[start]==-1)
            break;
        start=dir[start];
    }
    return;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    int lis=0,start;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    arr[0]=-1e9;
    for(int i=1;i<=n;i++)
    {
        if(longest(i)>lis)
        {
            lis=longest(i);
            start=i;
        }
    }
    cout<<lis<<endl;
    cout<<"starting point:"<<start<<endl;
    print(start);
    return 0;
}
