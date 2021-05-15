#include<bits/stdc++.h>
using namespace std;
struct point{
    long long int x,y;
    bool operator<(point q)
    {
        return x<q.x ||(x==q.x && y<q.y);
    }
};
int n;
vector<point>p;
long long int cross(point o,point a,point b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
vector<point> convex()
{
    int k=0;
    if(n<=3)
        return p;
    vector<point>ans(2*n);
    sort(p.begin(),p.end());
    for(int i=0;i<n;++i)
    {
        while(k>=2 && cross(ans[k-2],ans[k-1],p[i])<=0)
            k--;
        ans[k++]=p[i];
    }
    //cout<<k<<endl;
    for(size_t i=n-1,t=k+1;i>0;--i)
    {
        while(k>=t && cross(ans[k-2],ans[k-1],p[i-1])<=0)
            k--;
        ans[k++]=p[i-1];
    }
    //cout<<k<<endl;
    ans.resize(k-1);
    return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        for(int j=0;j<n;j++)
        {
            int x,y;
            cin>>x>>y;
            p.push_back({x,y});
        }
        vector<point>ans=convex();
        cout<<ans.size()<<endl;
        for(int j=0;j<ans.size();j++)
        {
            cout<<ans[j].x<<" "<<ans[j].y<<endl;
        }
    }
   return 0;
}
/*
1
7
0 3
2 2
1 1
2 1
3 0
0 0
3 3
*/
