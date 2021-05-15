#include<bits/stdc++.h>
using namespace std;
int piles[60];
int grundy[1000];
int calculate_mex(set<int>st)
{
    int mex=0;
    while(st.find(mex)!=st.end())
        mex++;
    return mex;
}
int calculate_grundy(int n)
{
    grundy[0]=0;
    grundy[1]=1;
    grundy[2]=2;
    grundy[3]=3;
    if(grundy[n]!=-1)
        return grundy[n];
    set<int>st;
    for(int i=1;i<=3;i++)
    {
        st.insert(calculate_grundy(n-i));
    }
    grundy[n]=calculate_mex(st);
    return grundy[n];
}
void declare(int n)
{
    int xr=grundy[piles[0]];
    for(int i=1;i<n;i++)
    {
        xr^=grundy[piles[i]];
    }
    if(xr!=0)
    {
        cout<<"p1 wins"<<endl;
    }
    else
    {
        cout<<"p2 wins"<<endl;
    }
}
int main()
{
    memset(grundy,-1,sizeof(grundy));
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>piles[i];
    }
    for(int i=0;i<n;i++)
    {
        calculate_grundy(piles[i]);
    }
    declare(n);
    return 0;
}
