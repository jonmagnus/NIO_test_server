/* Point 100/100*/
#include <cstdio>
using namespace std;

#define MAX_K 1005
#define MAX_R 1005

int main()
{
	int K,R,N;
	while (scanf("%d %d %d ", &K,&R,&N) != EOF)
	{
		char res[MAX_R][MAX_K];
		int r = 0, c = 0;
		while (N--)
		{
			char F; int A;
			scanf("%d %c ", &A,&F);

			while (A--)
			{
				res[r][r % 2 ? K - c - 1 : c] = F;
				c++;
				if (c >= K) c = 0, r++;
			}
		}

		for (int i = 0; i < R; i++)
			res[i][K] = '\0', printf("%s\n", res[i]);
	}


	return 0;
}
