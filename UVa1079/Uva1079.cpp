//UVa 1079 A Careful Approach

/*
	想法：

	題目想找所有下降時間可能中，間距最長的。
	利用next_permutation來排列所有飛機下降的可能性組合。
	利用二分縮來找最大的Ｌ。
	若Ｌ加完現在的下降時間後超出範圍，即Ｌ太大，需要縮小。
	若Ｌ加完後還在範圍內，即Ｌ太小，需要擴大。
	慢慢地靠近最理想的最大長度，即為答案。
*/

#include <cstdio>
#include <math.h>
// fabs
#include <algorithm>
// nex_permutation
// max

using namespace std;

int airplane, a[8], b[8], order[8];

int check(double gap)
{
	double target = a[order[0]] + gap;
	for(int i = 1 ; i < airplane ; i++)
	{
		if(target > b[order[i]])
		{
			return 0;
		}
		if(a[order[i]] > target)
		{
			target = a[order[i]];
		}
		 target = target + gap;
	}
	return 1;
}

double solve()
{
	double begin = 0, end = 86400, L;
	while(fabs(begin - end) > 1e-2)
	{
		L = ( begin + end ) / 2.0; // fix L
		if(check(L))
		{
			begin = L;
		}
		else
		{
			end = L;
		}
	}
	return L;
}

int main()
{
	//freopen("1079.in", "r", stdin);
	//freopen("test2.out", "w", stdout);

	int cases = 1;
	while(scanf("%d", &airplane) == 1 && airplane)
	{
		for(int i = 0 ; i < airplane ; i++)
		{
			scanf("%d %d", &a[i], &b[i]);
			a[i] = a[i] * 60;
			b[i] = b[i] * 60;
			order[i] = i;
		}
		
		double maxL = 0;
		do
		{
			double temp = solve();
			maxL = max(maxL, temp);

		}while(next_permutation(order, order+airplane));

		maxL = (int)(maxL + 0.5);

		printf("Case %d: %d:%0.2d\n", cases++, (int)(maxL / 60), ((int)maxL%60));
	}
}
