//UVa 11384 Help is needed for Dexter

/*

	想法：

	每一次扣除序列數字的一半，推導出遞迴公式。
	solve(n) = solve(n/2) + 1
	直接實作此公式即可。

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

int solve(int a)
{
	if(a == 1)
	{
		return 1;
	}
	else
	{
		return solve(a/2)+1;
	}
}

int main()
{
	//freopen("11384.in", "r", stdin);
	//freopen("11384.out", "w", stdout);
	int num;
	while(~scanf("%d", &num))
	{
		printf("%d\n", solve(num));
	}
	return 0;
}