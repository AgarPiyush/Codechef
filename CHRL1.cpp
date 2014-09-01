#include<stdio.h>
#define max(a,b) a>b?a:b
typedef long long int ll;
ll t,i,j,n,k;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		ll c[n+1],w[n+1],dp[n+1][k+1],C;
		for(i=1;i<=n;i++)
		scanf("%lld %lld",&c[i],&w[i]);
		for(i=0;i<=n;i++)
		dp[i][0]=0;
		for(i=0;i<=k;i++)
		dp[0][i]=0;
		for(i=1;i<=n;i++)
		{
			for(C=1;C<=k;C++)
			{
				if(C<c[i])
				dp[i][C]=dp[i-1][C];
				else
				dp[i][C]=max(dp[i-1][C],w[i]+dp[i-1][C-c[i]]);
			}
		}
		/*for(i=0;i<=n;i++)
		{
			for(j=0;j<=k;j++)
			printf("%lld ",dp[i][j]);
			printf("\n");
		}*/
		printf("%lld\n",dp[n][k]);
	}
	return 0;
}
