#include<stdio.h>
int main()
{
	long long int o,e,t,i,j,k,n;
	scanf("%lld",&t);
	while(t--)
	{
		o=0;
		e=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld %lld",&j,&k);
			if(k&1) o++;
			else e++;
		}
		int ans=o%2;
		if(ans==0)
		printf("YES\n");
		else
		printf("NO\n");
	}
}
