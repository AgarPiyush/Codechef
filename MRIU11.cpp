#include<stdio.h>
double a,b;
int main()
{
	scanf("%lf %lf",&a,&b);
	if(a>=b)
	{
		printf("%.2lf\n",b);
	}
	else
	{
		long long int f=(long long int)a;
		if(f%5==0)
		{
			printf("%.2lf\n",b-a-.5);
		}
		else
		printf("%.2lf\n",b);
	}
	return 0;
}
