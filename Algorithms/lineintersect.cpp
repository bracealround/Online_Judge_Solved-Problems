#include<bits/stdc++.h>
using namespace std;
struct point{
    int x,y;
};
void input(struct point a)
{
    cin>>a.x>>a.y;
    return;
}
int orientation(struct point p1,struct point p2,struct point p3)
{
    int fuck=(p2.y-p1.y)*(p3.x-p2.x)-(p3.y-p2.y)*(p2.x-p1.x);
    if(fuck==0)
        return 0;
    else if(fuck>0)
        return 1;
    else
        return -1;
}
bool intersection(struct point p,struct point q,struct point r)
{
    if(min(p.x,r.x)<=q.x && max(p.x,r.x)>=q.x)
        return 1;
    else
        return 0;
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        struct point l1,l2,p1,p2,p3,p4;
        input(l1);
        input(l2);
        input(p1);
        input(p3);
        p2.x=p3.x;
        p2.y=p1.y;
        p4.x=p1.x;
        p4.y=p3.y;
        int o1=orientation(p1,p2,l1);
        int o2=orientation(p1,p2,l2);
        int o3=orientation(l1,l2,p1);
        int o4=orientation(l1,l2,p2);
        bool b;
        if((o1!=o2) && (o3!=o4) || ((o1==0) && intersection(p1,p3,p2)==1) || ((o1==0) && intersection(p1,p4,p2)==1) || ((o1==0) && intersection(p3,p1,p4)==1))
            b=1;
        if(b==1)
        {
            cout<<"T"<<endl;
            continue;
        }
        o1=orientation(p2,p3,l1);
        o2=orientation(p2,p3,l2);
        o3=orientation(l1,l2,p2);
        o4=orientation(l1,l2,p3);
        if((o1!=o2) && (o3!=o4) || ((o1==0) && intersection(p1,p3,p2)==1) || ((o1==0) && intersection(p1,p4,p2)==1) || ((o1==0) && intersection(p3,p1,p4)==1))
            b=1;
        if(b==1)
        {
            cout<<"T"<<endl;
            continue;
        }
        o1=orientation(p3,p4,l1);
        o2=orientation(p3,p4,l2);
        o3=orientation(l1,l2,p3);
        o4=orientation(l1,l2,p4);
        if((o1!=o2) && (o3!=o4) || ((o1==0) && intersection(p1,p3,p2)==1) || ((o1==0) && intersection(p1,p4,p2)==1) || ((o1==0) && intersection(p3,p1,p4)==1))
            b=1;
        if(b==1)
        {
            cout<<"T"<<endl;
            continue;
        }
        o1=orientation(p4,p1,l1);
        o2=orientation(p4,p1,l2);
        o3=orientation(l1,l2,p4);
        o4=orientation(l1,l2,p1);
        if((o1!=o2) && (o3!=o4) || ((o1==0) && intersection(p1,p3,p2)==1) || ((o1==0) && intersection(p1,p4,p2)==1) || ((o1==0) && intersection(p3,p1,p4)==1))
            b=1;
        if(b==1)
        {
            cout<<"T"<<endl;
            continue;
        }
        cout<<"F"<<endl;
    }
    return 0;
}
