#include <cstdio>
using namespace std;

typedef long long ll;

int main()
{
	int n;
	scanf("%d ", &n);
	while (n--)
	{
		ll A,B,ans;
		char c;
		scanf("%lld %c %lld ", &A,&c,&B);
		switch(c)
		{
		case '+':
			ans = A + B;
			break;
		case '*':
			ans = A*B;
			break;
		case '-':
			ans = A - B;
			break;
		}
		printf("%lld\n",ans);
	}

	return 0;
}
