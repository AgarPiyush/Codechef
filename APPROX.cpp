#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	double k=103993.0/33102;
	int l;
	char *s,*d;
	scanf("%d",&l);
	s=(char*)malloc(200);
	d=(char*)malloc(200);
	sprintf(s,"%lf",k);
	printf("%s\n",s);
	strncpy(d,s,l+2);
	printf("%s",d);
	return 0;
}
