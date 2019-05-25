//UVa 10003 Cutting Sticks

/*

	想法：
	類似於矩陣相乘，找斷點分成兩part各自選最優解一路往上。
	
	題目要切n段，把兩端點也一起計入 -> dp[n+2][n+2]

	關係式：
	dp[i][j]代表從cut[i] ~ cut[j]斷點間能夠切割的最優解
	dp[i][j] = min(dp[i][1]+dp[i+1)][j], dp[i][2]+dp[i+2][j], ...., dp[][]+dp[][]) + cut[j] - cut[i]
				   --------------------  -------------------        -------------

			   [0]  [1]  [2]  [3]  [4]

	          | 0 | 25 | 50 | 75 | 100  
	    -------------------------------------
	[0]     0 | 0 | 0  | 50 | 125| 200
	    -------------------------------------
	[1]    25 |   | 0  | 0  | 75 | 125
	    -------------------------------------
	[2]    50 |   |    | 0  | 0  | 50
	    -------------------------------------
	[3]    75 |   |    |    | 0  |  0
	    -------------------------------------
	[4]   100 |   |    |    |    |  0

*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

vector <int> cut;

int main()
{
	//freopen("10003.in", "r", stdin);
	//freopen("10003.out", "w", stdout);
	int length;
	while(scanf("%d", &length) && length)
	{
		cut.clear();
		int cutnum;
		scanf("%d", &cutnum);
		
		cut.push_back(0);
		for(int i = 0 ; i < cutnum ; i++)
		{
			int temp;
			scanf("%d", &temp);
			cut.push_back(temp);
		}
		cut.push_back(length);

		int num = (int)cut.size();

		int dp[num][num];
		memset(dp, 0, sizeof(dp));

		for(int n = 2 ; n < num ; n++)
		{
			for(int r = 0 ; r < num-1 ; r++)
			{
				int e = n + r;
				if(e > num-1)
				{
					break;
				}
				dp[r][e] = 1000000000;
				for(int c = r+1 ; c < e ; c++)
				{
					int temp = dp[r][c] + dp[c][e] + cut[e] - cut[r];
					if(temp < dp[r][e])
					{
						dp[r][e] = temp;
					}
				}
			}
		}

		printf("The minimum cutting is %d.\n", dp[0][num-1]);
	}
}