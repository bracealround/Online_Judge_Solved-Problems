#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int a[3],n;
	cin >>n;
	for(int i=0;i<n;i++)
	{
		cin >>a[0]>>a[1]>>a[2]; 
		sort(a,a+3);
		if(a[0]==0 && a[1]==0 && a[2]==0)
		{
			break;
		}
		//sort(a,a+3);
		else if(a[2]*a[2]==a[1]*a[1]+a[0]*a[0])
		{
			printf("Case %d: yes\n",i+1);
		}
		else
		{
		printf("Case %d: no\n",i+1);
	    }	
	}
	return 0;
}
