/* Score 10/100
 * Wrong asnwer*/
#include <cstdio>
#include <cstring>
using namespace std;

#define MAX_N 303
#define min(A,B) ((A) < (B) ? (A) : (B))
#define INF 100000000000000LL
typedef long long ll;

int N,K;
ll dist[MAX_N][MAX_N];

int main()
{
	while (scanf("%d %d ", &N,&K) != EOF)
	{
		memset(dist,-1,sizeof dist);
		while (K--)
		{
			int u,v,d;
			scanf("%d %d %d ", &u,&v,&d);
			dist[u][v] = dist[v][u] = d;
		}

		for (int i = 0; i < N; i++) dist[i][i] = 0;
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++) if (dist[i][k] != -1 && dist[k][j] != -1)
				{
					if (dist[i][j] == -1) dist[i][j] = dist[i][k] + dist[k][j];
					else dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}

		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++) printf("%2lld ", dist[i][j]);
			printf("\n");
		}*/
		
		int hov;
		ll min_dist = INF;
		for (int i = 0; i < N; i++)
		{
			ll sum = 0;
			for (int j = 0; j < N; j++) sum += dist[i][j];
			if (sum < min_dist) min_dist = sum, hov = i;
		}
		
		printf("%d\n", hov);
	}

	return 0;
}
