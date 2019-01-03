/* Score 100/100*/
#include <cstdio>
using namespace std;

#define MAX_N 1000

int N,K,p[MAX_N];

int main()
{
	while (scanf("%d %d ", &N,&K) != EOF)
	{
		for (int i = 0; i < N; i++) scanf("%d ", &p[i]);
		int last_p = p[0];
		for (int i = 1; i < N - 1; i++)
		{
			if (p[i-1] >= p[i] && p[i] < p[i+1] & p[i] < last_p) last_p = p[i];
			else if (p[i-1] <= p[i] && p[i] > p[i+1] & p[i] > last_p)
			{
				int c_count = K/last_p;
				K += c_count*(p[i] - last_p);
				last_p = p[i];
			}
		}
		if (p[N-1] >= p[N-2])
		{
			int c_count = K/last_p;
			K += c_count*(p[N-1] - last_p);
		}

		printf("%d\n", K);
	}

	return 0;
}
