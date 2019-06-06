//UVa 307 Sticks

/*

	想法：DFS or Recursive Programming

*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAX 100

int stick[MAX];
int used[MAX];
int num, len;
//len是現在每一段都要的目標長度

int dfs(int i, int l, int remain)
{
	//i為現在是第幾根棍子，
	//l是需要裁減的長度
	//總長剩下多少

	
	// l == 0有兩種情況：
	if(l == 0)
	{
		
		// 1. [全部組完]
		remain = remain - len;
		if(remain == 0) return true; //如果所有的棍子都不剩就結束

		// 2. [組完一組後繼續組]
		for( i = 0 ; used[i] ; i++); //找到現在剩下沒用過中最長的

		used[i] = 1; //使用它

		if(dfs(i+1, len-stick[i], remain)) return true; //切好其中一組後繼續切下一組
		
		//沒有return true就是失敗。used復原，remain加回原本的
		used[i] = 0;
		remain = remain + len;

	}
	else
	{
		for(int j = i ; j < num ; j++)
		{
			if(j > 0 && (stick[j] == stick[j-1] && !used[j-1]))
				continue;//前一格的長度跟我現在一樣，且前一個沒用到，那我也不可能用到	


			//選擇到的這個人沒用到且長度小於目標長度
			if(!used[j] && l >= stick[j])
			{
				l = l - stick[j];
				used[j] = 1;

				if(dfs(j, l , remain))	return true;


				//選取失敗，復原長度，used也復原
				l = l + stick[j];
				used[j] = 0;

				if(stick[j] == l) break;
			}


		}
	}

	return false;
}

bool cmp(const int a, const int b)
{
	return a > b;
	//由大排到小
}


int main()
{

	//freopen("307.in", "r", stdin);
	//freopen("temp.out", "w", stdout);
	while(scanf("%d", &num) && num)
	{
		int sum = 0;
		for(int i = 0 ; i < num ; i++)
		{
			scanf("%d", &stick[i]);
			sum = sum + stick[i];
			used[i] = 0;
		}

		sort(stick, stick+num, cmp);

		bool flage = false;

		for(len = stick[0] ; len <= sum / 2 ; len++)
		{
			if(sum % len == 0)
			{
				if(dfs(0, len, sum))
				{
					flage = true;
					printf("%d\n", len);
					break;
				}
			}
		}

		if(!flage)
		{
			printf("%d\n", sum);
		}

	}
}