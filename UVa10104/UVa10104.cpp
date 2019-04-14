//UVa 10104 Euclid Problem

/* 
	想法：

	利用輾轉相除法遞迴。

*/

#include <cstdio>
#include <cstdlib>

int gcd(int a, int b, int &x, int &y) 
{
	if(a%b == 0)
	{
		x = 0, y = 1;
		return b;
	}
	else
	{
		int r, tempx, tempy;
		r = gcd(b, a%b, tempx, tempy);
		x = tempy;
		y = tempx - a/b*tempy;
		return r;
	}
}

int main()
{
	freopen("10104.in", "r", stdin);
	freopen("10104.out", "w", stdout);
	int a, b, x, y;
	while(~scanf("%d %d", &a, &b))
	{
		int r = gcd(a, b, x, y);
		printf("%d %d %d\n", x, y, r);
	}
}