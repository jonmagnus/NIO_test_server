/* Score 100/100*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 1005
#define max(A,B) ((A)>(B) ? (A) : (B))
#define min(A,B) ((A)<(B) ? (A) : (B))

typedef long long ll;

int main()
{
	int N;
	ll val[MAX_N];

	while (scanf("%d ", &N) != EOF)
	{
		for (int i = 0; i < N; i++)
			scanf("%lld ", &val[i]);
		sort(val, val + N);
		reverse(val, val + N);

		ll sum = 0;
		for (int i = 3; i < N; i++) sum += val[i];
		
		ll diff;
		diff = min(sum, val[1] - val[2]);
		sum -= diff; val[2] += diff;
		diff = min(sum/2, val[0] - val[2]);
		sum -= 2*diff; val[2] += diff;
		diff = sum/3;
		sum -= 3*diff; val[2] += diff;

		printf("%lld\n", val[2]);
	}
		

	return 0;
}
