//UVa 1382 Distant Galaxy
#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 110

struct Point
{
    int x, y;
    bool operator < (const Point& rhs) const
    {
        return x < rhs.x;   
    }                               
};

Point P[maxn];
int N, y_number, y[maxn], on[maxn], on_aty[maxn], left[maxn];

int solve()
{
    sort(P, P+N); //sort X
    sort(y, y+N); //sort Y
    y_number = unique(y, y+N) - y;
    
    if(y_number <= 2)
    {
        return N;
    }

    int ans = 0;
    for(int i = 0 ; i < y_number ; i++)
    
        for(int j = i+1 ; j < y_number ; j++)
        {
            int y_min_temp = y[i];
            int y_max_temp = y[j];

            int x_number = 0;

            for(int z = 0 ; z < N ; z++)
            {
                if(z == 0 || P[z].x != P[z-1].x)
                {
                    x_number++;
                    on[x_number] = 0;
                    on_aty[x_number] = 0;
                    if(x_number == 0)
                    {
                        left[x_number] = 0;
                    }
                    else
                    {
                        left[x_number] = left[(x_number - 1)] + on_aty[(x_number - 1)] - on[(x_number - 1)];
                    }
                }
                if(P[z].y > y_min_temp && P[z].y < y_max_temp)
                {
                    on[x_number]++;
                }
                if(P[z].y >= y_min_temp && P[z].y <= y_max_temp)
                {
                    on_aty[x_number]++;
                }
            }

            if(x_number <= 2)
            {
                return N;
            }
            int temp = 0;
            for(int k = 1 ; k <= x_number ; k++)
            {
                ans = max(ans, left[k]+on_aty[k]+temp);
                temp = max(temp, on[k]-left[k]);
            }
        }
        return ans;
}

int main()
{
    //freopen("1382.in", "r", stdin);
    //freopen("1382.out", "w", stdout);

    int cases = 1;

    while(scanf("%d", &N) == 1 && N)
    {
        for(int i = 0 ; i < N ; i++)
        {
            scanf("%d %d", &P[i].x, &P[i].y);
            y[i] = P[i].y;
        }
        printf("Case %d: %d\n", cases, solve());
        cases++;
    }
    return 0;
}