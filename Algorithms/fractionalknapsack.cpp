#include<bits/stdc++.h>
using namespace std;
vector<pair<double,double> >v;
bool cmpr(pair<int,int> p1,pair<int,int>p2)
{
    double x=p1.first;
    double y=p2.first;
    return p1.first>p2.first;
}
int main()
{
    int n,cap;
    cin>>n>>cap;
    for(int i=0;i<n;i++)
    {
        double a,b;
        cin>>a>>b;
        v.push_back(make_pair(a/b,b));
    }
    sort(v.begin(),v.end(),cmpr);
    double sum=0;
    double weight=0;
    for(int i=0;i<n;i++)
    {
        if(weight+v[i].second<=cap)
        {
            sum+=(v[i].first*v[i].second);
            weight+=v[i].second;
        }
        else
        {
            int x=cap-weight;
            sum+=v[i].first*x;
        }
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
