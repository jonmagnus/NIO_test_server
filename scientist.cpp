/* Wrong anwer
 * Point 70/100*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 1005

typedef long long ll;

int main()
{
	int N;
	ll val[MAX_N];
	while (scanf("%d ", &N) != EOF)
	{
		for (int i = 0; i < N; i++) scanf("%lld ", &val[i]);
		sort(val,val + N);
		ll res[] = {0,0,0};
		for (int j = N-1; j >= 0; j--)
		{
			int min_idx = 0;
			for (int i = 1; i < 3; i++)
				if (res[i] < res[min_idx])
					min_idx = i;
			res[min_idx] += val[j];
		}

		int min_idx = 0;
		for (int i = 1; i < 3; i++)
			if (res[i] < res[min_idx])
				min_idx = i;
		printf("%lld\n", res[min_idx]);
	}

	return 0;
}
