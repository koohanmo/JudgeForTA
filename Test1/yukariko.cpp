#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
	for(int i=2; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);

	for(int tc=1; tc <= T; tc++)
	{
		long long A, B, N;
		scanf("%lld%lld%lld", &A, &B, &N);

		vector<long long> factor;
		if(N != 1 && isPrime(N))
			factor.push_back(N);
		for(long long i=2; i*i <= N; i++)
		{
			if(N % i == 0)
			{
				if(isPrime(i))
					factor.push_back(i);
				if(N / i != i && isPrime(N / i))
					factor.push_back(N / i);
			}
		}

		long long mask = 1LL << factor.size();

		long long ans = B - A + 1;

		for(long long i=1; i < mask; i++)
		{
			long long num = 1;
			int cnt = 0;
			for(long long j=0; (1LL << j) < mask; j++)
			{
				if(i & (1LL << j))
				{
					num *= factor[j];
					cnt++;
				}
			}

			long long pick = B / num - (A - 1) / num;

			if(cnt & 1)
				ans -= pick;
			else
				ans += pick;
		}

		printf("Case #%d: %lld\n", tc, ans);
	}
	return 0;
}