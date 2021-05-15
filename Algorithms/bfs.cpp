#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >v;
int vis[50000];
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(vis[x]==1)
            continue;
        vis[x]=1;
        for(int i=0;i<v[x].size();i++)
        {
            int y=v[x][i];
            if(vis[y]==1)
                continue;
            q.push(y);
        }
    }
    return;
}
int main()
{
    return 0;
}
