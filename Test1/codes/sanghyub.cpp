#include<cstdio>
#include<cstring>
#include<cmath>
int soinsu[1000000];
int main() {
	int t; scanf("%d", &t);
	for (int l = 1; l <= t; l++) {
		memset(&soinsu, 0, sizeof(soinsu));
		long long a, b, n; scanf("%lld%lld%lld", &a, &b, &n);
		long long result = b - a + 1;
		int index = 1;
		for (int i = 2; i*i <= n; i++) {
			if (n%i == 0) {
				n /= i;
				if (soinsu[index - 1] != i) {
					soinsu[index++] = i;
				}
				i = 1;
			}
		}
		if (n != 1 &&index-1>=0 &&soinsu[index-1]!=n) soinsu[index++] = n;
		for (int i = 1; i < 1 << (index-1); i++) {
			int cnt = 0;
			int bae = 1;
			for (int j = 1; j < index; j++) {
				if ((i & (1 << (j - 1))) >= 1) {
					bae *= soinsu[j];
					cnt++;
				}
			}
			if (cnt % 2 == 0) {
				result += (b / bae - (a - 1) / bae);
			}
			else {
				result -= (b / bae - (a - 1) / bae);
			}
		}
		printf("Case #%d: %lld\n", l, result);
	}
}
