#include<bits/stdc++.h>
using namespace std;
long long int arr[5000000];
long int cnt;
long long int  merge(long long int l,long long int m,long long int r)
{
    //int cnt=0;
    long long int n1=m-l+1;
    long long int n2=r-m;
    long long int left[n1+5];
    long long int right[n2+5];
    for(int i=0;i<n1;i++)
    {
        left[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        right[i]=arr[m+1+i];
    }
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
            l++;
        }
        else
        {
            arr[k]=right[j];
            j++;
            cnt+=m-l+1;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] =left[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
    return cnt;
}
long long int mergesort(long long int l,long long int r)
{
    if(l<r)
    {
        long long int m=(l+r)/2;
        mergesort(l,m);
        mergesort(m+1,r);
        merge(l,m,r);
    }
    return cnt;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cnt=0;
        memset(arr,0,sizeof(arr));
        int n;
        cin>>n;
        for(int j=0;j<n;j++)
            cin>>arr[j];
        cout<<mergesort(0,n-1)<<endl;;
//        for(int j=0;j<n;j++)
//            cout<<arr[j];
    }
    return 0;
}
