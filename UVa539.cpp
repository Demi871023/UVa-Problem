#include <stdio.h>
#include <stdlib.h>

int n, m;
int bigest = 0;
int line[26][26];

void visit();
void dfs(int nodetemp, int len);


void visit()
{
	for(int node = 0 ; node < n ; node++)
	{
		int length = 0;
		dfs(node, length);
	}
}


void dfs(int nodetemp, int len)
{
	for(int i = 0 ; i < 26 ; i++)
	{
		if(line[nodetemp][i] == 1)
		{
			line[nodetemp][i] = line[i][nodetemp] = 0;
			dfs(i, len+1);
			line[nodetemp][i] = line[i][nodetemp] = 1;
		}
	}
	if(len > bigest)
	{
		bigest = len;
	}

}


int main()
{

	freopen("p3.in", "r", stdin);
	freopen("p3.out", "w", stdout);

	while(scanf("%d %d", &n, &m))
	{
		if(n ==0 && m ==0)
		{
			break;
		}

		for(int i = 0 ; i < 26 ; i++)
		{
			for(int j = 0 ; j < 26 ; j++)
			{
				line[i][j] = 0;
			}
		}

		for(int i = 0 ; i < m ; i++)
		{
			int temp1, temp2;
			scanf("%d %d", &temp1, &temp2);
			line[temp1][temp2] = line[temp2][temp1] = 1;
		}

		visit();
		printf("%d\n", bigest);
		bigest = 0;

	}

	return 0;
}