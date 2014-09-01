#include<stdio.h>
long long int a[1000005],i,q,l,r,j,k;
int main()
{
	long long int n;
	scanf("%lld %lld",&n,&q);
	for(i=0;i<n;i++)
	scanf("%lld",&a[i]);
	for(j=0;j<q;j++)
	{
		long long int c=0;
		scanf("%lld %lld %lld",&l,&r,&k);
		for(i=l-1;i<r;i++)
		{
			if(a[i]%k==0)
			c++;
		}
		printf("%lld\n",c);
	}
	return 0;
}

