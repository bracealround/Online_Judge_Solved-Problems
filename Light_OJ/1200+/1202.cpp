#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,r1,r2,c1,c2,x,y;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r1>>c1>>r2>>c2;
		x=abs(r2-r1);
		y=abs(c2-c1);
		if(r1==r2 && c1==c2)
		    cout<<"Case "<<i<<": "<<"2"<<endl;
		else if(x==y)
		    cout<<"Case "<<i<<": "<<"1"<<endl;
		else if((x%2==0 && y%2!=0)||(x%2!=0 && y%2==0) )
			cout<<"Case "<<i<<": "<<"impossible"<<endl;
		else 
		    cout<<"Case "<<i<<": "<<"2"<<endl;	
	}
	return 0;
}
