//UVa 11538	Chess Queen

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
	//freopen("11538.in", "r", stdin);
	//freopen("11538.out", "w", stdout);
	long long int M, N;

	while(scanf("%lld %lld", &M, &N))
	{
		if(M == 0 && N == 0)
		{
			break;
		}

		if(N > M)
		{
			swap(N , M);
		}

		long long int ans = N * M * (N+M-2) + 2 * N * (N-1) * (3*M-N-1)/3;
		printf("%lld\n", ans);
		
	}
	return 0;
}