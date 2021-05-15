#include<bits/stdc++.h>
using namespace std;
int a,b;
int md;
void multiply(int f[2][2],int m[2][2])
{
    int x=(f[0][0]%md*m[0][0]%md)%md+(f[0][1]%md*m[1][0]%md)%md;
    int y=(f[0][0]%md*m[0][1]%md)%md+(f[0][1]%md*m[1][1]%md)%md;
    int z=(f[1][0]%md*m[0][0]%md)%md+(f[1][1]%md*m[1][0]%md)%md;
    int w=(f[1][0]%md*m[0][1]%md)%md+(f[1][1]%md*m[1][1]%md)%md;
    f[0][0] = x%md;
    f[0][1] = y%md;
    f[1][0] = z%md;
    f[1][1] = w%md;
    return;
}
void power(int n,int f[2][2])
{
    if(n==0 || n==1)
        return;
    int m[2][2]={{1,1},{1,0}};
    power(n/2,f);
    multiply(f,f);
    if((n&1)!=0)
        multiply(f,m);
    return;
}
int fib(int n)
{
    int f[2][2]={{1,1},{1,0}};
    if(n==0)
        return 0;
    power(n-1,f);
    return ((f[0][0]%md)*(b%md))%md+((f[0][1]%md)*(a%md))%md;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int ms;
        int x;
        md=1;
        cin>>a>>b>>x>>ms;
        for(int j=0;j<ms;j++)
            md*=10;
        cout<<"Case "<<i+1<<": "<<fib(x)%md<<endl;
    }
    return 0;
}
