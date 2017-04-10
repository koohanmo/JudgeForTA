#include<stdio.h>
#include<vector>
#include<math.h>
using std::vector;



vector<long long> p;

long long num = 1;
long long dfs(long long idx, long long k,long long a) {
	if (k == 0) {
		return a / num;
	}
	if (idx == p.size()) {
		return 0;
	}
	long long ret = 0;
	for (int i = idx; i < p.size(); i++) {
		num *= p[i];
		ret += dfs(i + 1, k - 1, a);
		num /= p[i];
	}
	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int Tc = 1; Tc <= tc;Tc++) {
		long long a, b, n;
		scanf("%lld%lld%lld", &a, &b, &n);
		long long temp = sqrt(n);
		long long N = n;
		p.clear();
		for (int i = 2; i <= temp; i++) {
			if (N%i==0) {
				p.push_back(i);
				while (N%i == 0) {
					N /= i;
				}
			}
		}
		if (N != 1) {
			p.push_back(N);
		}
		long long ans = b-(a-1);
		for (int i = 1; i <= p.size(); i++) {
			if (i % 2 == 1) {
				ans -= dfs(0, i, b);
				ans += dfs(0, i, a - 1);
			}
			else {
				ans += dfs(0, i, b);
				ans -= dfs(0, i, a - 1);
			}
		}
		printf("Case #%d: %lld\n",Tc, ans);
	}
}