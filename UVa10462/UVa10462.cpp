#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

#define eMAX 205
#define nMAX 105
#define INF 1000000000

int n, e, ise[eMAX];
int father[nMAX];

struct Edge
{
    int from, to, dist;
}edge[eMAX];

bool cmp(Edge a, Edge b)
{
    return a.dist < b.dist;
}

int find(int i)
{
    if(father[i] == i)  return i;
    return find(father[i]);
}

int Kruskal()
{
    int ans = 0, num = 0, id = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        father[i] = i;
    }
    for(int i = 0 ; i < e ; i++)
    {
        int n1 = edge[i].from;
        int n2 = edge[i].to;
        int n1f = find(n1);
        int n2f = find(n2);
        if(n1f != n2f)
        {
            ise[id] = i;
            id++;
            father[n1f] = n2f;
            ans = ans + edge[i].dist;
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(i == find(i))
        {
            num++;
        }
    }
    if(num > 1)
    {
        return INF;
    }
    else
    {
        return ans;
    }
}

int Kruskal_2(int ide)
{
    int ans = 0, num = 0;
    for(int i = 1 ; i <= n ; i++)
    {
        father[i] = i;
    }
    for(int i = 0 ; i < e ; i++)
    {
        if(i == ide)
        {
            continue;
        }
        int n1 = edge[i].from;
        int n2 = edge[i].to;
        int n1f = find(n1);
        int n2f = find(n2);
        if(n1f != n2f)
        {
            father[n1f] = n2f;
            ans = ans + edge[i].dist; 
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(i == find(i))
        {
            num++;
        }
    }
    if(num > 1)
    {
        return INF;
    }
    return ans;
}

int main()
{
    freopen("10462.in", "r", stdin);
    freopen("10462.out", "w", stdout);
    int casecount = 1;
    int casenumber;
    scanf("%d", &casenumber);
    while(casenumber--)
    {
        scanf("%d%d", &n, &e);
        for(int i = 0 ; i < e ; i++)
        {
            scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].dist);
        }
        
        sort(edge, edge+e , cmp);

        int ans1 = Kruskal();
        int ans2 = INF;

        printf("Case #%d : ", casecount++);

        if(ans1 == INF)
        {
            printf("No way\n");
            continue;
        }

        for(int i = 0 ; i < n-1 ; i++)
        {
            int temp = ise[i];
            ans2 = min(ans2, Kruskal_2(temp));
        }
        if(ans2 == INF)
        {
            printf("No second way\n");
        }
        else
        {
            printf("%d\n", ans2);
        }
    }
}