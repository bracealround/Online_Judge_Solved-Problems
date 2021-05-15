#include<bits/stdc++.h>
using namespace std;
int arr[100005],sparse[100005][20];
int n,q;
void preprocess()
{
    int x=log2(n),y=0,z;
    //cout<<x<<endl;
    for(int i=0;i<=x;i++)
    {
        for(int j=0;j<(n-y);j++)
        {
            if(i==0)
                sparse[j][i]=arr[j];
            else
                sparse[j][i]=min(sparse[j][i-1],sparse[j+z][i-1]);
            //cout<<sparse[j][i]<<" ";
        }
        y=y*2+1;
        z=(y+1)/2;
        z=z;
        //cout<<y<<z<<endl;
        //cout<<endl;
    }
    return;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        memset(arr,0,sizeof(arr));
        memset(sparse,0,sizeof(sparse));
        scanf("%d %d",&n,&q);
        for(int j=0;j<n;j++)
            scanf("%d",&arr[j]);
        preprocess();
        printf("Case %d:\n",i+1);
        for(int j=0;j<q;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            if(a>b)
                swap(a,b);
            a=a-1;
            b=b-1;
            int lv=log2(b-a+1);
            int x=1;
            for(int k=0;k<lv;k++)
            {
                x=x*2;
            }
            //cout<<lv<<" "<<x<<"g"<<endl;
            int y=min(sparse[a][lv],sparse[b-x+1][lv]);
            printf("%d\n",y);
        }
    }
    return 0;
}
