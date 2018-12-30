/* Score 100/100*/
#include <cstdio>
using namespace std;

int A,B;

int main()
{
	while (scanf("%d ", &A) != EOF)
	{
		B = 0;
		int a,b;
		for (int i = 1; i < 3; i++) scanf("%d ", &a), A += a;
		for (int i = 0; i < 3; i++) scanf("%d ", &b), B += b;

		if (A > B)	printf("Anne\n");
		else if (A < B)	printf("Berit\n");
		else		printf("Uavgjort\n");
	}

	return 0;
}
