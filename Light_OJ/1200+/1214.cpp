#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
	string n;
	long long int m;
	cin>>n>>m;
	if(n[0]<48 || n[0]>57)
	n.erase(n.begin());
	long long int count=0;
	//reverse(n.begin(),n.end());
	for(int i=0;i<n.size();i++)
	{
		count=(count*10+(n[i]-48))%m;
		//cout<<count<<endl;
	}
	//cout<<count<<endl;
	if(count==0)
	{
		cout<<"Case "<<j+1<<": divisible"<<endl;
	}
	else
	cout<<"Case "<<j+1<<": not divisible"<<endl;
    }
    return 0;
}
