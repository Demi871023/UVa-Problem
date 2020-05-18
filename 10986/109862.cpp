#include <bits/stdc++.h>

using namespace std;
#define nMax 20005

struct qnode
{
	int x, cost;
	bool operator < (const qnode &rhs) const
	{
		return cost > rhs.cost;
	}
};

struct node
{
	int x, cost;
};

int N, n, m, S, T;
int cases = 1;

vector <node> edge[nMax];
bool vis[nMax];
int dist[nMax];

void Dijkstra(int start, int end)
{
	priority_queue<qnode> que;
	memset(vis, false, sizeof(vis));
	for(int i = 0 ; i < n ; i++)
		dist[i] = 1000000;

	dist[start] = 0;

	while(!que.empty())
		que.pop();

	que.push((qnode){start,0});
	qnode tmp;

	while(!que.empty())
	{
		tmp = que.top();
		que.pop();
		int u = tmp.x;
		if(vis[u])
			continue;
		vis[u] = true;
		for(int i = 0 ; i < edge[u].size() ; i++)
		{
			int x = edge[u][i].x;
			int cost = edge[u][i].cost;
			if(!vis[x] && dist[x] > dist[u] + cost)
			{
				dist[x] = dist[u] + cost;
				que.push((qnode){x, dist[x]});
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	while(N--)
	{
		
		scanf("%d%d%d%d", &n, &m, &S, &T);

		for(int i = 0 ; i <= n ; i++)
			edge[i].clear();

		while(m--)
		{
			int s1, s2, w;
			scanf("%d%d%d", &s1, &s2, &w);
			edge[s1].push_back((node){s2, w});
			edge[s2].push_back((node){s1, w});
		}
		Dijkstra(S, T);
		printf("Case #%d: ", cases++);
		if(dist[T] != 1000000)
			printf("%d\n", dist[T]);
		else
			printf("unreachable\n");
	}
}
