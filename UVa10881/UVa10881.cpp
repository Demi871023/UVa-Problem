//UVa 10881 Piotr's Ants

/*

    重點概念：兩隻螞蟻碰撞後往回走的路徑，與對方時間內往同一方向走的最終位置。且每隻螞蟻最後的順序不變。
    ---------------------------------------------------------------------------------
                a。->    <-。b           c。->                   <-。d. （走前）

                  a。<- ->。b                   c。->     <-。d         （走完）

        路徑關係為：（某定時t下）
        a的最終位置是a + b*t*方向(1 or -1)
        b的最終位置是b + a*b*方向(1 or -1)
    ---------------------------------------------------------------------------------
*/


#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 10000 + 5;

struct Ant
{
	int id;      
 	int positon;
  	int direction;
  	bool operator < (const Ant& a) const 
  	{
    	return positon < a.positon;
  	}
};

Ant before[maxn], after[maxn];

const char dirName[][10] = {"L", "Turning", "R"};

int order[maxn];// 輸入的第i隻螞蟻是終態中從左算起第order[i]隻螞蟻

int main()
{
	//freopen("10881.in", "r", stdin);
	//freopen("10881.out", "w", stdout);
  	int casenumber;
  	scanf("%d", &casenumber);

  	int casecount = 1;

  	while(casenumber--)
  	{
       int L, T, n;
       printf("Case #%d:\n", casecount++);
       scanf("%d%d%d", &L, &T, &n);

       for(int i = 0 ; i < n; i++)
       {
            int at, d;
            char dir;
            scanf("%d %c", &at, &dir);
            if(dir == 'R')
            {
            	d = 1;
            }
            else
            {
            	d = -1;
            }
            before[i] = (Ant){i, at, d};
           	after[i] = (Ant){0, at+T*d, d};   //這裡的i,d是未知的
       }

    // 計算order陣列
    sort(before, before+n);

    for(int i = 0; i < n; i++)
    {
    	order[before[i].id] = i;
    }

    sort(after, after+n);    
    for(int i = 0; i < n-1; i++)
    {
    	// 修改碰撞中螞蟻的方向
    	if(after[i].positon == after[i+1].positon)
    	{
    		after[i].direction = after[i+1].direction = 0;
    	}
    } 

    for(int i = 0; i < n; i++)
    {
         int a = order[i]; 
         if(after[a].positon < 0 || after[a].positon > L)  
         {
         	printf("Fell off\n");
         }
         else
         {
         	printf("%d %s\n", after[a].positon, dirName[after[a].direction+1]);
         }
    }
    printf("\n");
  }
  return 0;
} 
