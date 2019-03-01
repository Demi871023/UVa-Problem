#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	while(scanf("%d", &n))
	{
		if(n == 0)
		{
			break;
		}


		if( n == 1 )
		{
			printf("Discarded cards:\nRemaining card: 1\n");
		}

		else
		{
			int cardarray[n];

			// 初始化cardarray 1 ~ n
			for(int number = 1 ; number <= n ; number++)
			{
				cardarray[number-1] = number;
			}

			/*for(int number = 0 ; number < n ; number++)
			{
				printf("%d ", cardarray[number]);
			}*/

			printf("Discarded cards:1");
			//cardarray[0] = 0;

			//int number_circle = n-1;

			//number_throw_card為現在已經丟掉的卡牌數

			for(int number_throw_card = 1 ; number_throw_card < n-1 ; number_throw_card++)
			{
				int temp = cardarray[number_throw_card];
			
				for(int count = number_throw_card ; count < (n - 1) ; count++)
				{
				
					cardarray[count] = cardarray[count+1];
				}

				cardarray[n-1] = temp;
				printf(", %d", cardarray[number_throw_card]);

			}
			printf("\n");
			printf("Remaining card: %d\n", cardarray[n-1]);
		}
		
	}

	return 0;
}