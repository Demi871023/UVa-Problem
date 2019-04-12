//UVa 1267 Network

/*
	想法：

		建圖之後，利用dfs記錄下每個node的父親以及依據dist在nodes[]紀錄下超過k的node是誰。

		接著依據nodes[]，從dist最遠的開始反推距離k的祖先是誰。
		<重點！從dist最遠反推距離k的祖先一定要佈下服務器>
		接著從佈下的服務器位置坐第二次dfs。
		在converted[]裡紀錄原本屬於超出k範圍的那些點經過剛剛佈下的服務器之後已經滿足條件。
		將該點的converted[]從原本false改為true。
		每一次dfs2遞增，最後即是答案。
*/


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 1005

vector <int> graph[MAX];
vector <int> nodes[MAX];
int n, s, k, fa[MAX];
bool covered[MAX];

void dfs1(int u, int f, int d)
{
	fa[u] = f;

	int nd = graph[u].size();

	if(nd == 1 && d > k)
	{
		nodes[d].push_back(u);
	}

	for(int i = 0 ; i < nd ; i++)
	{
		int v = graph[u][i];
		if(v != f)
		{
			dfs1(v, u, d+1);
		}
	}
}

void dfs2(int u, int f, int d)
{
	covered[u] = true;
	int nd = graph[u].size();

	for(int i = 0 ; i < nd ; i++)
	{
		 int v = graph[u][i];
		 if(v != f && d < k)
		 {
		 	dfs2(v, u, d+1);
		 }
	}
}

int solve()
{
	int ans = 0;
	memset(covered, 0, sizeof(covered));

	for(int d = n-1 ; d > k ; d--)
	{
		for(int i = 0 ; i < (int)nodes[d].size() ; i++)
		{
			int u = nodes[d][i];
			if(covered[u])
			{
				continue;
			}
			//
			int v = u;

			for(int j = 0 ; j < k ; j++)
			{
				v = fa[v];
			}
			//
			dfs2(v, -1, 0);
			ans++;
		}
	}

	return ans;
}


int main()
{
	freopen("1267.in", "r", stdin);
	freopen("1267.out", "w", stdout);
	int casenumber;
	scanf("%d", &casenumber);

	while(casenumber--)
	{
		scanf("%d%d%d", &n, &s, &k);

		for(int i = 1 ; i <= n ; i++)
		{
			graph[i].clear();
			nodes[i].clear();

		}

		for(int i = 0 ; i < n-1 ; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		dfs1(s, -1, 0);
		printf("%d\n", solve());

	}
}