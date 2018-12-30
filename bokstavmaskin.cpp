/* Score 80/100
 * Execution timed out*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX_N 10000005

int N, a_len, b_len, rev;
char a[MAX_N], b[MAX_N];

int main()
{
	while (scanf("%d ", &N) != EOF)
	{
		a_len = b_len = rev = 0;
		a[a_len++] = 'A';
		while (N--)
		{
			char c; scanf("%c ", &c);
			switch(c)
			{
			case 'x':
				if (rev) b[b_len++] = 'A';
				else a[a_len++] = 'A';
				break;
			case 'y':
				if (rev) a[a_len++] = 'B';
				else b[b_len++] = 'B';
				break;
			case 'z':
				rev = 1 - rev;
				break;
			}
		}

		a[a_len] = b[b_len] = '\0';
		if (rev)
		{
			reverse(b,b + b_len);
			printf("%s%s\n",b,a);
		}
		else
		{
			reverse(a,a + a_len);
			printf("%s%s\n",a,b);
		}
	}

	return 0;
}
