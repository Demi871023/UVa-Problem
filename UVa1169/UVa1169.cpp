//UVa 1169 Robotruck

/*

	想法：

	利用一維陣列儲存dp結果。
	d[i]代表將前i個package收完之後的最小解。
	d[i] = d[j] + d20[j+1] - total_dist[j+1] + total_dist[i] + d20[i]

*/

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <deque>

using namespace std;

#define MAX 100005

int x[MAX], y[MAX];
int d[MAX]; //將前index收完的最短移動距離
int d20[MAX]; //起點到index的距離
int total_dist[MAX]; //從第一個一路收到index的距離 prefix
int total_weight[MAX]; //從第一個package到indwx的總重量 prefix
int capacity, packagenum;

int f(int j)
{
	return d[j] + d20[j+1] - total_dist[j+1];
}


int main()
{
	//freopen("1169.in", "r", stdin);
	//freopen("tt.out", "w", stdout);
	int casenumber;
	scanf("%d", &casenumber);
	while(casenumber--)
	{
		int w;
		scanf("%d%d", &capacity, &packagenum);

		d20[0] = total_dist[0] = total_weight[0] = x[0] = y[0] = 0;

		for(int i = 1 ; i <= packagenum ; i++)
		{
			scanf("%d%d%d", &x[i], &y[i], &w);
			d20[i] = abs(x[i]) + abs(y[i]);
			total_dist[i] = total_dist[i-1] + abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
			total_weight[i] = total_weight[i-1] + w;  
		}

		deque <int> Q;
		Q.push_back(0);

		for(int i = 1 ; i <= packagenum ; i++)
		{
			while(!Q.empty() && (total_weight[i] - total_weight[Q.front()]) > capacity)
			{
				//若從j+1一路收到i的總重量大於最大容量capacity，就不符合標準
				Q.pop_front();
			}

			d[i] = f(Q.front()) + total_dist[i] + d20[i];

			while(!Q.empty() && (f(Q.back()) >= f(i)))
			{
				//f(i)的解比f(j+1)還小，此j+1狀況也不考慮
				Q.pop_back();
			}

			Q.push_back(i);
		}

		printf("%d\n", d[packagenum]);
		if(casenumber)
		{
			printf("\n");
		}


	}
}

