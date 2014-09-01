#include<string.h>
#include<stdio.h>
long long int a[10000000]={0};
int main()
{
	long long int i,j,k,t,m,c,d,max;
	scanf("%lld",&t);
	while(t--)
	{
		
		scanf("%lld %lld",&c,&d);
		a[c]=1;
		a[d]=1;
		a[c+d]=1;
		max=c;
		for(i=c;i<=1000;i++)
		{
			if(a[i]==1)
			{
				for(j=1;j*d<1000000;j++)
				{
					a[j*c]=1;
					a[j*d]=1;
					a[(j*i)+c]=1;
					a[(j*i)+d]=1;
				}
			}
		}
		for(i=c;i<=1000000;i++)
		if(a[i]==0)
		max=i;
		printf("%lld",max);
		printf("\n");
	}
}
