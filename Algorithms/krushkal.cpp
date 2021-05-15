#include<bits/stdc++.h>
using namespace std;
struct edge{
    int u,v,w;
};
bool operator<(edge a,edge b){
    return a.w<b.w;
}
vector<edge>e;
int p[200005];
int fnd(int x)
{
    if(p[x]==x) return x;
    return p[x]=fnd(p[x]);
}
int  kruskal()
{
    sort(e.begin(),e.end());
    int sz=e.size();
    int ans=0;
    for(int i=0;i<sz;i++)
    {
        if(fnd((e[i].u))!=fnd((e[i].v)))
        {
            p[p[e[i].u]]=p[e[i].v];
            ans+=e[i].w;
        }
    }
    return ans;
}
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
    	if(n==0 && m==0)
    		break;
    	e.clear();
    	memset(p,0,sizeof(p));
    	int sum=0;
    	for(int i=1;i<=n;i++)
    	{
        	p[i]=i;
    	}
    	for(int i=0;i<m;i++)
    	{
        	int x,y,z;
        	cin>>x>>y>>z;
        	sum+=z;
        	e.push_back({x,y,z});
    	}
    	cout<<sum-kruskal()<<endl;
    }
    return 0;
}
