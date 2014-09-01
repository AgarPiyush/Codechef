#include<stdio.h>
long long int a[100000],b[100000],i,j,k,l,m,n,t;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		long long int x1,y1;
		scanf("%lld",&n);
		long long int chx=0,chy=0;
		for(i=1;i<=n;i++)
		{
			
			scanf("%lld",&x1,&y1);
			for(i=0;i<chx;i++)
			{
				if(a[i]==x1)
				{
					flag1=1;
					break;
				}
			}
			for(i=0;i<chy;i++)
			{
				if(b[i]==y1)
				{
					flag2=1;
					break;
				}
			}
			if(flag1==0)
			a[chx++]=x1;
			if(flag2==0)
			b[chy++]=y1;
		}
		for(i=0;i<chx;i++)
		printf("%lld ",a[i]);
		printf("\n");
		for(i=0;i<chy;i++)
		printf("%lld ",b[i]);
		printf("\n");
		
	}
	return 0;	
}
