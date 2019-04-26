//UVa 10891 Game of Sum
/*
	想法：
	利用Dynamic Programming討論最佳狀況，帶入公式即解。
	d(i,j) = sum(i,j) - min(d(i+1,j), d(i+2,j)....,d(i,j-1), d(i,j-2)....,0)
	其中d(i,j)代表從i到j的子序列中拿者的sum。
	故要求出現在拿者能夠有最大sum的情況，及將序列總和減掉以對方來說是拿者時的最小解。
	而答案要求出相差最大的狀況數值，即d(i,j)-(sum(i,j) - d(i,j)) = 2d(i,j)-sum(i,j)
									↓		↓
	        (對Ａ來說最大的i到j區段的數值。)  (對B來說最小的i到j區段的數值。)
*/



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std; //std::min()

#define MAX 105

long long int S[MAX], A[MAX], d[MAX][MAX], visited[MAX][MAX], numnumber;
//A[]儲存輸入的數字串
//S[]為A[]的prefix sum
//d[i][j]從i到j的子序列中，「拿者」的sum
//visited[]記錄d[i][j]有沒有被討論過，有則1，無則0


long long int dp(long long int i, long long int j)
{
	if(visited[i][j])
	{
		return d[i][j];
	}

	visited[i][j] = 1;
	long long int m = 0;

	for(long long int k = i+1 ; k <= j ; k++)
	{
		m = min(m, dp(k, j));
	}
	for(long long int k = i ; k < j ; k++)
	{
		m = min(m, dp(i, k));
	}

	d[i][j] = S[j] - S[i-1] - m;
	return d[i][j];
}



int main()
{

	//freopen("10891.in", "r", stdin);
	//freopen("10891.out", "w", stdout);
	while(scanf("%lld", &numnumber) && numnumber)
	{
		S[0] = 0;

		for(int i = 1 ; i <= numnumber ; i++)
		{
			scanf("%lld", &A[i]);
			S[i] = S[i-1] + A[i];
		}

		memset(visited, 0, sizeof(visited));
		printf("%lld\n", 2*dp(1, numnumber) - S[numnumber]);

	}
	return 0;
}