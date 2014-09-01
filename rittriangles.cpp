#include<stdio.h>
long long int x1,y2,x2,y1,x3,y3,t;
int main()
{
	long long int c=0;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&x3,&y3);
		long long int x4,y4,x5,y5,x6,y6,d1,d2,d3;
		x4=x2-x1;	
		x5=x3-x1;
		x6=x2-x3;

		x4=x4*x4;
		x5=x5*x5;
		x6=x6*x6;
		
		y4=y2-y1;
		y5=y3-y1;
		y6=y2-y3;
		
		y4=y4*y4;
		y5=y5*y5;
		y6=y6*y6;
		d1=x4+y4;
		d2=x5+y5;
		d3=x6+y6;
		if(((d1+d2)==d3)||((d1+d3)==d2)||((d3+d2)==d1))
		c++;
	}
	printf("%lld\n",c);
	return 0;
}
