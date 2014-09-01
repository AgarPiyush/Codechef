#include<stdio.h>
long long int a[100000];
int main()
{
	long long int t,i,j,k,l,m,n;
//	scanf("%lld",&t);
/*	while(t--)
	{*/
		//min=1000000;
		long long int c=0,flag=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
		scanf("%lld",&a[i]);
		if(a[i]>=0)
		flag=1;
		}
		if(flag==0)
		{
			printf("1\n");
		}
		else
		{
		long long int b=1000000;
		long long int z=0,p=0,neg=0;
		if(a[0]==0)
		z++;
		else if(a[0]>0)
		p++;
		for(i=1;i<n;i++)
		{
			if(a[i]==0)
			z++;
			if(a[i]<0)
			neg++;
		}
	//	printf("pos %lld neg %lld \n",p,neg);
		
		c=neg+p;
		p=0;
		for(i=1;i<n;i++)
		{
			if(a[i-1]>0)
			p++;
			if(a[i]<0&&i!=n-1)
			neg--;
			if((p+neg)<c)
			c=p+neg;
		//	printf("pos %lld neg %lld \n",p,neg);
		}
		printf("%lld\n",c+z);
//	}
	}
	
}
