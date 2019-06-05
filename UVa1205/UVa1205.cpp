//UVa 1205 Color a Tree

/*

	想法：Greedy + Tree

	基本cost為所有node的cost相加。即先做v[1]+v[2]+v[3]...+v[n]
	接著將所有node丟入priority queue裡，每次挑W最大的拿出來merge。
	每merge一次，cost和每個node代表幾個人的t做改變。總cost也要跟著做變化。
	最後所有node merge完後剩下root就結束，此時cost即答案。

	<補充>
	pair的比較operator已經被定義過！先比較first，無結果則再比較second。

*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
//#include <utility>

using namespace std;

#define MAX 1005

struct Node
{
	int t;
	double w;
};

int n, root;
int father[MAX], v[MAX];
bool visited[MAX];
Node node[MAX];

int main()
{
	freopen("1205.in", "r", stdin);
	freopen("temp.out", "w", stdout);
	while(scanf("%d%d", &n, &root) && n && root)
	{
		priority_queue < pair<double,int> > q;

		memset(visited, 0, sizeof(visited));
		memset(father, 0, sizeof(father));

		int ans = 0;

		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%d", &v[i]);
			node[i].w = v[i] * 1.0;
			node[i].t = 1;
			ans = ans + v[i];
			if(i == root) continue;
			q.push(make_pair(node[i].w, i)); //push進去已經邊依照W大小排序（大<-->小）
		}

		int a, b;
		for(int i = 1 ; i < n ; i++)
		{
			scanf("%d%d", &a, &b);
			father[b] = a;
		}

		for(int i = 1 ; i < n ; i++)
		{
			int x = q.top().second;
			q.pop();

			while(visited[x] || x == root)
			{
				x = q.top().second;
				q.pop();
			}
			visited[x] = 1;
			ans = ans + v[x]*node[father[x]].t;
			for(int j = 1 ; j <= n ; j++)
			{
				//假定要merge的node有child時。child的parent要改成祖父
				if(father[j] == x)
				{
					father[j] = father[x];
				}
			}
			node[father[x]].t = node[father[x]].t + node[x].t;
			v[father[x]] = v[father[x]] + v[x];
			node[father[x]].w = 1.0 * v[father[x]] / node[father[x]].t;
			q.push(make_pair(node[father[x]].w, father[x]));

		}
		printf("%d\n", ans);
	}
}