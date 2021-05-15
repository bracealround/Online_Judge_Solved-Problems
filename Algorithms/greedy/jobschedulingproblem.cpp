#include<bits/stdc++.h>
using namespace std;
struct job{
    char id;
    int dead;
    int profit;
};
vector<job>v;
bool flag[1000];
bool cmpr(job j,job k)
{
    return j.profit>k.profit;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        int a,b;
        cin>>a>>b;
        v.push_back({c,a,b});
    }
    sort(v.begin(),v.end(),cmpr);
    int pro=0;
    for(int i=0;i<n;i++)
    {
        int x=v[i].dead;
        while(1)
        {
            if(flag[x]==0)
            {
                flag[x]=1;
                pro+=v[i].profit;
                break;
            }
            else if(x==1)
                break;
            else
                x--;
        }
    }
    cout<<pro<<endl;
    return 0;
}
