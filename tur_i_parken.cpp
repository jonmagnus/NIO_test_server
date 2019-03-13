/* Score 50/100
 * Wrong answer*/
#include <cstdio>
#include <vector>
using namespace std;

#define MAX_N 1000005

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

class UnionFind
{
private:
	vi p, rank;
	int N;
public:
	int num_sets;
	bool duplicate;
	ii dupair;
	UnionFind(int n)
	{
		N = num_sets = n;
		p.assign(n,0);
		rank.assign(n,0);
		for (int i = 0; i < n; i++) p[i] = i;
		duplicate = false;
	}
	int get_p(int u) {return p[u] == u ? u : p[u] = get_p(p[u]);}
	bool is_same_set(int u, int v) {return get_p(u) == get_p(v);}
	void unite(int u, int v)
	{
		if (is_same_set(u,v)) {
			duplicate = true;
			dupair = ii(u,v);
			return;
		}
		int x = get_p(u), y = get_p(v);
		if (rank[x] < rank[y]) p[x]=y;
		else
		{
			p[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
		num_sets--;
	}
};

int N,M;

int main()
{
	while (scanf("%d %d ", &N, &M) != EOF)
	{
		UnionFind UF(N);
		fprintf(stderr, "Initiated UnionFind.\n");
		while (M--)
		{
			int P;
			scanf("%d ", &P);
			int u, v;
			scanf("%d ", &u);
			P--, u--;
			while (P--)
			{
				scanf("%d ", &v);
				v--;
				UF.unite(u,v);
			}
		}

		fprintf(stderr, "Completed reading input.\n");

		if (UF.num_sets != 1)
		{
			int i;
			for (i = 1; i < N && UF.is_same_set(0,i); i++);
			printf("Ingen veier mellom 1 og %d.\n", i + 1);
		}
		else
		{
			if (UF.duplicate)
				printf("Det finnes flere veier mellom %d og %d.\n", UF.dupair.first + 1, UF.dupair.second + 1);
			else
				printf("Alt er fint.\n");
		}
	}

	return 0;
}
