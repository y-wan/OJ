#include <stdio.h>
int main()
{
	int a, b, c, max, min, mid;
	scanf("%d%d%d", &a, &b, &c);
	max = a>b?a:b;
	max = max>c?max:c;
	min = a<b?a:b;
	min = min<c?min:c;
	mid = a+b+c-max-min;
	if(min+mid<=max)
	{
		printf("not a triangle\n");
		return 0;
	}
	if(min*min+mid*mid == max*max)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}

/* 2017.07.24 Αν½β
#include <stdio.h>
int main() {
	int a, b, c, t;
	scanf("%d %d %d", &a, &b, &c);
	if (a + b <= c || a + c <= b || b + c <= a)
		printf("not a triangle\n");
	else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
*/
