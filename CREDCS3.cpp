#include<stdio.h>
long long int a[1000000],i,j,k,n,m,l,t,mod=1000000000+7;
int main()
{
	a[0]=0;
	a[1]=1;
	for(i=2;i<=104;i++)
	{
		a[i]=((i+i-1)*a[i-1])%mod;
	}
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",a[n]);
	}
	return 0;
}
