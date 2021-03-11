#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	long long int x[10005];
	memset(x,-1,sizeof(x));
	long long int a,b,c,d,e,f,n,y;
	cin>>a>>b>>c>>d>>e>>f>>n;
	x[0]=a;
	x[1]=b;
	x[2]=c;
	x[3]=d;
	x[4]=e;
	x[5]=f;
	if(n<6)
	{
		cout<<"Case "<<i+1<<": "<<x[n]%10000007<<"\n";
		continue;
	}
	else
	{
		for(int j=6;j<=n;j++)
		{
			x[j]=((x[j-1]%10000007)+(x[j-2]%10000007)+(x[j-3]%10000007)+(x[j-4]%10000007)+(x[j-5]%10000007)+(x[j-6]%10000007))%10000007;
		}
		y=(x[n]%10000007);
		cout<<"Case "<<i+1<<": "<<y<<"\n";
		continue;
	}
    }
    return 0;
	
	
}
