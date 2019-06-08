//UVa 357 Let me count the way

//penny = 1c
//nickel = 5c
//dime = 10c
//quarter = 25c
//half-dollor - 50c

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int cent[5] = {1, 5, 10, 25, 50};


int main()
{
	freopen("357.in", "r", stdin);
	freopen("357.out", "w", stdout);

	int goal;
	while(~scanf("%d", &goal))
	{
		long long int dp[goal+1][5];
		memset(dp, 0, sizeof(dp));


		//

		for(int i = 0 ; i < 5 ; i++)
		{
			dp[0][i] = 1; //0塊的時候都是只有一種方法
		}

		for(int i = 0 ; i <= goal ; i++)
		{
			dp[i][0] = 1; //使用1cnet的時候所有金額都只有一種方法
		}

		//

		for(int i = 1 ; i < 5 ; i++)
		{
			for(int j = 1 ; j <= goal ; j++)
			{
				if(j < cent[i])
				{
					dp[j][i] = dp[j][i-1];
				}
				else
				{
					dp[j][i] = dp[j][i-1] + dp[j-cent[i]][i];
				}
			}
		}

		if(dp[goal][4] == 1)
		{
			printf("There is only %lld way to produce %d cents change.\n", dp[goal][4], goal);
		}
		else
		{
			printf("There are %lld ways to produce %d cents change.\n", dp[goal][4], goal);

		}


	}

}



/*	Example： input = 17

	1	5	10	25	50
--------------------------
 0	1	1	1	1	1
 1	1	1
 2	1	1
 3	1	1
 4	1	1
 5	1	2
 6	1	2
 7	1	2
 8	1	2
 9	1	2
10	1	3
11	1
12	1
13	1
14	1
15	1
16	1
17	1

*/


