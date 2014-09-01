#include<stdio.h>
int i,j,k,l,a[200][200],n,m,t,b[1000];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<=100;i++)
		for(j=0;j<=100;j++)
		a[i][j]=0;
		scanf("%d %d",&n,&m);
		
			for(i=1;i<=m;i++)
			{
				scanf("%d %d",&k,&l);
				a[k][l]=1;
				a[l][k]=1;
			}
				for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++) printf("%d ",a[i][j]);
				printf("\n");
			}
			printf("\n \n");
			
			if(n%2==1)  printf("NO\n");
			else
			{
			int c=0,flag=0,count=0;
			for(i=1;i<=n;i++)
			{
				c=0;
				for(j=1;j<=n;j++)
				{
					if(a[i][j]==1)
					{
					c++;k=j;
					}
				}
				if(c==1)
				{
					a[i][k]=0;
					a[k][i]=0;
					flag=1;
					b[i]=b[k]=1;
					for(j=1;j<=n;j++)
					{
						a[k][j]=0;
					}
					if(k<i)
					i=k;
					continue;
				}
			}
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++) printf("%d ",a[i][j]);
				printf("\n");
			}
			if(flag==0)
			printf("YES\n");
			else
			{
			int flag1=0;
			for(i=1;i<=n;i++)
			if(b[i]==1) count++;
			if(count==n)
			printf("full YES\n");
			else
			{
				for(i=1;i<=n;i++)
				{
					if(!b[i])
					{
					flag1=0;
					for(j=1;j<=n;j++)
					{
						if(a[i][j])
						flag1=1;
					}
					if(flag1==0)break;
					}
				}
				if(flag1==0) printf("NO\n");
				else printf("YES\n");
			}
			}
			}
		
	}
	return 0;
}

