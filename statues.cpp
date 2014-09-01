#include<stdio.h>
long long int i,j,k,l,n,a[1000000];
	
int main()
{
	scanf("%lld",&n);
	l=1;
	
	while(n!=0)
	{
		printf("Set #%lld",l++);
		long long int sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		sum=sum/n;
		k=0;
		for(i=0;i<n;i++)
		{
			if(a[i]>sum)
			k+=a[i]-sum;
			a[i]=0;
		}
		printf("The minimum number of moves is %lld\n",k);
		printf("\n");
		scanf("%lld",&n);
	}
	return 0;
	
}
