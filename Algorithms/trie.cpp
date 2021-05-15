#include<bits/stdc++.h>
using namespace std;
int trie[10000][28];
void build(string s)
{
    int x=s.size();
    int pos=0,cnt=0;
    for(int i=0;i<x;i++)
    {
        if(trie[pos][s[i]-97]>0)
            pos=trie[pos][s[i]-97];
        else
        {
            trie[pos][s[i]-97]=++cnt;
            pos=cnt;
        }
    }
    trie[pos][27]=1;
    return;
}
void mat(string s)
{
    int x=s.size();
    int pos=0,cnt=0,i;
    for(i=0;i<x;i++)
    {
        if(trie[pos][s[i]-97]>0)
            pos=trie[pos][s[i]-97];
        else
        {
            break;
        }
    }
    if(i==x && trie[pos][27]==1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(trie,0,sizeof(trie));
        int n;
        cin>>n;
        string s;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            build(s);
        }
        cin>>s;
        mat(s);
    }
}
