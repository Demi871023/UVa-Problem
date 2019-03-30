// UVa 1203	Argus

#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

struct Item
{
	int tag;
	int period;
	int time;

	bool operator < (const Item &a)const
	{
		return (time > a.time || (time == a.time && tag > a.tag));
	}
};

int main()
{
	//freopen("1203.in", "r", stdin);
	//freopen("1203.out", "w", stdout);
	char s[100];
	priority_queue <Item> q;

	while(scanf("%s", s) && s[0] != '#')
	{
		Item i;
		scanf("%d %d", &i.tag, &i.period);
		i.time = i.period;
		q.push(i);

	}
	int casenumber;
	scanf("%d", &casenumber);

	while(casenumber--)
	{
		Item temp = q.top();
		q.pop();

		printf("%d\n", temp.tag);

		temp.time = temp.time + temp.period;
		q.push(temp);

	}

}