/* Score 100/100*/
#include <cstdio>
using namespace std;

int N;

int main()
{
	while (scanf("%d ", &N) != EOF) while (N--)
	{
		long long t;
		scanf("%lld ", &t);
		printf("%s\n", t & 1 ? "GALT" : "RIKTIG");
	}
	
	return 0;
}
