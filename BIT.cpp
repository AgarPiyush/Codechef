#include<stdio.h>
int dp[3000];
 
int main()
{
		int dp[3000],j,sum=0,i,bits,n,sum1[3000];
		dp[0]=dp[2]=dp[4]=dp[8]=dp[16]=dp[32]=dp[64]=dp[128]=dp[256]=dp[512]=dp[1024]=dp[1]=1;
		int pow[]={1,2,4,8,16,32,64,128,256,512,1028};
		sum=2;
		sum1[1]=1;
		sum1[2]=2;
		for(i=3;i<=1000;i++)
		{
			for(j=0;j<=10;j++)
			{
				if(i<=pow[j])
				break;
			}
			if(!dp[i])
			dp[i]=dp[1<<(j-1)]+dp[i-(1<<(j-1))];
			sum=sum+dp[i];
			sum1[i]=sum;
		}
		int t;
		scanf("%d",&t);
		while(t--)
		{
			scanf("%d",&n);printf("%d\n",sum1[n]);
			
		}
		return 0;
} 
