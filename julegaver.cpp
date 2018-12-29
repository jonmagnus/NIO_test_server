/* Score 100/100*/
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_N 100005
#define max(A,B) ((A) < (B) ? (B) : (A))
typedef vector<int> vi;
typedef vector<vi> vvi;

char color[MAX_N];
int cc_val[MAX_N], cc_size[MAX_N], cc_num, n;
vvi adj_list;

bool bicolor(int u, int col, int &val, int &size)
{
	//printf("bicolor: %2d %2d %2d %2d\n", u,col,val,size);
	color[u] = col;
	if (col) val++;
	size++;
	for (int i = 0; i < (int)adj_list[u].size(); i++)
	{
		int v = adj_list[u][i];
		if (color[v] == color[u]) return false;
		if (color[v] != -1) continue;
		if (!bicolor(v, 1 - col, val, size)) return false;
	}
	return true;
}
	

int main()
{
	while (scanf("%d ", &n) != EOF)
	{
		adj_list.assign(n,vi());
		for (int i = 0; i < n; i++)
		{
			int m; scanf("%d ", &m);
			while (m--)
			{
				int v; scanf("%d ", &v);
				adj_list[i].push_back(v);
			}
		}

		bool colorable = true;
		memset(color, -1, sizeof color);
		memset(cc_val, 0, sizeof cc_val);
		memset(cc_size, 0, sizeof cc_size);
		cc_num = 0;
		for (int i = 0; i < n && colorable; i++) if (color[i] == -1)
		{
			colorable = bicolor(i,0,cc_val[cc_num],cc_size[cc_num]);
			cc_num++;
		}

		if (colorable)
		{
			int sum = 0;
			for (int i = 0; i < cc_num; i++)
				sum += max(cc_val[i], cc_size[i] - cc_val[i]);
			printf("%d\n", sum);
		}
		else
			printf("0\n");
	}

	return 0;
}
