#include<bits/stdc++.h>
using namespace std;
string text,pat;
int lps[1000005];
int mat()
{
    int s=pat.size(),st=text.size();
    int i,pos=0,f=0;
    int cnt=0;
    for(i=0;i<st;i++)
    {
        if(text[i]==pat[pos])
            ++pos;
        else
        {
            pos=lps[pos-1];
            f=1;
            while(text[i]!=pat[pos])
            {
                if(pos==0)
                {
                    f=0;
                    break;
                }
                pos=lps[pos-1];
            }
            if(f==1)
                ++pos;
        }
        if(pos==s)
        {
            pos=lps[pos-1];
            cnt++;
        }
    }
    return cnt;
}
void lpsf()
{
    int s=pat.size();
    int i,pos=0,f=0;
    for(i=1;i<s;i++)
    {

            pos=lps[i-1];
            f=1;
            while(pat[i]!=pat[pos])
            {
                if(pos==0)
                {
                    f=0;
                    lps[i]=0;
                    break;
                }
                pos=lps[pos-1];
            }
            if(f==1)
                lps[i]=++pos;
    }
    return;
}
int main()
{
    freopen("input.txt","r+",stdin);
    freopen("output.txt","w+",stdout);
    int t;
    cin>>t;
  
    cout<<t;
    return 0;
}
