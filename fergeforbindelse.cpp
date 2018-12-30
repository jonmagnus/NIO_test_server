/* Score 100/100*/
#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

#define MAX_N 100005
typedef vector<int> vi;
typedef vector<vi> vvi;

int N,M,count;
vvi adj_list;
bitset<MAX_N> vis;

void dfs(int u)
{
	vis[u] = 1;
	for (int i = 0; i < (int)adj_list[u].size(); i++)
	{
		int v = adj_list[u][i];
		if (vis[v]) continue;
		dfs(v);
	}
}

int main()
{
	while (scanf("%d %d ", &N,&M) != EOF)
	{
		adj_list.assign(N,vi());
		vis.reset();
		count = 0;
		while (M--)
		{
			int u,v; scanf("%d %d ", &u,&v);
			adj_list[u].push_back(v);
			adj_list[v].push_back(u);
		}

		for (int i = 0; i < N; i++)
			if (!vis[i]) dfs(i), count++;

		printf("%d\n", count - 1);
	}

	return 0;
}
