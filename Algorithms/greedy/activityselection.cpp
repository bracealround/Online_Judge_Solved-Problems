#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >v;
bool cmpr(pair<int,int> p1,pair<int,int>p2)
{
        return p1.second<p2.second;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end(),cmpr);
    int cnt =1;
    int prev=v[0].second;
    cout<<v[0].first<<" "<<v[0].second<<endl;
    for(int i=1;i<=n;i++)
    {
        if(v[i].first>=prev)
        {
            cnt++;
            cout<<v[i].first<<" "<<v[i].second<<endl;
            prev=v[i].second;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
