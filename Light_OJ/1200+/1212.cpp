#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	string a,b,c,d;
	a="pushLeft";
	b="pushRight";
	c="popLeft";
	d="popRight";
	for(int i=0;i<t;i++)
	{
		int n,m;
		cout<<"Case "<<i+1<<":"<<endl;
		cin>>n>>m;
		vector<int>v;
		int x;
		string y;
		for(int j=0;j<m;j++)
		{
			cin>>y;
			if(y==a ||y==b)
			cin>>x;
			if(y==a)
			{
				if(n==v.size())
				cout<<"The queue is full"<<endl;
				else
				{
					reverse(v.begin(),v.end());
					v.push_back(x);
					reverse(v.begin(),v.end());
					cout<<"Pushed in left: "<<x<<endl;
				}
			}
			else if(y==b)
			{
				if(n==v.size())
				cout<<"The queue is full"<<endl;
				else
				{
					v.push_back(x);
					cout<<"Pushed in right: "<<x<<endl;
				}
			}
			else if(y==c)
			{
				if(v.size()==0)
				cout<<"The queue is empty"<<endl;
				else
				{
					x=v[0];
					reverse(v.begin(),v.end());
					v.pop_back();
					reverse(v.begin(),v.end());
					cout<<"Popped from left: "<<x<<endl;
				}
			}
			else if(y==d)
			{
				if(v.size()==0)
				cout<<"The queue is empty"<<endl;
				else
				{
					x=v[v.size()-1];
					v.pop_back();
					cout<<"Popped from right: "<<x<<endl;
				}
			}
			
		}
	}
return 0;
}
