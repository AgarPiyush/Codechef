#include<stdio.h>
int main()
{
	long long int t,n,m;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&m,&n);
		if(m%2==1&&n%2==1) printf("Ramesh\n");
		else
		printf("Suresh\n");
	}
	return 0;
}
