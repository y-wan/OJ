#include <stdio.h>
#include <math.h>
int main()
{
	int n;
	const double pi = acos(-1);
	scanf("%d", &n);
	printf("%f %f\n", sin(pi*n/180), cos(pi*n/180));
	return 0;
}
