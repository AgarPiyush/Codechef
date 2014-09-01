#include<stdio.h>
typedef long long int ll;
inline ll max(ll a,ll b,ll c)
{
	if(a>=b&&a>=c) return a;
	if(b>=a&&b>=c) return b;
	return c;
}
inline ll min(ll a,ll b,ll c)
{
//	printf("here %d %d %d\n",a,b,c);
	if(b>=a&&c>=a) return a;
	if(a>=b&&c>=b) return b;
	return c;
}
int main()
{
	ll t,dp[100000][2],n,chk1,chk2,a[100000],i,j,k,l;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++) 
		{
		dp[i][0]=dp[i][1]=0;
		scanf("%lld",&a[i]);
		}
		if(n==1) printf("%lld\n",a[0]);
		else
		{
		dp[1][0]=min(a[0]+a[1],a[0]-a[1],a[0]*a[1]);
		dp[1][1]=max(a[0]+a[1],a[0]-a[1],a[0]*a[1]);
	//	printf("%d",dp[1][0]);
		for(i=2;i<n;i++)
		{
			chk1=min(dp[i-1][0]+a[i],dp[i-1][0]-a[i],dp[i-1][0]*a[i]);
			chk2=min(dp[i-1][1]+a[i],dp[i-1][1]-a[i],dp[i-1][1]*a[i]);
			if(chk1>chk2) dp[i][0]=chk2;
			else 		  dp[i][0]=chk1;
		//	printf("min %d\n",dp[i][0]);
			chk1=max(dp[i-1][0]+a[i],dp[i-1][0]-a[i],dp[i-1][0]*a[i]);
			chk2=max(dp[i-1][1]+a[i],dp[i-1][1]-a[i],dp[i-1][1]*a[i]);
			if(chk1<chk2) dp[i][1]=chk2;
			else 		  dp[i][1]=chk1;
		//	printf("max %d\n",dp[i][1]);
		}
	/*	for(i=1;i<n;i++)
		{
			for(j=0;j<2;j++)
			printf("%d ",dp[i][j]);
			printf("\n");
		}*/
		printf("%lld\n",dp[n-1][0]);
		}
	}
}
