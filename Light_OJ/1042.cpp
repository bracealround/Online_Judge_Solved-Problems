#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define fr(i,n) for(int i=0;i<n;i++)
#define sc scanf
#define pf printf
using namespace std;
int main()
{
	int t;
	sc("%d",&t);
	fr(i,t)
	{
		long long int n;
		sc("%lld",&n);
		if((n & (n-1))==0)
		{
			n=log2(n);
			//cout<<n<<endl;
			n=1<<(n+1);
			pf("Case %d: %lld\n",i+1,n);
		}
		else if((n & (n+1))==0)
		{
			int x;
			x=log2(n);
			//cout<<x<<endl;
			x=1<<(x);
			pf("Case %d: %lld\n",i+1,n+x);
		}
		else
		{
			vector<int>v;
			while(n!=0)
			{
				int x;
				x= n % 2;
				//cout<<x<<endl;
				n=n/2;
				v.pb(x);
			}
			int count=0;
			//reverse(v.begin(),v.end());
			/*for(int j=0;j<v.size()-1;j++)
			{
				if(v[j]==1 && v[j+1]==0)
				{
					swap(v[j],v[j+1]);
					count++;
					break;
				}
			}*/
			//reverse(v.begin(),v.end());
			/*fr(j,v.size())
			{
				cout<<v[j];
			}*/
			//cout<<endl;
			if(count==0)
			{
				v.pb(0);
			}
			reverse(v.begin(),v.end());
			if(count==0)
			{
				next_permutation(v.begin(),v.end());
			}
			/*fr(j,v.size())
			{
				cout<<v[j];
			}*/
			reverse(v.begin(),v.end());
			long long int sum=v[0]*1;
			for(int j=1;j<v.size();j++)
			{
				sum=sum+v[j]*(1<<(j));
			}
			pf("Case %d: %lld\n",i+1,sum);
		}
	}
	return 0;
}
