#include <stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	if(n<4)
		printf("%.2lf\n", 95.0*n);
	else
		printf("%.2lf\n", 95.0*n*0.85);
	return 0;
}
