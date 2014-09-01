#include<stdio.h>
long long int t,i,j,k,l,a[1000000]={0},b[10000000]={0},c[1000000]={0};
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		long long int flag=0,sum=0,max=0,temp,k=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>0)
			{
			if(flag==1)
			k++;
			b[k++]=a[i];
			flag=0;
			}
			else
			{
				flag=1;
				b[k]=b[k]+a[i];
			}
		}
		if(a[n-1]<0)
		k++;
		for(i=0;i<k;i++)
		printf("%lld ",b[i]);
		printf("\n");
		long long int min=100000000;
		
		sum=0;
		long long int w=0;
		for(i=0;i<k;i++)
		{
			sum=sum+b[i];
			if(sum>0)
			{
				if((sum-b[i])!=0)
				c[w++]=sum-b[i];
				c[w++]=b[i];
				sum=0;
			}
		}
		if(sum<0)
		c[w++]=sum;
	
		for(i=0;i<w;i++)
		printf("%lld ",c[i]);
		
		for(i=0;i<w;i++)
		{
			if(c[i]<min&&c[i]<0)
			{
				min=c[i];
			}
		}
		sum=0;
		for(i=0;i<w;i++)
		{
			if(c[i]==min)
			sum=sum-min;
			else
			sum=sum+c[i];
		}
		
		for(i=0;i<n;i++)
		{
			c[i]=0;
			a[i]=0;
			b[i]=0;
		}
		printf("%lld\n",sum);
		
	}
	return 0;
}
