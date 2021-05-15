#include<bits/stdc++.h>
using namespace std;
vector<long long int>v,v2;
bool vis[1000005];
long long int arr[1000005];
void prime()
{
    v.push_back(2);
    int y=sqrt(1000005);
    for(int i=3;i<=y;i++)
    {
        if(vis[i]==1)
            continue;
        for(int j=i*i;j<=1000000;j=j+(2*i))
        {
            vis[j]=1;
        }
    }
    for(int i=3;i<=1000000;i+=2)
    {
        if(vis[i]==0)
            v.push_back(i);
    }
    return;
}
void segmentseive(long long int a,long long int b)
{
    if(a==1)
        a++;
        int sq=sqrt(b);
        memset(arr,0,sizeof(arr));
        //cout<<sq<<endl;
        for(int i=0;i<v.size() && v[i]<=sq;i++)
        {
            int p=v[i];
            long long int j=p*p;
            if(j<a)
                j=((a+p-1)/p)*p;
            for(;j<=b;j+=p)
            {
                arr[j-a]=1;
            }
        }
        for ( int i = a; i <= b; i++ ) {
        if ( arr[i-a] == 0 ) v2.push_back(i);
    }
}
int main()
{
    int t;
    cin>>t;
    prime();
    bool b=0;
    for(int i=0;i<t;i++)
    {
        if(b!=0)
            cout<<endl;
        b=1;
        v2.clear();
        long long int a,b;
        cin>>a>>b;
        segmentseive(a,b);
        int s=v2.size();
        for(int j=0;j<s;j++)
        {
            cout<<v2[j]<<endl;
        }
    }
    return 0;
}

