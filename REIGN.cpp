#include<stdio.h>
#include<limits.h>
#define max(a,b) a>b?a:b
typedef long long int lll;
lll i,j,k,l,n,a[1000000],b[1000000],c[1000000],t;
	
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		for(i=0;i<n;i++) scanf("%lld",&a[i]);
		lll sum=b[0]=a[0];
		for(i=1;i<n;i++)
		{
			if(sum+a[i]>a[i])
			sum=sum+a[i];
			else
			sum=a[i];
			
			b[i]=max(sum,b[i-1]);
		}
		/*for(i=0;i<n;i++) printf("%lld ",b[i]);
		printf("\n");*/
		sum=c[n-1]=a[n-1];
		for(i=n-2;i>=0;i--)
		{
			if(sum+a[i]>a[i])
			sum=sum+a[i];
			else
			sum=a[i];
			c[i]=max(sum,c[i+1]);
		}
	/*	for(i=0;i<n;i++) printf("%lld ",c[i]);
		printf("\n");*/
		lll ans=LONG_MIN;
		for(i=0;i<n-k-1;i++)
		{
			ans=max(ans,b[i]+c[i+k+1]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
