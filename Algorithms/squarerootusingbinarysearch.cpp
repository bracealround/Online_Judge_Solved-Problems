#include<bits/stdc++.h>
using namespace std;
double ab,ca,bc,onu;
double arr,arrade,arrbdec;
double func(double x)
{
    double low=0,high=x,mid;
    while((high-low)>.0000001)
    {
        //cout<<high<<" "<<low<<endl;
        mid=(high+low)/2;
        if((mid*mid)==x)
            break;
        else if((mid*mid)>x)
            high=mid;
        else
            low=mid;
    }
    return mid;
}
int main()
{
    return 0;
}
