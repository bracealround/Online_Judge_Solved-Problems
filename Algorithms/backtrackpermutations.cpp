#include<bits/stdc++.h>
using namespace std;
int s;
vector<int>v;
string a;
char ans[500];
map<char,bool>mp;
int vis[50];
void permutation(int cnt)
{
    if(cnt==s)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s;i++)
    {
        if(mp[a[i]]==1)
            continue;
        mp[a[i]]=1;
        ans[cnt]=a[i];
        permutation(cnt+1);
        mp[a[i]]=0;
    }
    return ;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a;
        s=a.size();
        permutation(0);
    }
    return 0;
}
