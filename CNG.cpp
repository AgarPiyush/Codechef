#include<stdio.h>
long long int i,j,k,t,c,d;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		long long int a[100000]={0},max=0;
		scanf("%lld %lld",&c,&d);
		long long int pro=c*d;
		pro=pro-c;
		pro=pro-d;
		printf("%lld\n",pro);
	}
	return 0;
}
