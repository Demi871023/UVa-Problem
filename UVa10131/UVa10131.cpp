//UVa 10131 Is Bgger Smater?

/*
	想法：

	先將每一個Elephant依照重量由大到小排序。
	若重量相同，則由IQ由大到小排序。
	接著只要針對IQ做Longest Increasing Subsequence的DP解法找除最長遞增子序列。
	並紀律下來每一個狀態是從誰來->（path[]）
	即可找除答案

	！注意：輸出的大象代碼是原先輸入的順序，故struct裡面要有一個number欄位紀錄

*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

struct Elephant
{
	int number;
	int weight;
	int IQ;

	bool operator < (const Elephant &a)const
	{
		return ((weight > a.weight) || (weight == a.weight && IQ > a.IQ));
	}
};

vector <Elephant> e;

int main()
{
	freopen("10131.in", "r", stdin);
	freopen("10131.out", "w", stdout);
	int w, i;
	int count = 1;
	while(~scanf("%d%d", &w, &i))
	{
		e.push_back((Elephant){count++, w, i});
	}

	sort(e.begin(), e.end());

	int lis[count];
	int path[count];

	for(int i = 0 ; i < count ; i++)
	{
		lis[i] = 1;
	}

	int temp;

	for(int i = 0 ; i < e.size() ; i++)
	{
		for(int j = 0 ; j < i ; j++)
		{
			if(e[j].IQ < e[i].IQ && e[j].weight != e[i].weight)
			{
				if(lis[i] <= lis[j]+1)
				{
					lis[i] = lis[j]+1;
					temp = j;
				}
			}
		}
		path[i] = temp;
	}

	int max = 0;
	int endpoint;
	for(int i = 0 ; i < e.size() ; i++)
	{
		if(max < lis[i])
		{
			max = lis[i];
			endpoint = i;
		}
	}

	printf("%d\n%d\n", max, e[endpoint].number);

	for(int i = 0 ; i < max-1 ; i++)
	{
		endpoint = path[endpoint];
		printf("%d\n", e[endpoint].number);
	}

}