#include<iostream>
#include<cstdio>
#include<climits>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<cmath>
#include<queue>
using namespace std;
#define inp(a) scanf("%lld",&a)
#define line(a) printf("%lld ",a);
#define next() printf("\n");
#define out(a) printf("%lld\n",a)
#define swap(a,b) {a=a+b;a=a-b;b=a-b;}
#define VI vector<int>
#define VLL vector<long long int>
#define PQI priority_queue<int>
#define PQLL priority_queue<long long int>
#define ll long long int
#define mod 1000000
#define getcx getchar_unlocked
/*inline void fscan(ll *a )
{
	ll n=0; int ch = getcx(); int sign = 1;
	while(ch < '0' || ch > '9')
	{
	if(ch == '-') sign=-1; ch = getcx();
	}
	while(ch >= '0' && ch <= '9')
	{
	n = (n << 3) + (n << 1) + ch - '0', ch = getcx();
	}
	*a = n * sign;
}*/
ll i,j,k,l,t,dp[3000010],hash[3000010],repeat[3000010],all[3000010],pos[3000010],flag;

int main()
{
	inp(t);
	while(t--)
	{
		ll n,a,b,c,d,sum1=0,sum2=0,max,fin=0,count=1;
		flag=0;
		//inp(n);inp(a);inp(b);inp(c);inp(d);
		dp[0]=d;
		max=d;
		hash[dp[0]]=1;
		all[0]=d;
		/*for(i=1;i<n;i++)
		{
			dp[i]=(dp[i-1]*(a*dp[i-1]+b)+c)%mod;
			if(hash[dp[i]]==1)
			{
			flag=1;
			break;
			}
			else
			{
			all[count++]=dp[i];
			pos[dp[i]]=i;
			if(dp[i]>max)
			max=dp[i];
			hash[dp[i]]=1;
			}
		}*/
		
		all[0]=dp[0]=7;all[1]=dp[1]=6;all[2]=dp[2]=1;all[3]=dp[3]=2;all[4]=dp[4]=3;all[5]=dp[5]=4;dp[6]=2;
		flag=1;
		n=10;
		i=6;pos[7]=0;pos[6]=1;pos[1]=2;pos[2]=3;pos[3]=4;pos[4]=5;
		if(flag==1)
		{
			j=0;k=0;
			count=pos[dp[i]];
			printf("count is %lld\n",count);
			ll remain=n-count;
			ll f;
			repeat[k++]=dp[count];
			f=count+1;
			while(dp[f]!=dp[i])
			{
				repeat[k++]=dp[f];
				f++;
			}
			remain=remain%(2*k);
			printf("remain %lld\n",remain);
			ll q=0;
			for(i=0;i<remain;i++)
			{
				all[count++]=repeat[q++];
				if((k)==q)
				q=0;
			}
			printf("now count %lld \n",count);
			for(i=0;i<count;i++)
			printf("%lld ",all[i]);
			printf("sort");
			sort(all,all+count);
		}
		for(i=0;i<k;i++)
		printf("%lld ",repeat[i]);
		printf("\n");
		for(i=0;i<count;i++)
		printf("%lld ",all[i]);
		printf("\n");
		
		c=0;
		for(i=count-1;i>=0;i--)
		{
			if(c%2==0)
			sum1=(sum1+all[i])%mod;
			else
			sum2=(sum2+all[i])%mod;
			c++;
		}
		if(sum1-sum2>0)
		out(sum1-sum2);
		else
		out(sum2-sum1);
		for(i=0;i<count+k;i++)
		{
			hash[dp[i]]=0;
			pos[dp[i]]=0;
			dp[i]=0;
			
		}
	}
	return 0;
}

