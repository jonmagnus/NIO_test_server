/* Execuiton times out --> too slow.
 * Implement binary search.
 * 70/100 points*/
#include <cstdio>
#include <vector>
using namespace std;

struct Box {double x1,y1,x2,y2;};
struct Circle {double x,y,r;};

double norm_sq(double x, double y) {return x*x + y*y;}

int main()
{
	int X,Y,M,N;
	while (scanf("%d %d %d %d ", &X,&Y,&M,&N) != EOF )
	{
		vector<Box> boxes;
		vector<Circle> circles;
		while (M--)
		{
			char type;
			scanf("%c ", &type);
			if (type == 'r')
			{
				Box b;
				scanf("%lf %lf %lf %lf ", &b.x1,&b.y1,&b.x2,&b.y2);
				boxes.push_back(b);
			}
			else
			{
				Circle s;
				scanf("%lf %lf %lf ", &s.x,&s.y,&s.r);
				circles.push_back(s);
			}
		}

		while (N--)
		{
			double x,y;
			scanf("%lf %lf ", &x,&y);
			int count = 0;
			for (int i = 0; i < (int)boxes.size(); i++)
			{
				Box &b = boxes[i];
				if (x > b.x1 && y > b.y1
						&& x < b.x2 && y < b.y2)
					count++;
			}
			for (int i = 0; i < (int)circles.size(); i++)
			{
				Circle &s = circles[i];
				if (norm_sq(x - s.x, y - s.y) < s.r*s.r)
					count++;
			}
			printf("%d\n", count);
		}

	}

	return 0;
}

