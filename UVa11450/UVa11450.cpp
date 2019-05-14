//UVa 11450 Wedding shopping

/*
	想法：

		利用dp，來記錄每個價錢的可能性。
		特蝶的是，從原有有的前往前推，如果減掉測試價格>=0的畫集可以購買此物
		依此類推，直到最後一行的dp即為可能性所有結果。
		從dp[0][C_MAX]~dp[M_MAX][C_MAX]找尋剩下的錢min（一旦找到dp[][]==1即可）
		M - 剩下的錢min即為答案

*/	

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 25

vector <int> model[MAX];

int main()
{
	freopen("11450.in", "r", stdin);
	freopen("11450.out", "w", stdout);
	int casenumber;
	scanf("%d", &casenumber);
	while(casenumber--)
	{
		int M, C;
		scanf("%d %d", &M, &C);

		for(int i = 0 ; i < C ; i++)
		{
			int K;
			scanf("%d", &K);
			int temp;

			for(int j = 0 ; j < K ; j++)
			{
				scanf("%d", &temp);
				model[i].push_back(temp);
			}
		}

		int dp[M+1][C];
		memset(dp, 0, sizeof(dp));

		for(int i = 0 ; i < (int)model[0].size() ; i++)
		{
			int price = model[0][i];
			dp[M-price][0] = 1;
		}

		for(int i = 0 ; i < C ; i++)
		{
			for(int j = 0 ; j <= M ; j++)
			{
				if(dp[j][i] == 1)
				{
					for(int k = 0 ; k < (int)model[i+1].size() ; k++)
					{
						int price = model[i+1][k];
						if(j - price >= 0)
						{
							dp[j-price][i+1] = 1;
						}
					}
				}
				
			}
		}

		int ans;
		bool find = false;
		for(int i = 0 ; i <= M ; i++)
		{
			if(dp[i][C-1] == 1)
			{
				ans = M-i;
				find = true;
				break;
			}
		}

		if(find)
		{
			printf("%d\n", ans);
		}
		else
		{
			printf("no solution\n");
		}

		for(int i = 0 ; i < C ; i++)
		{
			model[i].clear();
		}
	}
}


