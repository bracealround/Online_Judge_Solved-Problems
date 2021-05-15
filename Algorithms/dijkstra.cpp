#include<bits/stdc++.h>
using namespace std;
vector<pair<long long int,long long int>>v[100001];
long long int dis[100001];
long long int par[100001];
long long int vis[100001];
int main()
{
    int n,q;
    cin>>n>>q;
    long long int x,y,cst;
    for(int i=0;i<q;i++)
    {
        cin>>x>>y>>cst;
        v[x].push_back({cst,y});
        v[y].push_back({cst,x});
    }
    for(int i=1;i<=100000;i++)
        dis[i]=1e18;
    memset(par,-1,sizeof(par));
    priority_queue<pair<long long int,long long int>, vector<pair<long long int,long long int>>, std::greater<pair<long long int,long long int>> > pq;
    dis[1]=0;
    par[1]=1;
    //cout<<"1"<<endl;
    pq.push({0,1});
    while(!pq.empty())
    {
        long long int u=pq.top().second;
        long long int c=pq.top().first;
        //cout<<u<<" "<<c<<endl;
        pq.pop();
        if(dis[u]<c)
            continue;
        /*if(vis[u]==1)
            continue;
        vis[u]=1;*/
        for(int i=0;i<v[u].size();i++)
        {
            long long int p=v[u][i].second;
			long long int w = v[u][i].first;
			//cout<<p<<" "<<w<<endl;
            if(dis[u]+w<dis[p])
            {
                dis[p]=dis[u]+w;
                par[p]=u;
                pq.push({dis[p],p});
            }
        }
    }
    //cout<<"56987"<<endl;
    x=n;
    //cout<<par[1]<<endl;
    int cnt= 0;

    vector<int>vp;
    while(1)
    {
        if(par[x]==-1)
        {
            cout<<"-1"<<endl;
            return 0;
        }
        vp.push_back(x);
       // cout<<x<<endl;
        if(par[x]==1)
        {
        	vp.push_back(1);
                break;
        }
        x=par[x];
    }
    reverse(vp.begin(),vp.end());
    for(int i=0;i<vp.size();i++)
    {
        cout<<vp[i]<<" ";
    }
    return 0;
}
