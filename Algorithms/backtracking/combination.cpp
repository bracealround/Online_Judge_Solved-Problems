#include<bits/stdc++.h>
using namespace std;
string a;
int n,r;
char ans[500];
void combination(int x,int y)
{
    if(y==r)
    {
        cout<<ans<<endl;
        return;
    }
    if(x==n) return;
    ans[y]=a[x];
    combination(x,y+1);
    combination(x+1,y);
}
int main()
{
    cin>>a;
    cin>>r;
    n=a.size();
    combination(0,0);
    return 0;
}
