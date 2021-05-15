#include<bits/stdc++.h>
using namespace std;
bool con[100][100];
int  col[100];
int n,e,color;
bool safe(int node,int j)
{
    for(int i=1;i<=n;i++)
    {
        if(con[node][i]==1 && col[i]==j)
            return 0;
    }
    return 1;
}
bool func(int node)
{
    if(node>n)
        return 1;
    for(int i=1;i<=color;i++)
    {
        if(safe(node,i))
        {
            col[node]=1;
            if(func(node+1))
                return 1;
            col[node]=0;
        }
    }
    return 0;
}
int main()
{
    cin>>n>>e>>color;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        con[a][b]=1;
        con[b][a]=1;
    }
    if(func(1))
        cout<<"Yes\n";
    else
        cout<<"No\n";
    return 0;
}
