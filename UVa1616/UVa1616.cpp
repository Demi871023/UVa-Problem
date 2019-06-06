//UVa 1616 Caravan Robbers

/*

	想法：二分收必出最佳L解 + 利用窮舉小數換成分數

*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>

using namespace std;


int n;

const int maxn = 100100;
const int INF = 1000010;
const double eps = 1e-9; //誤差值

struct gang
{
	double left;
	double right;
}g[maxn];

bool cmp(gang a, gang b)
{
	return a.left < b.left;
}

bool judge(double l)
{
	int f = 1; //回傳值 f=1為true f=0為false

	double s = 0; //可以安排搶劫的起始位置

	for(int i = 0 ; i < n && f; i++)
	{
		//強劫由左掃到右
		if(s < g[i].left)
		{
			//如果s在第i個強盜搜索範圍左側的左邊
			if(g[i].left + l <= g[i].right)
			{
				//還在i強盜的範圍內的話
				s = g[i].left + l;
				continue;
			}
			else
			{
				f = 0; //此長度l不可行
			}
		}
		else
		{
			//如果s在第i個強盜搜索範圍左側的右邊
			if(s + l <= g[i].right)
			{
				s = s + l;
				continue;
			}
			else
			{
				f = 0;
			}
		}
	}
	return f;

}

int main()
{
	//freopen("1616.in", "r", stdin);
	//freopen("temp.out", "w", stdout);
	while(~scanf("%d", &n))
	{
		for(int i = 0 ; i < n ; i++)
		{
			scanf("%lf%lf", &g[i].left, &g[i].right);
		}

		sort(g, g+n , cmp);

		double L = 0 ;
		double R = INF;

		while((R - L) > eps)
		{
			double mid = (L + R) / 2;

			if(judge(mid))
			{
				L = mid;
			}
			else
			{
				R = mid;
			}
		}

		//做完後L的數值就是答案，接著要把它轉成分數形式輸出

		double ans = L; //將ans轉乘分數型態表示（p/q）

		int rp = 0, rq = 1; //rp和rq分別是p和q的最終答案

		for(int p, q = 1 ; q <= n ; q++)
		{
			p = round(ans * q);

			if(fabs((double)p/q - ans) < fabs((double)rp/rq - ans))
			{
				rp = p;
				rq = q;
			}
		}
		printf("%d/%d\n", rp, rq);
	}
}