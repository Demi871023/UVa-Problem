#include <bits/stdc++.h>

#define mMax 100005


int main()
{

	// freopen("12918.in", "r", stdin);
	// freopen("12918.out", "w", stdout);
	unsigned long long T, n, m;

	unsigned long long prefixsum[mMax];
	memset(prefixsum, 0, sizeof(prefixsum));
	prefixsum[0] = 0;

	for(int i = 1 ; i < mMax ; i++)
	{
		prefixsum[i] = prefixsum[i-1] + i;
	}

	scanf("%llu", &T);
	while(T--)
	{
		scanf("%llu%llu", &n, &m);
		if(m == n)
			printf("%llu\n", prefixsum[m-1] - prefixsum[0]);
		else
			printf("%llu\n", prefixsum[m-1] - prefixsum[m-n-1]);
	}

}