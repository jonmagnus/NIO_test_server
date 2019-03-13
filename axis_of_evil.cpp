#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 250003
#define MAX_DIST 100000000

typedef pair<int,int> ii;

struct point 
{
	int x,y,i;
	point(int x_, int y_, int i_): x(x_), y(y_), i(i_) {}
};
bool operator< (point a, point b)
{
	if (a.x < b.x) return true;
	if (a.x > b.x) return false;
	if (a.y < b.y) return true;
	if (a.y > b.y) return false;
	if (a.i < b.i) return true;
	return false;
}

point operator- (point a, point b) {return point(a.x-b.x, a.y-b.y, 0);}
int norm(point a) {return a.x*a.x + a.y*a.y;}
int sq_dist(point a, point b) {return norm(a - b);}
int sq(int a) {return a*a;}

int N;
point p[MAX_N];
int min_sq_dist;
int ia,ib;

void min_in_range(int begin, int end)
{
	if (end - begin > 2)
	{
		int mid = (begin + end)/2;
		min_in_range(begin,mid);
		min_in_range(mid,end);
		for (int i = begin; i < mid; i++) if (sq(p[mid].x - p[i].x) < min_sq_dist)
			for (int j = mid; j < end; j++) if (sq(p[p[j].x - p[mid].x) < min_sq_dist)
			{
				dist = 

			}
	}
}

int main()
{
	while (scanf("%d ", %N) != EOF)
	{
		for (int i = 0; i < N; i++)
		{
			int x,y;
			scanf("%d %d ", &x,&y);
			p[i] = point(x,y,i);
		}
		sort(p, p + N);

		min_sq_dist = MAX_DIST;
		ia = ib = 0;
	}
	
	
	return 0;
}
