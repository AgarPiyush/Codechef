#include<stdio.h>
#include<cmath> 
 
using namespace std;
typedef long long int LL;
 
int main()
{
    LL t;
    LL x;
    double d;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&x);
        d = sqrt(1+8*(x-1));
		printf("%.0lf\n",ceil((d-1)/2));
    }
    return 0;
}
