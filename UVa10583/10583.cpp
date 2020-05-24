#include <cstdio>
#include <cstdlib>
#include <cstring>

#define nMax 50005
int n, m;
int p[nMax];

int FindRoot(int x)
{
    if(x == p[x])
        return x;
    return p[x] = FindRoot(p[x]);
}

bool UnionSet(int x, int y)
{
    int rootX = FindRoot(x);
    int rootY = FindRoot(y);
    
    if(rootX== rootY)
        return false;
    
    p[rootX] = p[rootY];
    return true;
}

int main()
{
    freopen("10583.in", "r", stdin);
    freopen("10583.out", "w", stdout);

    int cases = 1;
    while(scanf("%d%d", &n, &m))
    {
        if(n == 0 && m == 0)
            break;

        int ans = n;

        memset(p, 0, sizeof(p));
        for(int i = 1 ; i <= n ; i++)
            p[i] = i;

        while(m--)
        {
            int i, j;
            scanf("%d%d", &i, &j);
            if(UnionSet(i, j))
                ans--;
        }
        printf("Case %d: %d\n", cases++, ans);
    }
}