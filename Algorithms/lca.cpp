#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >con;
int level[10005],par[10005],sparse[10005][20];
bool vis[10005];
int n,root,maxlevel;
void bfs(int source)
{
    memset(vis,0,sizeof(vis));
    level[source]=1;
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        if(vis[u]==1)
            continue;
        vis[u]=1;
        for(int j=0;j<con[u].size();j++)
        {
            int x=con[u][j];
            if(level[x]==-1)
            {
                level[x]=level[u]+1;
                q.push(x);
                maxlevel=max(maxlevel,level[x]);
            }
        }
    }
    return;
}
void preprocess()
{
    int x=log2(maxlevel);
    for(int i=0;i<=x;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i==0)
                sparse[j][i]=par[j];
            else
                sparse[j][i]=sparse[sparse[j][i-1]][i-1];
        }
    }
    return;
}
int query(int a,int b)
{
    if(level[a]<level[b])
        swap(a,b);
    int x=log2(maxlevel);
    while(x>=0)
    {
        if(sparse[a][x]!=-1 && level[sparse[a][x]]>=level[b])
            a=sparse[a][x];
        --x;
    }
    if(a==b)
        return a;
    x=log2(maxlevel);
    while(x>=0)
    {
        if(sparse[a][x]!=sparse[b][x])
        {
            a=sparse[a][x];
            b=sparse[b][x];
        }
        x--;
    }
    return sparse[a][x+1];
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        con.clear();
        memset(par,-1,sizeof(par));
        memset(level,-1,sizeof(level));
        memset(sparse,-1,sizeof(sparse));
        maxlevel=0;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            int num;
            cin>>num;
            for(int k=0;k<num;k++)
            {
                int x;
                cin>>x;
                con[j].push_back(x);
                con[x].push_back(j);
                par[x]=j;
            }
        }
//        for(int j=1;j<=n;j++)
//        {
//            cout<<"par "<<j<<" "<<par[j];
//        }
//        cout<<endl;
        bfs(1);
//        for(int j=1;j<=n;j++)
//        {
//            cout<<" level "<<j<<" "<<level[j];
//        }
//        cout<<endl;
//        cout<<maxlevel<<endl;
        preprocess();
        cout<<"Case "<<i+1<<":"<<endl;
        int q;
        cin>>q;
        for(int j=0;j<q;j++)
        {
            int a,b;
            cin>>a>>b;
            if(a==b)
            {
                cout<<a<<endl;
                continue;
            }
            cout<<query(a,b)<<endl;
        }
    }
    return 0;
}

