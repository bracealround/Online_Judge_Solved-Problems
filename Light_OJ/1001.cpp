#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		if(a>10)
		{
			a=a-10;
			b=10;
		}
		else
		b=0;
		cout<<a<<" "<<b<<endl;
	}
	return 0;
	
}
