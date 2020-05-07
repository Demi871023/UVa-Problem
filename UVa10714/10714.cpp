// UVa10714
/* 
    earlist：找距離最近端點最大值者
    latest：找距離最遠端點最大值者
*/


#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    freopen("10714.in", "r", stdin);
    freopen("10714.out", "w", stdout);

    vector <int> position;
    int cases;
    scanf("%d", &cases);
    

    for(int i = 0 ; i < cases ; i++)
    {
        int length, n;
        scanf("%d%d", &length, &n);
        for(int j = 0 ; j < n ; j++)
        {
            int pos;
            scanf("%d", &pos);
            position.push_back(pos);
        }
        
        int earliest = 0, latest = 0;
        for(int j = 0 ; j < position.size() ; j++)
        {
            int FindClose, FindFar;

            // 螞蟻在右半邊
            if(position[j] < (length / 2))
            {
                FindClose = position[j];
                FindFar = length - position[j];
            }
            // 螞蟻在左邊
            else
            {
                FindClose = length - position[j];
                FindFar = position[j];
            }
            
            if(FindClose > earliest)
                earliest = FindClose;
            if(FindFar > latest)
                latest = FindFar;
        }
        printf("%d %d\n", earliest, latest);
        position.clear();
    }
}