#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct info{
	ll int prop,sum;
}tree[500000];
ll int arr[500000];
void init(ll int node, ll int b, ll int e)
{
    if (b == e) {
        tree[node].sum = arr[b];
        return;
    }
    ll int Left = node * 2;
    ll int Right = node * 2 + 1;
    ll int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}
void update(ll int node,ll int b,ll int e,ll int i,ll int j,ll int x)
{
	if(i>e || j<b)
		return;
	if(b>=i && e<=j)
	{
		tree[node].sum+=(e-b+1)*x;
		tree[node].prop+=x;
		return;
	}
	ll int left=node*2;
	ll int right=node*2+1;
	ll int mid=(b+e)/2;
	update(left,b,mid,i,j,x);
	update(right,mid+1,e,i,j,x);
	tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
ll int query(ll int node,ll int b,ll int e,ll int i,ll int j,ll int carry=0)
{
	if(i>e || j<b)
		return 0;
	if(b>=i && e<=j)
		return tree[node].sum+(e-b+1)*carry;
	ll int left=node*2;
	ll int right=node*2+1;
	ll int mid=(b+e)/2;
	ll int p1=query(left,b,mid,i,j,carry+tree[node].prop);
	ll int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
	return p1+p2;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		memset(tree,0,sizeof(tree));
		while(m--)
		{
			int x;
			cin>>x;
			if(x==0)
			{
				int y,z,num;
				cin>>y>>z>>num;
				update(1,1,n,y,z,num);
			}
			else
			{
				int y,z;
				cin>>y>>z;
				cout<<query(1,1,n,y,z)<<endl;
			}
		}
	}
	return 0;
}
