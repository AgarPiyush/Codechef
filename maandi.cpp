#include<stdio.h>
#include<math.h>
long long int a[10000000],rem,t,i,j,k,l,n;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		long long int c=0;
		scanf("%lld",&n);
		k=(long long int)sqrt(n);
		for(i=1;i<=k;i++)
		{
			if(n%i==0)
			{
				a[c++]=i;
				if(i!=n/i)
				a[c++]=n/i;
			}
		}
		j=0;
		for(i=0;i<c;i++)
		{
			while(a[i]>0)
			{
				rem=a[i]%10;
				if(rem==7||rem==4)
				{
				j++;
				break;
				}
				a[i]=a[i]/10;
			}
			a[i]=0;
		}
		printf("%lld\n",j);
	}
	return 0;
	
}
