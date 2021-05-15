#include<bits/stdc++.h>
 using namespace std;
 int w[100];
 int c[100];
 int cap;
 int n;
 int ns(int i,int weight)
 {
     int p1,p2;
     bool p=0;
     if(i>n) return 0;
     if(weight+w[i]<=cap)
     {
        p1=c[i]+ns(i+1,weight+w[i]);
        p=1;
     }
     p2=ns(i+1,weight);
     if(p==0) return p2;
     else return max(p1,p2);
 }
 int main()
 {
     cin>>n>>cap;
     for(int i=1;i<=n;i++)
     {
         cin>>w[i]>>c[i];
     }
     cout<<ns(1,0)<<endl;
     return 0;
 }
