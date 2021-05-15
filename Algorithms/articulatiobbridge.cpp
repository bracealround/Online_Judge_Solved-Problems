#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >v;
vector<pair<int,int> >vp;
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
//            cout<<x<<" low "<<low[x]<<endl;
//            cout<<u<<" high "<<dis[u]<<endl;
            if(low[x]>dis[u])
            {
                if(u>x)
                    vp.push_back({x,u});
                else
                    vp.push_back({u,x});
            }
        }
        else if(x!=par[u])
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
    //cout<<t<<endl;
    for(int i=0;i<t;i++)
    {
        cnt=0;
        int n;
        cin>>n;
        //cout<<n<<endl;
        v.clear();
        vp.clear();
        memset(vis,0,sizeof(vis));
        memset(par,-1,sizeof(par));
        //memset(ap,0,sizeof(ap));
        memset(low,0,sizeof(low));
        memset(dis,0,sizeof(dis));
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            //cout<<x<<endl;
            char c;
            cin>>c;
            int y;
            cin>>y;
            //cout<<y<<endl;
            cin>>c;
            for(int k=0;k<y;k++)
            {
                int p;
                cin>>p;
                v[x].push_back(p);
            }
        }
        for(int j=0;j<n;j++)
        {
            if(vis[j]!=1)
            {
                    dfs(j);
            }
        }
        sort(vp.begin(),vp.end());
        cout<<"Case "<<i+1<<":"<<endl;
        cout<<vp.size()<<" critical links"<<endl;
        for(int j=0;j<vp.size();j++)
        {
            cout<<vp[j].first<<" - "<<vp[j].second<<endl;
        }
        int temp=0;

    }
    return 0;
}
