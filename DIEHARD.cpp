#include<stdio.h>
long long int  n,m,i,j,k,t,sum1=0,sum2=0,i1,j1,a[1005][1005],h=1,ar=1;

int main()
{
	for(i=1;i<=1000;i++)
	{
		for(j=1;j<=1000;j++)
		{
			a[i][j]=1;
			i1=i+3;
			j1=j+2;
			a[i1][j1]=1;
			sum1=sum2=1;
			if(i1>5&&j1>10)
			sum1=a[i1-5][j1-10]+2;
			if(i1>20)
			sum2=a[i1-20][j1+5]+2;
			if(sum1>sum2)
			a[i][j]=sum1;
			else
			a[i][j]=sum2;
		}
	}
	/*for(i=0;i<=20;i++)
	{
		for(j=0;j<=20;j++)
		{
			printf("%lld ",a[i][j]);
		}
		printf("\n");
	}*/
	scanf("%lld",&k);
	while(k--)
	{
		scanf("%lld %lld",&m,&n);
		printf("%lld\n",a[m][n]);
	}
	return 0;
}
