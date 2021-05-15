#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >v;
int vis[10005];
int par[10005];
int ap[10005];
int dis[10005];
int low[10005];
int cnt;
void dfs(int u)
{
    vis[u]=1;
    cnt++;
    dis[u]=low[u]=cnt;
    int chld=0;
    for(int i=0;i<v[u].size();i++)
    {
        int x=v[u][i];
        if(vis[x]!=1)
        {
            chld++;
            par[x]=u;
            dfs(x);
            low[u]=min(low[u],low[x]);
            if(par[u]!=-1 && low[x]>=dis[u])
                ap[u]=1;
            else if(par[u]==-1 && chld>1)
                ap[u]=1;
        }
        else if(x!=par[x])
        {
            low[u]=min(low[u],dis[x]);
        }
    }
    return;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cnt=0;
        int n,m;
        cin>>n>>m;
        v.clear();
        memset(vis,0,sizeof(vis));
        memset(par,-1,sizeof(par));
        memset(ap,0,sizeof(ap));
        memset(low,0,sizeof(low));
        memset(dis,0,sizeof(dis));
        for(int j=0;j<m;j++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(int j=1;j<=n;j++)
        {
            if(vis[j]!=1)
                dfs(j);
        }
        int temp=0;
        for(int j=1;j<=n;j++)
        {
            if(ap[j]==1)
                temp++;
        }
        cout<<"Case "<<i+1<<": "<<temp<<endl;
    }
    return 0;
}
