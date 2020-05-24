#include <cstdio>
#include <cstdlib>
#include <cstring>
 
#define N 22
int n, k;
unsigned long long dp[N][N];

void DP()
{
	memset(dp, 0, sizeof(dp));

	// 任意字串長度, 交換 0 次的狀況皆為 1
	for(int i = 1 ; i < N ; i++)
		dp[i][0] = 1;

	// i 為 n 長度, j 為交換 k 次, dp[i][j] 紀錄在長度為 n, 交換 k 次的有幾種
	for(int i = 1 ; i < N ; i++)
		for(int j = 1 ; j < N ; j++)
			// 若每多增長 1 , 可分為加在前一次討論的最後（dp[i-1][j]）和參與前一次討論的 i-1 個位置的可能性
			dp[i][j] = dp[i-1][j-1] * (i - 1) + dp[i-1][j];
}
 
int main() {

	freopen("11077.in", "r", stdin);
	freopen("11077.out", "w", stdout);
	DP();

	while(scanf("%d%d", &n, &k))
	{
		if(n == 0 && k == 0)
			break;
		printf("%llu\n", dp[n][k]);
	}
}