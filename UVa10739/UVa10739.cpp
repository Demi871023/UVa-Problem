//UVa 10739 String to Palindrome（回文）

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