/* Score 100/100*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 100005
#define max(A,B) ((A) < (B) ? (B) : (A))
typedef pair<int,int> ii;
typedef vector<ii> vi;
typedef vector<vi> vvi;

int N,A,B,adist[MAX_N],bdist[MAX_N];
vvi adj_list;

int main()
{
	while (scanf("%d ", &N) != EOF)
	{
		scanf("%d %d ", &A, &B);
		adj_list.assign(N,vi());
		for (int i = 0; i < N-1; i++)
		{
			int u,v,d;
			scanf("%d %d %d ", &u,&v,&d);
			adj_list[u].push_back(ii(v,d));
			adj_list[v].push_back(ii(u,d));
		}

		queue<int> q;
		memset(adist,-1,sizeof adist);
		adist[A] = 0;
		q.push(A);
		int u;
		while (!q.empty())
		{
			u = q.front(); q.pop();
			for (int i = 0; i < (int)adj_list[u].size(); i++)
			{
				int v = adj_list[u][i].first;
				int d = adj_list[u][i].second;
				if (adist[v] != -1) continue;
				adist[v] = adist[u] + d;
				q.push(v);
			}
		}

		memset(bdist,-1,sizeof bdist);
		bdist[B] = 0;
		q.push(B);
		while (!q.empty())
		{
			u = q.front(); q.pop();
			for (int i = 0; i < (int)adj_list[u].size(); i++)
			{
				int v = adj_list[u][i].first;
				int d = adj_list[u][i].second;
				if (bdist[v] != -1) continue;
				if (bdist[u] + d >= adist[v]) continue;
				bdist[v] = bdist[u] + d;
				q.push(v);
			}
		}

		int max_dist = 0;
		for (int i = 0; i < N; i++) if (bdist[i] != -1) max_dist = max(max_dist,adist[i]);
		printf("%d\n", max_dist);
	}
			
	return 0;
}
