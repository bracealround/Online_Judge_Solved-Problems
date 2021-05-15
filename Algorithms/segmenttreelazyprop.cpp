#include<bits/stdc++.h>
using namespace std;
struct info{
    long long  sum,prop;
};
info tree[1000000];
#define ll long long
#define scl(a) scanf("%lld",&a)
#define sc(a) scanf("%d",&a)
#define sca(a,b) scanf("%lld %lld",&a,&b)
void update(ll node,ll b,ll e,ll i,ll j,ll val)
{
    if(i>e || j<b)
    {
        return;
    }
    if(b>=i && e<=j)
    {
        tree[node].sum+=(e-b+1)*val;
        tree[node].prop+=val;
        return;
    }
    ll left=node*2;
    ll right=(node*2)+1;
    ll mid=(b+e)/2;
    update(left,b,mid,i,j,val);
    update(right,mid+1,e,i,j,val);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
    return;
}
ll query(ll node,ll b,ll e,ll i,ll j,ll carry=0)
{
    if(i>e || j<b)
    {
        return 0;
    }
    if(b>=i && e<=j)
    {
      return tree[node].sum+(e-b+1)*carry;
    }
    ll left=node*2;
    ll right=(node*2)+1;
    ll mid=(b+e)/2;
    ll p1=query(left,b,mid,i,j,carry+tree[node].prop);
    ll p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    //tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
    return p1+p2;
}
int main()
{
    int t;
    sc(t);
    for(int i=0;i<t;i++)
    {
        ll n,q;
        sca(n,q);
        memset(tree,0,sizeof(tree));
        printf("Case %d:\n",i+1);
        for(int j=0;j<q;j++)
        {
            ll a;
            scl(a);
            ll b,c,d;
            //cout<<a<<endl;
            if(a==0)
            {
                sca(b,c);
                scl(d);
                update(1,1,n,b+1,c+1,d);
            }
            else
            {
                sca(b,c);
                printf("%lld\n",query(1,1,n,b+1,c+1,0));
            }
        }
    }
    return 0;
}
