#include<bits/stdc++.h>
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
using namespace std;
int main()
{
	int t;
	sc(t);
	for(int i=0;i<t;i++)
	{
		long long int n,x,y,z;
		scl(n);
		x=sqrt(n);
		if(x*x==n && n%2==0)
		cout<<"Case "<<i+1<<": "<<x<<" 1"<<endl;
		else if(x*x==n && n%2!=0)
	    cout<<"Case "<<i+1<<": "<<"1 "<<x<<endl;
		else
		{
			y=x+1;
			z=(y*y)-(x*x);
			z=(x*x)+((z/2)+1);
			if(n==z)
			cout<<"Case "<<i+1<<": "<<y<<" "<<y<<endl;
			else if(n<z  && x%2==0)
			cout<<"Case "<<i+1<<": "<<y<<" "<<y-(z-n)<<endl;
			else if(n>z  && x%2==0)
			cout<<"Case "<<i+1<<": "<<y-(n-z) <<" "<<y<<endl;
			else if(x%2==1 && n<z)
			cout<<"Case "<<i+1<<": "<<y-(z-n)<<" "<<y<<endl;
			else
			cout<<"Case "<<i+1<<": "<<y<<" "<<y-(n-z)<<endl;
		}
	}
	return 0;
}
