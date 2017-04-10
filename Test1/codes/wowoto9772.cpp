#include <stdio.h>
#include <vector>

#define ll long long

using namespace std;

ll a, b, n;
ll ans;
void G(vector <ll> P, int c, long long v, int flag){
	if (flag){
		ans += b / v - (a - 1) / v;
	}
	else{
		ans -= b / v - (a - 1) / v;
	}
	for (int j = c + 1; j < P.size(); j++){
		ll lim = v*P[j];
		if (lim > b)break;
		G(P, j, lim, !flag);
	}
}

int main(){

	int t, x = 1;
	scanf("%d", &t);

	while (t--){
		scanf("%lld %lld %lld", &a, &b, &n);

		ans = b - a + 1;

		vector <ll> P;

		for (int i = 2; i*i <= n; i++){
			if (n%i)continue;
			else{
				P.push_back(i);
				while (!(n%i))n /= i;
			}
		}
		if (n > 1)P.push_back(n);

		for (int i = 0; i < P.size(); i++)G(P, i, P[i], 0);

		printf("Case #%d: %lld\n", x++, ans);
	}
}