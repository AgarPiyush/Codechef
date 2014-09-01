#include<stdio.h>
long long int a[1000000],b[1000000];
int main()
{
	long long int i,j;
	long long int t,n;
	scanf("%lld",&t);
	while(t--)
	{
		long long int z=1;
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		b[i]=1;
		long long int flag=0;
		for(i=0;i<n;i++)
		{
		scanf("%lld",&a[i]);
		if(a[i]>=0)
		flag=1;
		}
		if(flag==0)
		{
			printf("1\n");
		}
		else
		{
		b[0]=-1;
		
		long long int c=0,k=1000000000;
		for(i=0;i<n;i++)
		{
			
			for(j=i;j<n;j++)
			{
				if(a[j]>0&&b[j]<0||a[j]==0)
				c++;
				else
				if(a[j]<0&&b[j]>0||a[j]==0)
				c++;
			}
			b[z++]=-1;
			if(c<k)
			{
				k=c;
			}
			printf("compare %lld\n",k);
			if(z==n+1)
			break;
		}
		
		
		if(k==1000000000)
		printf("0\n");
		else
		{
		printf("%lld\n",k);
		}
}
	}
	return 0;
}
