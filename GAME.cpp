#include<stdio.h>
int main()
{
	long long int a[500][500],i,j;
	for(i=1;i<=200;i++)
	{
		a[i][1]=1;
		a[1][i]=1;
		a[i][i]=0;
	}
	long long int k;
	for(i=2;i<=200;i++)
	{
		k=0;
		for(j=i+1;j<=200;j++)
		{
			k=0;
			int copy=j-i;
			while(copy>i)
			{
				
				if(copy>0)
				if(a[i][copy]==0)
				{
					k=1;
					break;
				}
				copy=copy-i;
			}
			if(k==1||a[copy][i]==0)
			{
			a[i][j]=1;a[j][i]=1;
			}
			else
			a[i][j]=0;
			
		}
	}
	/*for(i=1;i<=6;i++)
	{
		for(j=1;j<=6;j++)
		printf("%lld ",a[i][j]);
		printf("\n");
	}*/
		long long int t;
		scanf("%lld",&t);
		while(t--)
		{
		long long int o=0,n,c,d;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld %lld",&c,&d);
			while(c>100||d>100)
			{
		//					printf("%d %d\n",c,d);
				if(d!=0)
				c=c%d;
				if(c!=0)
				d=d%c;
				if(c==0||d==0)
				break;
			}
		//	printf("%d %d\n",c,d);
			 if(a[c][d]) o++;
		}
		int ans=o%2;
		if(ans==0)
		printf("NO\n");
		else
		printf("YES\n");
		}
	return 0;
}
