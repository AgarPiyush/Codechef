#include<stdio.h>
long long int a[10000000];
long long int fibo(long long int);
int main()
{
	long long int i,j,k,l,m;
	for(i=0;i<=11;i++)
	a[i]=i;
	for(i=12;i<=10000000;i++)
	a[i]=a[i/2]+a[i/3]+a[i/4];
	long long int n;
	while(scanf("%lld",&n)!=EOF)
	{
		if(n<=10000000)
		printf("%lld\n",a[n]);
		else
		{
		long long int res;
		res=fibo(n);
		printf("%lld\n",res);
		}
	}
	return 0;
}
long long int fibo(long long int n)
{
	if(n<=10000000)
	return a[n];
	else
	return fibo(n/3)+fibo(n/2)+fibo(n/4);
	
}
