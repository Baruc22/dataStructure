#include <stdio.h>

int suma(int x[], int n)
{
	if (n == -1)
		return 0;
	return x[n] + suma(x, n - 1);
}
int main()
{
	int i, n, x[100];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	printf("%d", suma(x, n));
	return 0;
}
