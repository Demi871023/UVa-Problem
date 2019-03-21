//UVa 10672 Marbles on a tree

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

using namespace std;

#define MAX 10005

int parent[MAX];
int children[MAX];
int ball[MAX];


void construct(int node_total_number)
{
	memset(parent, 0, sizeof(parent));
	memset(children, 0, sizeof(children));
	memset(ball, 0, sizeof(ball));

	for(int i = 0 ; i < node_total_number ; i++)
	{
		int node, num, children_number;
		scanf("%d %d %d", &node, &num, &children_number);
		ball[node] = num;
		children[node] = children_number;
		for(int j = 0 ; j < children_number ; j++)
		{
			int temp;
			scanf("%d", &temp);
			parent[temp] = node;
		}
	}
}

int main()
{

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	int cases;
	while(scanf("%d", &cases) == 1 && cases)
	{
		construct(cases);
		int ans = 0;
		queue<int> q;

		for(int i = 1 ; i <= cases ; i++)
		{
			if(children[i] == 0)
			{
				q.push(i);
			}
		}
		
		while(!q.empty())
		{
			int	u = q.front();
			q.pop();

			if(parent[u] == 0)
			{
				break;
			}

			ans = ans + abs(ball[u] - 1);
			ball[parent[u]] = ball[parent[u]] + (ball[u] - 1);
			children[parent[u]]--;
			

			if(children[parent[u]] == 0)
			{
				q.push(parent[u]);
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}