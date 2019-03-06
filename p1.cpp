#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{

	int N, S;
	while(~scanf("%d %d", &N, &S))
	{
		int narray[N];
		int prefix[N+1];

		prefix[0] = 0;

		for(int i = 0 ; i < N ; i++)
		{
			scanf("%d", &narray[i]);
		}

		for(int i = 1 ; i < N+1 ; i++)
		{
			prefix[i] = prefix[i-1] + narray[i-1];
		}

		int minimal;
		bool find = false;
		for(int i = 1 ; i <= N ; i++)
		{
			for(int j = 0 ; j <= N-i ; j++)
			{
				if(prefix[j+i]-prefix[j] >= S)
				{
					find = true;
					minimal = i;
					break;
				}
			}
			if(find)
			{
				break;
			}
		}

		if(find)
		{
			printf("%d\n", minimal);
		}
		if(!find)
		{
			printf("0\n");
		}

	}

	return 0;
}