//UVa 10017 The Never Ending Towers of Hanoi

/*
	想法：

	原本Hanoi的部分在加上判斷移動輸出的移動步數是否目標步數內。
	（包含一開始初始的時候所有disk在pegA也算在其中一步
	------------------------------------------------------------
	利用vector來記錄dsik的移動：

			vector[0] vector[1] vector[2] ...... vector[n-1]
	disk號碼   n         n-1        n-2               1
	------------------------------------------------------------
	當計算步數的數值等於目標步數，就跳回去，繼續下一個case
*/
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int ndisk, nstep, step;
char pegname[3] = {'A', 'B', 'C'};
vector <int> pegs[3];

void printStatus()
{
	for(int i = 0 ; i < 3 ; i++)
	{
		printf("%c=>", pegname[i]);
		if(!pegs[i].empty())
		{
			printf("  ");
			for(int j = 0 ; j < pegs[i].size() ; j++)
			{
				printf(" %d", pegs[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
}

void hanoi(int n, int from, int mid, int to)
{
	if(step == nstep)
	{
		return;
	}
	if(n == 1)
	{
		step++;
		pegs[to].push_back(pegs[from].back());
		pegs[from].pop_back();
		printStatus();
	}
	else
	{
		hanoi(n-1, from, to, mid);
		if(step == nstep)
		{
			return;
		}
		step++;
		pegs[to].push_back(pegs[from].back());
		pegs[from].pop_back();
		printStatus();
		hanoi(n-1, mid, from, to);
	}
}

int main()
{
	freopen("10017.in", "r", stdin);
	freopen("10017.out", "w", stdout);
	
	int casenumber = 1;
	while(scanf("%d%d", &ndisk, &nstep) && ndisk)
	{
		printf("Problem #%d\n\n", casenumber++);
		step = 0;

		for(int i = ndisk ; i ; i--)
		{
			pegs[0].push_back(i);
		}
		pegs[1].clear();
		pegs[2].clear();

		printStatus();
		hanoi(ndisk, 0, 1, 2);

		for(int i = 0 ; i < 3 ; i++)
		{
			pegs[i].clear();
		}
	}
	return 0;
}