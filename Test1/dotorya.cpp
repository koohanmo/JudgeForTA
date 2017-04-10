#include <algorithm>
#include <assert.h>
#include <complex>
#include <ctype.h>
#include <functional>
#include <iostream>
#include <limits.h>
#include <locale.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <vector>
//#include <unordered_set>
//#include <unordered_map>

#pragma warning(disable:4996)
using namespace std;

#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <ldb, ldb> pdd;

int IT_MAX = 262144;
const int MOD = 1000000007;
const int INF = 1034567891;
const ll LL_INF = 1234567890123456789ll;
const db PI = 3.141592653589793238;
const ldb ERR = 1E-11;

vector <int> V;
int main() {
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++) {
		ll A, B;
		int N, i, j;
		scanf("%lld %lld %d", &A, &B, &N);
		for (i = 2; i*i <= N; i++) {
			if (N%i) continue;
			V.push_back(i);
			while (N % i == 0) N /= i;
		}
		if (N != 1) V.push_back(N);

		ll ans = 0;
		int M = V.size();
		for (i = 0; i < (1 << M); i++) {
			int c = 0;
			int v = 1;
			for (j = 0; j < M; j++) {
				if (i & (1 << j)) {
					c++;
					v *= V[j];
				}
			}
			if (c % 2) ans -= B / v - (A - 1) / v;
			else ans += B / v - (A - 1) / v;
		}
		printf("Case #%d: %lld\n", tc, ans);
		V.clear();
	}
	return 0;
}