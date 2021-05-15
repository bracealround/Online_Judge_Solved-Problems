#include<bits/stdc++.h>
using namespace std;
struct node{
    int at,cost;
    node(int _at,int _cost)
    {
        at=_at;
        cost=_cost;
    }
};
bool operator<(node a,node b)
{
    return a.cost>b.cost;
}
struct ed{
    int v,w;
};
map<int,vector<ed> >v;
priority_queue<node>pq;
int n,m;
int dist[505];
void dij(int s)
{
    for(int i=0;i<n;i++)
    {
        dist[i]=1e9;
    }
    dist[s]=0;
    pq.push({s,0});
    while(!pq.empty())
    {
        node u=pq.top();
        //cout<<u.at<<" "<<u.cost<<endl;
        pq.pop();
        if(u.cost!=dist[u.at])
            continue;
        for(ed e:v[u.at])
        {
            if(dist[e.v]>max(u.cost,e.w)){
            dist[e.v]=max(u.cost,e.w);
            pq.push({e.v,dist[e.v]});
            }
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m;
        memset(dist,0,sizeof(dist));
        pq.empty();
        v.clear();
        for(int j=0;j<m;j++)
        {
            int x,y,z;
            cin>>x>>y>>z;
            v[x].push_back({y,z});
            v[y].push_back({x,z});
        }
        int s;
        cin>>s;
        dij(s);
        cout<<"Case "<<i+1<<":"<<endl;
        for(int j=0;j<n;j++)
        {
            if(dist[j]==1e9)
                cout<<"Impossible"<<endl;
            else
            cout<<dist[j]<<endl;
        }
    }
    return 0;
}
