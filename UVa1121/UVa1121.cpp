//UVa 1121 Subsequence

/*
	想法：

	利用prefix紀錄，透過固定長度(由小到大)去測試有沒有符合條件(>=S)
	一但發現符合條件，即答案值。
	若測試到最後都沒有找到即印出0
*/


#include <cstdio>
#include <cstdlib>

int main()
{
	//freopen("1121.in", "r", stdin);
	//freopen("1121.out", "w", stdout);
	int N, S;
	while(~scanf("%d %d", &N, &S))
	{
		int number[N];
		int prefix[N+1];

		prefix[0] = 0;

		for(int i = 0 ; i < N ; i++)
		{
			scanf("%d", &number[i]);
			prefix[i+1] = prefix[i] + number[i];
		}

		int len = 0;
		bool find = false;
		while(len <= N)
		{
			for(int j = 0 ; j+len <= N ; j++)
			{
				if(prefix[j+len] - prefix[j] >= S)
				{
					printf("%d\n", len);
					find = true;
					break;
				}
			}
			if(find)
			{
				break;
			}
			len++;
		}
		if(!find)
		{
			printf("0\n");
		}
	}	
}