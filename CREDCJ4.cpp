#include<stdio.h>
double x[100000]={0},b,c,d,a;
long long int t,w,i,j,k,l;
int main()
{
    scanf("%lld",&t);
    while(t--)
	{
		double t1=0;
		scanf("%lld",&w);
		scanf("%lf %lf",&a,&b);
		for(i=0;i<w-1;i++)
		scanf("%lf",&x[i]);
		scanf("%lf",&c);
		double u=0,y;
		long long int q,p=1; 
		for(i=0;i<=w-2;i++)
		{
			y=(a-x[i]/2);
			if(y<0)
			{
				if(p==1)
				{
					q=((-y*(x[i]-u))/(y-a))+x[i];
					t1=t1+q/((i+1)*(i+1)+1);
					t1=t1+(x[i]-q)/c;
					p++;
					
				}
				else
				{
					t1=t1+x[i]/c;
				}
				a=0;
			}
			else
			{
				t1=t1+x[i]/((i+1)*(i+1)+1);
				a=a-x[i]/2;
			}
			u=u+x[i];
		}
		t1=t1+b/c;
		printf("%lf\n",t1);
	
	}
	return 0;
} 
