#include<stdio.h>
#include<math.h>
double i,j,k,m,n,t,a,b,c;
long long int ans;
int main()
{
	scanf("%lf",&t);
	while(t--)
	{
		scanf("%lf %lf %lf",&n,&k,&m);
		if(m<=n)
		printf("0\n");
		else
		{
		a=log10(k);
		b=log10(m/n);
		ans=(long long int)(ceil)(b/a+.000001);
		printf("%lld\n",ans-1);
		}
	}
	return 0;
}
