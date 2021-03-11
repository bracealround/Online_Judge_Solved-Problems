#include<stdio.h>
int main()
{
	int T,n,N,test,f;
	scanf("%d\n",&test);
	for(f=1;f<=test;f++)
	{
	scanf("%d\n",&T);
	int count=0;
	
	for(n=1;n<=T;n++)
	{
		scanf("%d\n",&N);
		if(N<0)
		{
			N=0;
		}
		count=count+N;
	}
	printf("Case %d: %d\n",f,count);
    }
    return 0;
	
}
