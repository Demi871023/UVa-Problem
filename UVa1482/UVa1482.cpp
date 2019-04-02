//UVa 1482 Playing With Stones

#include <cstdio>
#include <cstdlib>

long long int SG(long long int temp)
{
	if(temp % 2 == 0)
	{
		return temp / 2;
	}
	else
	{
		return SG(temp / 2);
	}
}

int main()
{
	//freopen("1482.in", "r", stdin);
	//freopen("1482.out", "w", stdout);

	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N;
		scanf("%d", &N);

		long long int pile;
		long long int ans = 0;

		while(N--)
		{
			scanf("%lld", &pile);
			ans = ans ^SG(pile);
		}

		if(ans)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}