#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;

int t;
ll a, b, n;

ll yeah(ll a, ll d) {
	if (a == 0) return 0;
	if (d == 1) return a;
	ll count = a, p;
	vector<int> prd;
	int i, sz, mask, tl, mob;
	for (i = 2; i * i <= d; i++) {
		if (d % i == 0) prd.push_back(i);
		while (d % i == 0) d /= i;
	}
	if (d > 1)
		prd.push_back(d);
	sz = prd.size();
	tl = 1 << sz;
	
	for (mask = 1; mask < tl; mask++) {
		mob = 1; p = 1;
		for (i = 0; i < sz; i++)
			if ((mask >> i) & 1) {
				mob *= -1;
				p *= prd[i];
			}
		count += (a / p) * mob;
	}
	return count;
}

int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%lld%lld%lld", &a, &b, &n);
		printf("Case #%d: %lld\n", tt, yeah(b, n) - yeah(a-1, n));
	}
}