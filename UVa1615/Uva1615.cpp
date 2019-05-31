//UVa 1615 Highway

/*
	想法：

	概念上很像 UVa 10382 Watering Grass的覆蓋問題。
	利用畢氏定理，求出圓半徑和圓中心距離Ｌ線的所構成的第三條邊(即dis)
	在圓心Ｘ值往左的dis(-dis)和往右的dis(+dis)，即為高速公路必定存在的範圍。

	直接掃一遍，在不符合上述規則的情況時，count++。
	最後掃完之後的ans即為答案
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Villages
{
	double left;
	double right;

	bool operator < (const Villages &rhs)const
	{
		return right < rhs.right;
	}
};

vector <Villages> v;

int main()
{
	//freopen("1615.in", "r", stdin);
	//freopen("ttt.out", "w", stdout);
	int L, D, N;
	while(~scanf("%d%d%d", &L, &D, &N))
	{
		v.clear();
		for(int i = 0 ; i < N ; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);

			double dis = sqrt(D*D - y*y);
			double templeft = (double)x - dis;
			double tempright = (double)x + dis;

			v.push_back((Villages){templeft, tempright});
		}

		sort(v.begin(), v.end());

		double build = v[0].right;

		int ans = 1;
		for(int i = 1 ; i < N ; i++)
		{
			double leftmost = v[i].left;

			if(leftmost <= build)
			{
				continue;
			}
			else
			{
				ans++;
				build = v[i].right;
			}
		}

		printf("%d\n", ans);
	}
}