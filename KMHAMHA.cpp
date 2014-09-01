#include<stdio.h>
long long int a[100000],b[1000000],c[1000000],d[1000000],i,j,k,l,m,n;
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		
		long long int x1,y1, flag2=0,flag1=0;
		scanf("%lld",&n);
		long long int chx=0,chy=0;
		for(j=1;j<=n;j++)
		{
			 flag2=0,flag1=0;
			scanf("%lld %lld",&x1,&y1);
			for(i=0;i<chx;i++)
			{
				if(a[i]==x1&&b[i]==y1)
				{
					flag1=1;
					break;
				}
			}
			if(flag1==0)
			{
				a[chx]=x1;
				c[chx]=x1;
				d[chx]=y1;
				b[chx++]=y1;
			}
		}
		long long int f=0,g=0;
		for(i=0;i<chx;i++)
			if(a[i]!=-1)
			{
		//	printf("%lld ",a[i]);
			}
		//	printf("\n");
			for(i=0;i<chx;i++)
			if(b[i]!=-1)
			{
				
			//printf("%lld ",b[i]);
			}
			//printf("\n");
			//printf("sevo\n");
			for(i=0;i<chx;i++)
			{
				if(a[i]!=-1)
				{
				for(j=i+1;j<chx;j++)
				{
					if(a[i]==a[j]&&a[j]!=-1)
					{
						
						a[j]=-1;
						b[j]=-1;
					}
				}
				}
			}
			for(i=0;i<chx;i++)
			{
				if(b[i]!=-1)
				{
				for(j=i+1;j<chx;j++)
				{
					if(b[i]==b[j]&&b[j]!=-1)
					{
						a[j]=-1;
						b[j]=-1;
					}
				}
				}
			}
			for(i=0;i<chx;i++)
			if(a[i]!=-1)
			{
			f++;
			//printf("%lld ",a[i]);
			}
			//printf("\n");
			for(i=0;i<chx;i++)
			if(b[i]!=-1)
			{
			g++;
			//printf("%lld ",b[i]);
			}
			long long int min;
			if(f>g)
			min=g;
			else
			min=f;
			printf("\n");
			flag1=flag2=0;
			for(i=0;i<chx;i++)
			{
				if(a[i]!=-1)
				{
					for(j=i+1;j<chx;j++)
					{
						if(c[j]==a[i])
						{
							flag1=1;
							break;
						}
					}
					for(j=i+1;j<chx;j++)
					{
						if(d[j]==b[i])
						{
							flag2=1;
							break;
						}
					}
				
				if(flag1==1&&flag2==1)
				chy+=2;
				else
				chy++;
				}
			}
			if(min>chy)
			printf("%lld\n",chy);
			else
			printf("%lld\n",min);
		
	}
	return 0;	
}
