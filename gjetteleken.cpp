/* Score 100/100*/
#include <cstdio>
using namespace std;

int main()
{
	int N,M;
	while (scanf("%d %d ", &N,&M) != EOF)
	{
		while (M--)
		{
			int x;
			scanf("%d ", &x);
			if (x < N)	printf("FOR LITE\n");
			else if (x > N)	printf("FOR MYE\n");
			else		printf("RIKTIG\n");
		}
	}

	return 0;
}
