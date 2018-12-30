/* Score 100/100*/
#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_DIM 104

typedef pair<int,int> ii;

struct State {int x,y,r;};	// Define struct for state-space point
bool operator== (State a, State b) 
{
	return a.x == b.x
		&& a.y == b.y;
}

const int dx[] = {0,1,0,-1}, dy[] = {-1,0,1,0};

int main()
{
	int X,Y;
	char arena[MAX_DIM][MAX_DIM];
	int dist[4][MAX_DIM][MAX_DIM];
	while (scanf("%d %d ", &X,&Y) != EOF)
	{
		State start_pos, goal_pos;
		for (int i = 0; i < Y; i++)
			for (int j = 0; j < X; j++)
			{
				char c;
				scanf("%c ", &c);
				if (c == 'S')
					start_pos.x = j, start_pos.y = i;
				if (c == 'M')
					goal_pos.x = j, goal_pos.y = i;
				arena[j][i] = c;
			}
		start_pos.r = 0;
		
		memset(dist, -1, sizeof dist);
		queue<State> q;
		q.push(start_pos);
		dist[start_pos.r][start_pos.x][start_pos.y] = 0;
		while (!q.empty())
		{
			State cur = q.front(); q.pop();
			if (cur.x < 0 || cur.x >= X) continue;
			if (cur.y < 0 || cur.y >= Y) continue;
			
			int cur_dist = dist[cur.r][cur.x][cur.y], *ndist;
			if (cur == goal_pos)
			{
				printf("%d\n", cur_dist);
				break;
			}

			ndist = &dist[(cur.r + 3) % 4][cur.x][cur.y];
			if (*ndist == -1)
			{
				State npos = cur;
				npos.r = (cur.r + 3) % 4;
				q.push(npos);
				*ndist = cur_dist + 1;
			}
			ndist = &dist[(cur.r + 1) % 4][cur.x][cur.y];
			if (*ndist == -1)
			{
				State npos = cur;
				npos.r = (cur.r + 1) % 4;
				q.push(npos);
				*ndist = cur_dist + 1;
			}
			State npos = cur;
			npos.x += dx[cur.r];
			npos.y += dy[cur.r];
			if (npos.x < 0 || npos.x >= X) continue;
			if (npos.y < 0 || npos.y >= Y) continue;
			ndist = &dist[cur.r][npos.x][npos.y];
			if (*ndist != -1 || arena[npos.x][npos.y] == '#') continue;
			*ndist = cur_dist + 1;
			q.push(npos);
		}
	}

	return 0;
}
