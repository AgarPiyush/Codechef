#include<stdio.h>
int a[]={0,1,3,6,10,15,21,28,36,45};
typedef long long int ll;
ll sumcal(ll copy)
{
		ll mul=1,sum=0;
		while(copy>0)
		{
			int sumdig=0;
			int rem=copy%10;
			sum=sum+a[rem]*mul;
			copy=copy/10;
			sum=sum+copy*45*mul;
			ll copy2=copy;
			while(copy2>0)
			{
				sumdig=sumdig+copy2%10;
				copy2/=10;
			}
			sum=sum+(rem+1)*sumdig*mul; 
			mul=mul*10;	
			copy=copy-1;
		}
		return sum;
}
int main()
{
	ll n,m,i,j,k;
	scanf("%lld %lld",&m,&n);
	while(n!=-1&&m!=-1)
	{
		ll sum,sum2;
		sum=sumcal(n);
		sum2=sumcal(m-1);
		printf("%lld\n",sum-sum2);
		scanf("%lld %lld",&m,&n);

	}

	return 0;
}
