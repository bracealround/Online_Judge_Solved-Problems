#include<bits/stdc++.h>
using namespace std;
vector<int>v,tail;
int binary(int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (tail[m] >= key)
            r = m;
        else
            l = m;
    }

    return r;
}
int lis()
{
    if(v.size()==0)
        return 0;
    int l=1;
    int n=v.size();
    tail[0]=v[0];
    for(int i=0;i<n;i++)
    {
        if(v[i]<tail[0])
            tail[0]=v[i];
        else if(v[i]>tail[l-1])
            tail[l++]=v[i];
        else
            tail[binary(-1,l-1,v[i])]=v[i];
    }
    return l;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    tail.resize(v.size()+5);
    cout<<lis()<<endl;
    return 0;
}
