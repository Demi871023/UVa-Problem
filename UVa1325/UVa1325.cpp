//UVa 1325 Hypertransmission

#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAX 10005

struct Point
{
	int x, y, z, p;
};

Point point[MAX];

struct Edge
{
	int from, to, dist;
	bool operator < (const Edge& e)const
	{
		return dist < e.dist;
	}
};

vector<Edge> edges;
int different_count[MAX];

int main()
{
	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

	int N;
	while(~scanf("%d", &N))
	{
		for(int i = 0 ; i < N ; i++)
		{
			scanf("%d %d %d %d", &point[i].x, &point[i].y, &point[i].z, &point[i].p);
			different_count[i] = 1;
		}
		edges.clear();

		for(int i = 0 ; i < N ; i++)
		{
			for(int j = i+1 ; j < N ; j++)
			{
				int distance = (point[i].x - point[j].x)*(point[i].x - point[j].x) + (point[i].y - point[j].y)*(point[i].y - point[j].y) + (point[i].z - point[j].z) * (point[i].z - point[j].z);
				edges.push_back((Edge){i,j,distance});
			}
		}

		sort(edges.begin(), edges.end()); // sort for edge


		int biggest_starball_ans = 0, smallest_edge_ans = 0, starball_temp = 0;

		int a = 0;

		while(a < edges.size())
		{
			int b = a;

			while( b < edges.size() && edges[a].dist == edges[b].dist)
			{
				int edgefrom = edges[b].from;
				int edgeto = edges[b].to;
				if(point[edgefrom].p != point[edgeto].p)
				{
					different_count[edgefrom]--;
					different_count[edgeto]--;
					if(different_count[edgefrom] == -1)
					{
						starball_temp++;
					}
					if(different_count[edgeto] == -1)
					{
						starball_temp++;
					}
				}
				else
				{
					different_count[edgefrom]++;
					different_count[edgeto]++;
					if(different_count[edgefrom] == 0)
					{
						starball_temp--;
					}
					if(different_count[edgeto] == 0)
					{
						starball_temp--;
					}
				}
				b++;
			}

			if(biggest_starball_ans < starball_temp)
			{
				biggest_starball_ans = starball_temp;
				smallest_edge_ans = edges[a].dist;
			}

			a = b;
		}

		printf("%d\n%.4lf\n", biggest_starball_ans, sqrt(smallest_edge_ans));

	}

	return 0;
}