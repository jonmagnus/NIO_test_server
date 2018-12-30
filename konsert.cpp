/* Score 10/100
 * Wrong answer & Execution killed*/
#include <cstdio>
#include <map>
using namespace std;

#define MAX_N 503
#define INF 10000000
#define max(A,B) ((A) < (B) ? (B) : (A))
#define abs(A) ((A) < 0 ? -(A) : (A))
typedef pair<int,int> ii;

int N,T,x[MAX_N],y[MAX_N],b[MAX_N];
map<ii,int> memo;

int iter(int u, int t)
{
	if (t < 0) return -INF;	// If there is no more money left
	if (u == N) return 0;	// If last consert has been considered (useless)
	if (memo.count(ii(u,t))) return memo[ii(u,t)];
	//printf("iter: %2d %3d\n", u,t);

	int best = 0; 	// Consider not going to any further conserts
	for (int i = u + 1; i < N; i++)	// Try going directly to every consert after current one
		best = max(best,iter(i,t - b[i] - abs(x[t] - x[i]) - abs(y[t] - y[i])));
	return memo[ii(u,t)] = best < 0 ? -INF : best + 1;
}

int main()
{
	while (scanf("%d %d ", &N, &T) != EOF)
	{
		for (int i = 0; i < N; i++)
			scanf("%d %d %d ", &x[i], &y[i], &b[i]);

		int best = 0;
		memo.clear();
		// Try picking every consert as the first one
		for (int i = 0; i < N; i++) best = max(best, iter(i,T - abs(x[i]) - abs(y[i]) - b[i]));
		printf("%d\n", best);
	}

	return 0;
}
