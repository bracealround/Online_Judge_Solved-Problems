#include<bits/stdc++.h>
using namespace std;
double a[1000005];
int main()
{
	a[0]=0;
	a[1]=0;
	for(int i=2;i<=1000003;i++)
	{
		a[i]=a[i-1]+log10(i);
	}
	//cout<<a[2]<<endl;
	int t,num,base,y;
	double x;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>num>>base;
		x=a[num]/log10(base);
		y=floor(x);
		y++;
		cout<<"Case "<<i<<": "<<y<<endl;
	}
	return 0;
}
