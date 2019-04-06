//UVa 11538 Chess Queen

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{

	//freopen("11538.in", "r", stdin);
	//freopen("11538.out", "w", stdout);
	
	long long int N, M;

	while(scanf("%lld %lld", &N, &M) == 2 && N && M)
	{
		if(N > M)
		{
			swap(N,M);
		}
		printf("%lld\n", N*M*(N+M-2)+2*N*(N-1)*(3*M-N-1)/3);
	}
	return 0;
}