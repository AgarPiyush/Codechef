#include<stdio.h>
long long int t,i,j,n,p=77,k,l;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		long long int x=1,b=5;
		while(n>0)
		{
			if(n%2==1)
			{
				x=(x*b)%p;
			}
			b=(b*b)%p;
			n=n/2;
			printf("%lld %lld \n",x,b);
		}
//		printf("%lld\n",(x-1)%p);
	}
	return 0;
}
