#include<stdio.h>
long long int gcd(long long int a,long long int b)
{
	if(b==0)
	return a;
	else
	return gcd(b,a%b);
}

int main()
{
	long long int i,j,k,l,m,n,t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld %lld %lld",&i,&j,&k,&l);
		m=i-k;
		if(m<0)
		m=-m;
		n=j-l;
		if(n<0)
		n=-n;
		long long int y=gcd(m,n);
		long long int ans=m+n-y;
		printf("%lld\n",ans);
	}
	
	return 0;
}
