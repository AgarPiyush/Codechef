#include<stdio.h>
typedef long long int ll;
ll a[10010],b[10010],i,n,j,k,l,t;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		scanf("%lld",&a[0]);
		/*if(n==1)
		printf("0\n");
		else
		{*/
		int k=1;
		for(i=1;i<n;i++)
		{
			scanf("%lld",&a[i]);
			b[i-1]=a[i]-a[i-1];
		}
		ll sum=0,sum1=0,c=1;
		for(i=n-2;i>=0;i--)
		{
				sum1+=c*b[i];
			//	printf("%lld\n",sum1);
				sum+=sum1;
				c++;
		}
		printf("%lld\n",sum);
		
	}
	
	
	return 0;
}


