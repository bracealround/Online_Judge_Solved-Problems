#include<bits/stdc++.h>
using namespace std;
int arr[200][200];
bool vis[200];
int main()
{
	int tc=0;
	while(1)
	{
		tc++;
		memset(arr,63,sizeof(arr));
		memset(vis,0,sizeof(vis));
		string line;
		getline(cin,line);
		stringstream ss(line);
		vector<int>v;
		int num;
		while(ss>>num)
			v.push_back(num);
		if(v.size()==2 && v[0]==0 && v[1]==0)
			break;
		int mx=0;
		//cout<<v.size()<<endl;
		for(int i=0;i<v.size();i+=2)
		{
			int x=v[i];
			int y=v[i+1];
			vis[x]=1;
			vis[y]=1;
			if(x==0 && y==0)
				break;
			mx=max(x,mx);
			mx=max(y,mx);
			arr[x][y]=1;
		}	
		for(int i=1;i<=mx;i++)
			arr[i][i]=0;
		for(int k=1;k<=mx;k++)
			for(int i=1;i<=mx;i++)
				for(int j=1;j<=mx;j++)
				{
					if(arr[i][j]>=arr[i][k]+arr[k][j])
						arr[i][j]=arr[i][k]+arr[k][j];
				}
		int sum=0;
		int cnt=0;
		for(int i=1;i<=mx;i++)
		{
			for(int j=1;j<=mx;j++)
			{
				
				if(i==j)
					continue;
				else if(vis[i] && vis[j])
				{
					sum+=arr[i][j];
					cnt++;
				}
			}
		}
		cout<<"Case "<<tc<<": average length between pages = "<<setprecision(3)<<fixed<<(double)(sum)/(double)(cnt)<<" clicks"<<endl;
	}
	return 0;
}
