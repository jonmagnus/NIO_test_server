/* Score 100/100*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

map<ii,int> dist, kart;
int B,L,S;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1};

int main()
{
	while (scanf("%d %d %d ", &B,&L,&S) != EOF)
	{
		dist.clear();
		kart.clear();
		queue<ii> q;
		while (S--)
		{
			int b,l; scanf("%d %d ", &b, &l);
			kart[ii(b,l)] = 1;
			if (b == 0)
			{
				dist[ii(b,l)];
				q.push(ii(b,l));
			}
		}
		
		int min_dist = -1;
		while (!q.empty())
		{
			ii u = q.front(); q.pop();
			if (u.first == B - 1) 
			{
				min_dist = dist[u];
				break;
			}
			for (int i = 0; i < 4; i++)
			{
				ii v = u;
				v.first += dx[i];
				v.second += dy[i];
				if (v.first < 0 || v.first >= B) continue;
				if (v.second < 0 || v.second >= L) continue;
				if (!kart.count(v)) continue;
				if (dist.count(v)) continue;
				
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}

		printf("%d\n", min_dist + 2);
	}

	return 0;
}
