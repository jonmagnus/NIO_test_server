/* Wrong answer
 * Score 10/100*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 200005
#define abs(A) ((A) < 0 ? -(A) : (A))

typedef long long ll;

int main()
{
	int N,T;
	while (scanf("%d %d ", &N,&T) != EOF)
	{
		ll p[MAX_N];
		for (int i = 0; i < N; i++)
			scanf("%lld ", &p[i]);
		sort(p, p + N);

		while (T--)
		{
			ll a;
			scanf("%lld ", &a);
			ll *lb = lower_bound(p, p + N, a);
			ll min_val;
			if (lb != p + N) min_val = *lb;
			else min_val = *(lb - 1);
			if (lb != p && a - *(lb - 1) < min_val - a)
				min_val = *(lb - 1);
			
			printf("%lld\n", abs(a - min_val));
		}
	}


	return 0;
}
