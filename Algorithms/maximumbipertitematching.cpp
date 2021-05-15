#include<bits/stdc++.h>
using namespace std;
map<int,vector<int> >mp;
map<int,int>mp2;
int n,m;
vector<int>v1,v2;
int r[1000];
bool seen[1000];
bool match(int u)
{
    for(int j=0;j<mp[u].size();j++)
    {
        int z=mp[u][j];
        if(seen[z])
            continue;
        seen[z]=1;
        if(r[z]==-1 || match(r[z]))
        {
            r[z]=u;
            return true;
        }
    }
    return false;
}
int bpm()
{

    memset(r,-1,sizeof(r));
    int result=0;
    for(int i=0;i<n;i++)
    {
        if(mp[i].empty())
            continue;
        memset(seen,0,sizeof(seen));
        if(match(i))
            result++;
    }
    return result;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        mp.clear();
        v1.clear();
        v2.clear();
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            v1.push_back(x);
        }
        cin>>m;
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            v2.push_back(x);
        }
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(v2[k]%v1[j]==0)
                {
                    mp[j].push_back(k);
                }
            }
        }
        cout<<"Case "<<i+1<<": "<<bpm()<<endl;;
    }
}
