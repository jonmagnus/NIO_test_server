/* Wrong answer
 * Score 10/100*/
#include <cstdio>
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

		while (T--)
		{
			ll a;
			scanf("%lld ", &a);
			
			ll min_val = p[0];
			for (int i = 1; i < N; i++)
				if (abs(a - p[i]) < abs(a - min_val))
					min_val = p[i];

			printf("%lld\n", abs(a - min_val));
		}
	}

	return 0;
}
