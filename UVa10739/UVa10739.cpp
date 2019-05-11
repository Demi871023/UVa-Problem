//UVa 10739 String to Palindrome（回文）

/*
	想法：

	dp[i][j]記錄，當str[i+1]~str[j-1]符合回文條件，在考慮i和j相不相同時的最佳解
	i ============= j，分為兩種情形，i和j相同以及i和j不同時的各式解決辦法

	------------------------------------------------------------
	關係式：
	dp[i][j] = dp[i+1][j-1] , if(str[i] == str[j])
	dp[i][j] = min(dp[i+1][j-1], dp[i][j-1], dp[i+1][j]) + 1 , if(str[i] != str[j]
		      -------------  ----------  ----------
			  (1)           (2)         (3)
	(1)i直接換成j或j直接換成i 
	(2)在str[i]~str[j-1]成為回文後，將j刪除或直接在i前面加上一個j
	(3)將str[i+1]~str[j]成為回文後，將i刪除或直接在j後面加上一個i
	------------------------------------------------------------

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 1005

int main()
{
	freopen("10739.in", "r", stdin);
	freopen("10739.out", "w", stdout);
	int casenumber;
	char str[1005];

	scanf("%d", &casenumber);
	int count = 1;

	gets(str);
	while(casenumber--)
	{
		printf("Case %d: ", count++);

		gets(str);

		int len = strlen(str);

		int dp[len][len];
		memset(dp, 0, sizeof(dp));

		for(int j = 0 ; j < len ; j++)
		{
			for(int i = j-1 ; i >= 0 ; i--)
			{
				if(str[i] == str[j])
				{
					dp[i][j] = dp[i+1][j-1];
				}
				if(str[i] != str[j])
				{
					dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
					dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
					dp[i][j] = dp[i][j] + 1;
				}
			}
		}
		printf("%d\n", dp[0][len-1]);


	}

}
