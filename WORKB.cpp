#include<stdio.h>
long long int a[1000000];
int main()
{
	long long int j,t,n,c,s;
	scanf("%lld",&t);
	for(j=1;j<=t;j++)
	{
		long long int sum=0,i,k,f;
		scanf("%lld %lld %lld",&n,&c,&s);
		sum=c+s;
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		for(i=0;i<n-1;i++)
		{
			k=a[i+1]-a[i];
			k=k*s;
			f=c*2;
			if(k<=f)
			sum=sum+k;
			else
			{
				sum=sum+f+s;
			}
		}
		sum=sum+c;
		printf("Case #%lld: %lld\n",j,sum);
	
	}
}
