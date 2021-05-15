#include<bits/stdc++.h>
using namespace std;
int arr[305][305];
int n;
bool preferover(int w,int m,int m1)
{
    for(int i=1;i<=n;i++)
    {
        if(arr[w][i]==m)
            return 1;
        if(arr[w][i]==m1)
            return 0;
    }
}
void call(int t)
{
    int wp[500];
    bool fm[500];
    memset(wp,-1,sizeof(wp));
    memset(fm,0,sizeof(fm));
    int free=n;
    while(free>0)
    {
        int m;
        for(m=1;m<=n;m++)
        {
            //cout<<m<<endl;
            if(fm[m]==0)
                break;
        }
        //cout<<m<<endl;
        for(int i=1;i<=n &&fm[m]==0 ;i++)
        {
            int w=arr[m][i];
            if(wp[w-n]==-1)
            {
                wp[w-n]=m;
                fm[m]=1;
                free--;
            }
            else
            {
                //cout<<w<<" "<<wp[w-n]<<endl;
                int m1=wp[w-n];
                if(preferover(w,m,m1)==1)
                {
                    wp[w-n]=m;
                    fm[m]=1;
                    fm[m1]=0;
                }
            }
            //cout<<w<<" "<<wp[w-n]<<endl;
        }
//        for(int i=0;i<n;i++)
//        cout<<i+n<<"-"<<wp[i]<<endl;
    }
    cout<<"Case "<<t+1<<":";
    for(int i=1;i<=n;i++)
        cout<<" ("<<i<<" "<<wp[i]<<")";
        cout<<endl;
        return;
}
int main()
{
    int t;
    cin>>t;
    for(int j=0;j<t;j++)
    {
        cin>>n;

        memset(arr,0,sizeof(arr));
        for(int i=1;i<=2*n;i++)
            for(int j=1;j<=n;j++)
                cin>>arr[i][j];
        call(j);
    }
    return 0;
}
/*
4
7 5 6 4
5 4 6 7
4 5 6 7
4 5 6 7
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
*/

