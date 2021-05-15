#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >v;
int con[100][100];
bool vis[105];
bool b;
int n,e;
void hamil(int i,int d)
{
    if(vis[1]==1)
    {
        if(d==n)
            b=1;
            return;
    }
    for(int j=1;j<=n;j++)
    {
        if(con[i][j]==1 && vis[j]==0)
        {
            vis[j]=1;
            hamil(j,d+1);
            vis[j]=0;
        }
    }
    return;
}
int main()
{
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        con[a][b]=1;
    }
    hamil(1,0);
    if(b==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}
