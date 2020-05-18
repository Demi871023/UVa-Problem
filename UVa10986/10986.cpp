#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define nMax 20005

struct Edge{
    int to, cost;
    bool operator < (const Edge rhs) const
    {
        return cost > rhs.cost;
    }
};

int N, n, m, S, T;
int cases = 1;
vector <Edge> e[nMax];
bool vis[nMax];
int dis[nMax];

void Dijkstra(int start)
{
    priority_queue <Edge> que;
    memset(vis, false, sizeof(vis));
    for(int i = 0 ; i < nMax ; i++)
        dis[i] = 1000000;

    dis[start] = 0;

    while(!que.empty())
		que.pop();

    que.push((Edge){start, 0});
    while(!que.empty())
    {
        Edge tmp = que.top();
        que.pop();

        int u = tmp.to;
        if(vis[u])
            continue;
        vis[u] = true;

        for(int i = 0 ; i < e[u].size() ; i++)
        {
            int t = e[u][i].to;
            int c = e[u][i].cost;
            if(!vis[t] && dis[t] > dis[u] + c)
            {
                dis[t] = dis[u] + c;
                que.push((Edge){t, dis[t]});
            }
        }
    }
}

int main()
{
    freopen("10986.in", "r", stdin);
    freopen("10986.out", "w", stdout);
    scanf("%d", &N);
    while(N--)
    {
        scanf("%d%d%d%d", &n, &m, &S, &T);
        for(int i = 0 ; i < nMax ; i++)
            e[i].clear();
        while(m--)
        {
            int sou, des, cos;
            scanf("%d%d%d", &sou, &des, &cos);
            e[sou].push_back((Edge){des, cos});
            e[des].push_back((Edge){sou, cos});
        }
        Dijkstra(S);
        printf("Case #%d: ", cases++);
        if(dis[T] != 1000000)
            printf("%d\n", dis[T]);
        else
            printf("unreachable\n");
    }
}