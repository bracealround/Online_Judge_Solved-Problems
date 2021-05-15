#include<bits/stdc++.h>
using namespace std;
int n;
int row[50],ans[50],p45d[50],n45d[50];
void nq(int c)
{
    if(c>n)
    {
        for(int i=1;i<=n;++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!row[i] && !p45d[i+c] && !n45d[n+i-c])
        {
            ans[c]=i;
            row[i]=1;
            p45d[i+c]=1;
            n45d[n+i-c]=1;
            nq(c+1);
            row[i]=0;
            p45d[i+c]=0;
            n45d[i+n-c]=0;
        }
    }
    return;
}
int main()
{
    cin>>n;
    nq(1);
    return 0;
}
