#include<cstdio>
#include<cstring>
#define int long long
int N, factor[40], n, sum, A, B, T, TC;
bool used[40];

int gcd(int x, int y) {
	return y ? gcd(y, x%y) : x;
}

void Count(int sz)
{
	if (sz == n) {
		int lcm = 1, cnt = 0, sum = 0;
		for (int i = 0; i < n; i++) {
			if (!used[i]) continue;
			++cnt;
			lcm = lcm * factor[i] / gcd(factor[i], lcm);
			if (lcm > B) return;
		} sum = B / lcm - (A - 1) / lcm;
		if (!cnt) return;
		::sum += (cnt&1 ? sum : -sum);
	} else {
		used[sz] = 0;
		Count(sz + 1);
		used[sz] = 1;
		Count(sz + 1);
	}
}

main()
{
	for (scanf("%lld", &T); T--;) {
		scanf("%lld%lld%lld", &A, &B, &N);
		n = sum = 0;
		memset(used, 0, sizeof used);
		for (int i = 2; i * i <= N && N > 1; i++) {
			if (N % i) continue;
			while (N % i == 0) N /= i;
			factor[n++] = i;
		} if (N > 1) factor[n++] = N;
		Count(0);
		printf("Case #%lld: %lld\n", ++TC, B - A - sum + 1);
	}	
	return 0;
}
