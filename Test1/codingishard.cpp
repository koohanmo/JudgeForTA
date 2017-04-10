#include <stdio.h>
#include <vector>

typedef long long ll;

using namespace std;

int main()
{
	int T; scanf("%d", &T);
	for (int t = 1;t <= T;++t)
	{
		int N;
		ll A, B;
		scanf("%lld %lld %d", &A, &B, &N);
		
		--A;
		ll ans = B - A;

		vector<int> primes;
		bool p;
		for (int i = 2;i * i <= N;++i)
		{
			p = true;
			while (N % i == 0)
			{
				N /= i;
				if (p)
				{
					primes.push_back(i);
					p = false;
				}
			}
		}
		if (N != 1) primes.push_back(N);

		int n = primes.size();
		for (int i = 1;i < 1 << n;++i)
		{
			int k = 1, l = 1;
			for (int j = 0;j < n;++j)
			{
				if (i & 1 << j)
				{
					k *= -1;
					l *= primes[j];
				}
			}

			ans += (B / l - A / l) * k;
		}

		printf("Case #%d: %lld\n", t, ans);
	}

	return 0;
}