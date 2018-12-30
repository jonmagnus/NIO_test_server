/* Score 100/100*/
#include <cstdio>
using namespace std;

#define MOD 1000000007LL
typedef long long ll;

ll N;

ll fast_exp(ll a, ll b)
{
	ll p = 1;
	while (b)
	{
		if (b & 1) p = (a*p) % MOD;
		a = (a*a) % MOD;
		b /= 2;
	}
	return p;
}

int main()
{
	while (scanf("%lld ", &N) != EOF)
	{
		ll ans = fast_exp(2,N - 1) + fast_exp(2,(N + 1)/2  - 1) - 1;
		ans %= MOD;
		printf("%lld\n", ans);
	}

	return 0;
}
