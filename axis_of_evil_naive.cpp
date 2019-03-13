/* Score 55/100
 * Execution timed out*/
#include <cstdio>
using namespace std;

#define MAX_N 250005
#define INF 100000000

struct point
{
	int x,y;
	point() {x = y = 0;}
	point(int x_, int y_) : x(x_), y(y_) {}
};
point operator- (point a, point b) {return point(a.x-b.x, a.y-b.y);}
int sq(int a) {return a*a;}
int norm(point a) {return sq(a.x) + sq(a.y);}
int dist(point a, point b) {return norm(a - b);}

int N, min_dist, a, b;
point p[MAX_N];

int main()
{
	while (scanf("%d ", &N) != EOF)
	{
		for (int i = 0; i < N; i++) scanf("%d %d ", &p[i].x, &p[i].y);
		
		min_dist = INF;
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++)
				if (dist(p[i],p[j]) < min_dist)
				{
					min_dist = dist(p[i],p[j]);
					a = i, b = j;
				}
		
		printf("%d %d\n", a + 1,b + 1);
	}

	return 0;
}
