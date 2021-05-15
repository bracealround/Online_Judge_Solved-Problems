#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>v;
bitset<10000010>vis;
void prime(ll num)
{
    v.push_back(2);
    int y=sqrt(num+1);
    for(int i=3;i<=y;i+=2)
    {
        if(vis[i]==1)
            continue;
        for(int j=i*i;j<=10000000;j=j+(2*i))
        {
            vis[j]=1;
        }
    }
    for(int i=3;i<=10000000;i+=2)
    {
        if(vis[i]==0)
            v.push_back(i);
    }
    return;
}
int main()
{
    prime(10000000);
    return 0;
}
