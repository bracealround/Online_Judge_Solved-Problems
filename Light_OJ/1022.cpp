#include<stdio.h>
#include<math.h>
int main()
{
	double r,a,area;
	int n,i;
	scanf("%d",&n);
	double pi=2*acos(0.0);
	for(i=1;i<=n;i++)
	{
	scanf("%lf",&r);
	a=2*r;
	area=(a*a)-(pi*r*r);
	printf("Case %d: %0.2lf\n",i,area);
    }
	return 0;
}
