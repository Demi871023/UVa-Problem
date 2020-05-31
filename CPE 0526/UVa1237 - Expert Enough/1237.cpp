#include <bits/stdc++.h>

using namespace std;


struct ACM
{
	string M;
	int L, H;
};

int main()
{
	// freopen("1237.in", "r", stdin);
	// freopen("1237.out", "w", stdout);
	int T, D, Q, P;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &D);
		vector <ACM> a;
		while(D--)
		{
			string m;
			int l, h;
			cin >> m >> l >> h;
			a.push_back((ACM){m, l, h});
		}
		scanf("%d", &Q);
		
		while(Q--)
		{
			scanf("%d", &P);
			int select = 0, count = 0;
			for(int i = 0 ; i < a.size() ; i++)
			{
				if(P >= a[i].L && P <= a[i].H)
				{
					select = i;
					count++;
				}
			}
			if(count == 0 || count > 1)
			{
				printf("UNDETERMINED\n");
				continue;
			}
			cout << a[select].M << endl;

		}
		if(T != 0)
			printf("\n");
	}
}