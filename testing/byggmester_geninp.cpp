#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAX_P 10000000000

typedef long long ll;

int main()
{
	srand(time(NULL));
	int N = 1000, T = 1000;
	
	printf("%d %d\n", N,T);
	for (int i = 0; i < N + T; i++) printf("%lld\n", ((ll)rand()*RAND_MAX + rand()) % MAX_P);

	return 0;
}
