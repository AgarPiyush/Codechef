#include<stdio.h>
long long int a[12]={0,1,2,5,15,52,203,877,4140,21147,115975,678570};
int main()
{
	long long int t,n;
	scanf("%lld",&t);
	while(t>0)
	{
		scanf("%lld",&n);
		printf("%lld\n",a[n]);
		t--;
	}
	return 0;
}
