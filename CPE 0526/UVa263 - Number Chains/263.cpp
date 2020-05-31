#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("263.in", "r", stdin);
	freopen("263.out", "w", stdout);


	int number;
	while(scanf("%d", &number))
	{

		if(number == 0)
			break;

		bool same = false;
		int chain = 0;

		printf("Original number was %d\n", number);
		vector <int> prob;

		while(!same)
		{
			chain = chain + 1;

			// 數字轉文字
			stringstream ss;
			string intstr;
			ss << number;
			ss >> intstr;


			string dec = intstr, aec = intstr;

			sort(aec.begin(), aec.end());
			sort(dec.begin(), dec.end(), greater<int>());
			int decnum, aecnum;
			stringstream decss;
			decss << dec;
			decss >> decnum;
			stringstream aecss;
			aecss << aec;
			aecss >> aecnum;

			int ans = decnum - aecnum;

			printf("%d - %d = %d\n", decnum, aecnum, ans);
			

			for(int i = 0 ; i < prob.size() ; i++)
				if(ans == prob[i])
					same = true;

			if(same)
				break;
			prob.push_back(ans);
			number = ans;
		}

		printf("Chain length %d\n\n", chain);
	}
}