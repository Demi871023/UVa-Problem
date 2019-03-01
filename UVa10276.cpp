#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int T;
	scanf("%d", &T);

	for(int i = 0 ; i < T ; i++)
	{
		int N, column_count = 1, max, number = 2;
		scanf("%d", &N);
		int top_ball_array[N];
		top_ball_array[0] = 1;

		for(int j = 1 ; j < N ; j++)
		{
			top_ball_array[j] = 0;
		}

		if(N == 1)
		{
			printf("1\n");
		}

		else
		{
			while(column_count <= N)
			{
				int in_or_noin = 0;
				for(int arraycount = 0 ; in_or_noin != 1 && arraycount <= (column_count-1) ; arraycount++)
				{
					float temp = 0;
					temp = temp + sqrt(top_ball_array[arraycount] + number);
					if(temp == ((int)temp))
					{
						top_ball_array[arraycount] = number;
						max = number;
						in_or_noin = 1;
					}
					
				}
				if(in_or_noin != 1)
				{
					column_count++;

					if(column_count <= N)
					{
						top_ball_array[column_count-1] = number;
						max = number;
						in_or_noin = 1;
					}
				}
				number++;
			}

			printf("%d\n", max);
		}
		
		
	}
}