#include<stdio.h>
long long int cal(long long int);
long long int a[1000000]={0};
long long int b[1000000],n;
int main()
{
	long long int i,j,k;
	for(i=4;i<=10000;i=i+2)
	a[i]=1;
	for(i=3;i*i<=10000;i=i+2)
	{
		if(a[i]==0)
		{
			for(j=3;j*i<=10000;j=j+2)
			{
				a[i*j]=1;
			}
		}
	}
	k=0;
	b[k++]=2;
	long long int ans;
	for(i=3;i<=1000000;i=i+2)
	if(a[i]==0)
	b[k++]=i;
	long long int l;
	for(i=0;i<100;i++)
	{
	for(j=1;j<=1000000;j++)
	{
	for(l=1;l<=1000000;l++)
	{
		if((l*l+j*j)==b[i])
		printf("%lld ",b[i]);
		if((l*l+j*j)>b[i])
		break;
	}
	}
	}
	return 0;
}
