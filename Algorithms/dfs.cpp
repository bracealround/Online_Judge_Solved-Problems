#include<bits/stdc++.h>
using namespace std;
vector<long long int>v[100000];
int l[1000000];
map<long long int,long long int>m;
long long int y=999999999999999999;
long long int dfs(long long int source)
{
	if(m[source]==1) y=0;
	m[source]=1;
	int flag=0;
	if(l[source]<y)
	y=l[source];
	//cout<<y<<endl;
	for(int i=0;i<v[source].size();i++)
	{
		long long int x=v[source][i];
		if(m[x]==0)
		{
			dfs(x);
		}
	}
}
int main()
{
    return 0;
}
