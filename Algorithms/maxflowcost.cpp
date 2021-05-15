#include<bits/stdc++.h>
using namespace std;
int cst[100][100];
int par[105];
int vis[105];
int n,ed,s,e;
bool bfs(int s,int e)
{
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(s);
    vis[s]=1;
    par[s]=-1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(cst[x][i]>0 && vis[i]==0)
            {
                vis[i]=1;
                q.push(i);
                par[i]=x;
                if(i==e)
                    return 1;
            }
        }
    }
    return 0;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>s>>e>>ed;
        memset(cst,0,sizeof(cst));
        for(int j=0;j<ed;j++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            cst[a][b]+=c;
        }
        int ans=0;
        while(bfs(s,e))
        {
            int mn=1e9;
            int x=e;
            while(par[x]>0)
            {
                mn=min(mn,cst[par[x]][x]);
                x=par[x];
            }
            cout<<mn<<endl;
            x=e;
            while(par[x]>0)
            {
                cst[par[x]][x]-=mn;
                cst[x][par[x]]+=mn;
                x=par[x];
            }
            ans+=mn;
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
1
6 7 1 6
1 2 2
1 3 5
2 5 1
3 4 3
2 4 3
5 6 4
4 6 4
*/
