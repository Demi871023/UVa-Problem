//UVa 12083 Guardian of Decency

/*

	想法：

	這題運用概念為二分圖（Bipartite Graph）＋ Max Independent Set
	只要計算出不衝突的最大配對數，再由總人數扣除即答案。

*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 505

vector <int> couple[MAX];
int match[MAX];
int visited[MAX];

struct People
{
	int height;
	char gender[5];
	char music[105];
	char sport[105];
}p[MAX];


int abs(int x)
{
	if(x < 0) return -x;
	return x;
}


bool can_pair(int i, int j)
{
	//low probability become couple
	if(abs(p[i].height - p[j].height) > 40) return true;
	if(p[i].gender[0] == p[j].gender[0]) return true;
	if(strcmp(p[i].music, p[j].music)) return true;
	if(!strcmp(p[i].sport, p[j].sport)) return true;
	 
	/*	strcmp
		
		如果返回值 < 0，則表明str1 < str2
		如果返回值 > 0，則表明str1 > str2
		如果返回值 = 0，則表明str1 = str2
	*/
	return false;
}

bool KM(int x)
{
	for(int i = 0 ; i < (int)couple[x].size() ; i++)
	{
		int v = couple[x][i];
		if(visited[v]) continue;

		visited[v] = 1;
		if(match[v] == -1 || KM(match[v]))
		{
			//還沒被配到對，或是（想要配對的人）的（配對人）回推後還能找到其他人配的話
			match[v] = x;
			return true;
		}
	}
	return false;
}

int solve(int n)
{
	int max_match = 0;

	memset(match, -1, sizeof(match));

	for(int i = 0 ; i < n ; i++)
	{
		memset(visited, 0, sizeof(visited));
		if(KM(i)) max_match++;
	}
	return max_match;
}

int main()
{
	freopen("12083.in", "r", stdin);
	freopen("12083.out", "w", stdout);
	int casenumber;
	scanf("%d", &casenumber);
	while(casenumber--)
	{
		int num;
		scanf("%d", &num);

		for(int i = 0 ; i < num ; i++)
		{
			couple[i].clear();
			scanf("%d%s%s%s", &p[i].height, p[i].gender, p[i].music, p[i].sport);
		}

		for(int i = 0 ; i < num ; i++)
		{
			if(p[i].gender[0] == 'M')
			{
				continue;
			}
			for(int j = 0 ; j < num ; j++)
			{
				if(i == j)
				{
					continue;
				}
				if(!can_pair(i, j))
				{
					couple[i].push_back(j);
				}

			}
		}
		int max_match = solve(num);
		printf("%d\n", num - max_match);
	}
	return 0;
}