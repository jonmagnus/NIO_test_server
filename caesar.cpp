/* Score 100/100*/
#include <cstdio>
using namespace std;

#define MAX_M 100005

int main()
{
	int n,m;
	char inp[MAX_M];
	while (scanf("%d ", &n) != EOF)
	{
		scanf("%s%n ", inp,&m);
		for (int i = 0; i < m; i++)
		{
			int offset = inp[i] - 'A';
			offset = (offset + n) % ('Z' - 'A' + 1);
			inp[i] = offset + 'A';
		}
		printf("%s\n", inp);
	}
	return 0;
}
