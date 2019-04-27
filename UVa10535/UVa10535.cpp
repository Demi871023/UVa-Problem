//UVa 10535 Shooter

/*
	想法：

	計算每個線段的端點極角，排列所有極角後，從最小角度開始掃描。
	邊紀錄＋1或-1值進入S[]。
	最後再掃描一遍S[]，取max值即為答案


*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-9;
const double pi = acos(-1.0); //利用反餘弦求出3.14159... 
const int N = 1005;

struct State
{
	double t;
	int k;
};

struct Point
{
	double x1,y1,x2,y2;
};

State s[N*2];
Point p[N];
int n, m;
double x, y;

bool cmp(const State &a, const State &b)
{
	if(fabs(a.t-b.t) > eps)
	{
		return a.t < b.t;
	}

	return a.k > b.k;
}


int solve()
{
	int ans = 0, c = 0;
	for(int i = 0 ; i < m ; i++)
	{
		c = c+ s[i].k;
		ans = max(ans, c);
	}
	return ans;
}

int main()
{

	freopen("10535.in", "r", stdin);
	freopen("test.out", "w", stdout);
	while(scanf("%d", &n) && n)
	{
		m = 0;

		for(int i = 0 ; i < n ; i++)
		{
			scanf("%lf%lf%lf%lf", &p[i].x1, &p[i].y1, &p[i].x2, &p[i].y2);
		}
		scanf("%lf%lf", &x, &y);

		for(int i = 0 ; i < n ; i++)
		{
			double I = atan2(p[i].y1 - y, p[i].x1 - x);
			double R = atan2(p[i].y2 - y, p[i].x2 - x);

			if(I > R)
			{
				swap(R,I);
			}
			if(R - I >= pi)
			{
				//如果一道牆橫跨以射擊基準為X軸的上下，就要將牆分成兩個，以下圖解。

				/*
					   牆面
					    |		（x軸上部）
					    |
					----------。--------（將射擊點。為中心的x軸）
					    |
					    |		（x軸下部）
				*/

				s[m].t = -pi;
				s[m++].k = 1;
				s[m].t = I;
				s[m++].k = -1;
				I = R;
				R = pi;
 			}

 			s[m].t = I;
 			s[m++].k = 1;
 			s[m].t = R;
 			s[m++].k = -1;
		}
		sort(s, s+m, cmp);

		printf("%d\n", solve());
	}
	return 0;
}
