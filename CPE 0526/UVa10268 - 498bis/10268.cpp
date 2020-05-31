#include <bits/stdc++.h>

using namespace std;

int main()
{
	// freopen("10268.in", "r", stdin);
	// freopen("10268.out", "w", stdout);
	long long int x;
	
	char space;
	long long int coef;
	vector <long long int> coefvec;

	while(scanf("%lld", &x)!=EOF)
	{
		int n = 0;
		long long int ans = 0;
		while(scanf("%lld%c", &coef, &space))
		{
			if(space != ' ')
				break;
			coefvec.push_back(coef);
		}

		long long int powx = 1;
		for (int i = coefvec.size()-1, j = 1; i>=0; i--, j++)
		{
		    ans = ans + coefvec[i] * j * powx;
		    powx = powx * x;
		}
		printf("%lld\n", ans);
		coefvec.clear();
	}
}
