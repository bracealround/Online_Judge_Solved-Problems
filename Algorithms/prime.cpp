#include<bits/stdc++.h>
using namespace std;
vector<int>v;
bool vis[10005];
void prime()
{
    v.push_back(2);
    int y=sqrt(10005);
    for(int i=3;i<=y;i+=2)
    {
        if(vis[i]==1)
            continue;
        for(int j=i*i;j<=10000;j=j+(2*i))
        {
            vis[j]=1;
        }
    }
    for(int i=3;i<=10000;i+=2)
    {
        if(vis[i]==0)
            v.push_back(i);
    }
    return;
}
int main()
{
    bool c=2;
    cout<<c<<endl;
    return 0;
}
