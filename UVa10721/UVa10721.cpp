//UVa 10721 Bar Code

/*
	想法：

	dp題目，直接用陣列推算出關係式並記錄答案即可。
	最右下角那格即為答案。
	------------------------------------------------------------
	關係式如下：

	dp[k][n] = 0 , if(k > n)
	dp[k][n] = 1 , if(k == n)
	dp[k][n] = dp[k-1][n-1] + dp[k-1][n-2]+....+dp[k-1][n-m]
	------------------------------------------------------------

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{

	freopen("10721.in", "r", stdin);
	freopen("10721.out", "w", stdout);
	long long int n, k, m;

	while(~scanf("%lld%lld%lld", &n, &k, &m))
	{
		k = k+1;
		n = n+1;
		long long int dp[k][n];
		memset(dp, 0, sizeof(dp));


		dp[0][0] = 1;

		for(long long int i = 1 ; i < k ; i++)
		{
			for(long long int j = 1 ; j < n ; j++)
			{
				if(i > j)
				{
					dp[i][j] = 0;
				}
				else if(j == i)
				{
					dp[i][j] = 1;
				}
				else if(j > i)
				{
					for(long long int k = 1 ; k <= m ; k++)
					{
						if(j - k < 0)
						{
							break;
						}
						dp[i][j] = dp[i][j] + dp[i-1][j-k];
					}
				}
			}
		}

		printf("%lld\n", dp[k-1][n-1]);

	}
}