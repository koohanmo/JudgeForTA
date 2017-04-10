#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
using std::vector;
long long count_num(vector<int>& d, int depth, int idx, long long val, long long limit) {
	if (idx == d.size() || val > limit) return 0;
	long long ret = 0;
	for (int i = idx; i < d.size(); i++) {
		if (depth & 1) ret += limit / (d[i] * val);
		else ret -= limit / (d[i] * val);
		ret += count_num(d, depth + 1, i + 1, d[i] * val, limit);
	}
	return ret;
}
int main(void) {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		long long a, b, n;
		scanf("%lld%lld%lld", &a, &b, &n);
		std::vector<int> count;
		std::bitset<50010> c;
		long long tmp = n;
		for (long long i = 2; i*i <= n; i++) {
			if (!c[i]) {
				if(n%i==0)
					count.push_back(i);
				for (long long j = i *i; j*j <= n; j += i) {
					c[j] = 1;
				}
				while (tmp != 1 && tmp%i == 0) tmp /= i;
				if (tmp == 1) break;
			}
		}
		if (tmp != 1) count.push_back(tmp);
		long long ans = count_num(count, 1, 0, 1, b) - count_num(count, 1, 0, 1, a - 1);
		printf("Case #%d: %lld\n", tc, b - a +1 - ans);
	}
}