/* TODO: Current program not working (test case 6 2 2 4 1 1). Modify program
 * so it runs a specialized verion of the algorithm for every value of f.
 * (should not increase runtime to more than O(N*M*F)=4e7)*/
#include <cstdio>
#include <bitset>
using namespace std;

#define MAX_N 10005
#define MAX_M 102

int N,M,A[MAX_N],F;
bitset<2*MAX_N*MAX_M> memo;

int to_num(int idx, int val) {return 2*idx*N + (val + N);}
bool possible(int idx, int val)
{
	if (idx < 0 || idx >= M) return false;
	if (val < -N || val > N) return false;
	return memo[to_num(idx,val)];
}

int main()
{
	while (scanf("%d %d ", &N, &M) != EOF)
	{
		for (int i = 0; i < M; i++) scanf("%d ", &A[i]);
		memo.reset();
		memo[to_num(0,-A[0])] = memo[to_num(0,0)] = memo[to_num(0,A[0])] = 1;	
		for (int i = 1; i < M; i++)
			for (int j = -N; j <= N; j++)
				memo[to_num(i,j)] = (memo[to_num(i-1,j)] ||
						possible(i-1,j+A[i]) ||
						possible(i-1,j-A[i]));
		
		scanf("%d ", &F);
		while (F--)
		{
			int f; scanf("%d ", &f);
			printf("%s\n", possible(M-1,2*A[f]) ? "JA" : "NEI");
		}

		for (int i = 0; i < M; i++)
		{
			for (int j = -N; j <= N; j++) printf("%c", possible(i,j) ? '1' : '0');
			printf("\n");
		}
	}

	return 0;
}
