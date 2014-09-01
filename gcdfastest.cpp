#include <iostream>

using namespace std;

const int N=100000;
int a[10000000];

void f( int n )
  {
  for( a[n+1] = a[n] + a[n-1] ; a[n+1] <= N  ; a[n+1]+=a[n] )
     {
     cout<<a[n]<<","<<a[n+1]<<endl;

     f( n + 1 );
     }
  }

int main()
  {
  a[0] = a[1] = 1;

  f( 1 );

  return 0;
  }
