//UVa 442 Matrix Chain Multiplication

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;

struct Matrix
{
	char name;
	int row;
	int cloumn;
};

int main()
{

	//freopen("442.in", "r", stdin);
	//freopen("442.out", "w", stdout);
	int matrix_number;
	vector <Matrix> matrix;

	scanf("%d\n", &matrix_number);

	for(int i = 0 ; i < matrix_number ; i++)
	{
		char nam; 
		int ro, col;
		scanf("%c %d %d\n", &nam, &ro, &col);
		matrix.push_back((Matrix){nam, ro, col});
	}

	char str[1000];

	while(~scanf("%s", str))
	{
		stack <char> s;
		int len = (int)strlen(str);
		int ans = 0;
		char n = 'a';
		bool accepted = true;

		if(len == 1)
		{
			printf("0\n");
			continue;
		}
		else
		{
			for(int i = 0 ; i < len ; i++)
			{

				if(str[i] == ')')
				{
					char char2 = s.top();
					s.pop();
					char char1 = s.top();
					s.pop();

					s.pop();

					Matrix one, two; 

					for(int i = 0 ; i < (int)matrix.size() ; i++)
					{
						if(matrix[i].name == char1)
						{
							one = matrix[i];
						}

						if(matrix[i].name == char2)
						{
							two = matrix[i];
						}
					}

					if(one.cloumn != two.row)
					{
						accepted = false;
					}

					ans = ans + one.row * one.cloumn * two.cloumn;

					
					matrix.push_back((Matrix){n, one.row, two.cloumn});
					s.push(n);
					n++;
					

				}
				else
				{
					s.push(str[i]);
				}
			}
		}
		
		if(accepted)
		{
			printf("%d\n", ans);
		}
		else
		{
			printf("error\n");
		}
		
	}
}