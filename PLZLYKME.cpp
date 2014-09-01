#include<stdio.h>
double i,j,s,c,t,l;
long long int d;
double power(double b,long long int p)
{
	double x=1;
	while(p>0)
	{
		if(p%2==1) x=x*b;
		b=b*b;
		p=p/2;
	}
	return x;
}
int main()
{
	scanf("%lf",&t);
	while(t--)
	{
		scanf("%lf %lld %lf %lf",&l,&d,&s,&c);
		double ans=power(1+c,d-1);
		ans=ans*s;
//		printf("%.0lf\n",ans);
		if(ans>=l) printf("ALIVE AND KICKING\n");
		else printf("DEAD AND ROTTING\n");
	}
	return 0;
}
