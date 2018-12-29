/* Score 80/100
 * Wrong answer
 * TODO: Add detection for split top - 1 2 2 1 - by
 * changing primary test in loop.*/
#include <cstdio>
using namespace std;

#define MAX_N 1005
typedef long long ll;

int n, p[MAX_N];

int main()
{
	while (scanf("%d ", &n) != EOF)
	{
		for (int i = 0; i < n; i++) scanf("%d ", &p[i]);
		
		ll val = 0;
		int pre_p;
		if (p[0] <= p[1]) pre_p = p[0];
		for (int i = 1; i < n - 1; i++) 
			if ((p[i-1] - p[i])*(p[i] - p[i+1]) < 0)
			{
				if (p[i-1] < p[i])
					val += p[i] - pre_p;
				else
					pre_p = p[i];
			}
		if (p[n-1] >= p[n-2]) val += p[n-1] - pre_p;
		printf("%lld\n", val*1000);
	}

	return 0;
}
