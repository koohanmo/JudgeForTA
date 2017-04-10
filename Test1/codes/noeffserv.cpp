#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iostream>

#define ENP     printf("**Entry Point**\n")
#define A       first
#define B       second
#define MP      make_pair

using namespace std;

typedef long long ll;

const int INF = 0x60000000;
const int MINF = -1000000000;
const ll mod = 1000000007;
const int cons = 50000001;
const double pi = 3.141592653589793;

bool isP[100001];

vector <int> getBit(int x)
{
	vector <int> ret;
	int cnt = 0;

	while (x)
	{
		if (x & 1)
		{
			ret.push_back(cnt);
		}
		x >>= 1;
		cnt++;
	}

	return ret;
}

ll gcd(ll a, ll b)
{
	if (b == 0)return a;
	return gcd(b, a%b);
}

int main()
{
	memset(isP, true, sizeof(isP));
	isP[0] = isP[1] = false;

	int t = sqrt(100000);

	for (int i = 2; i <= t; i++)
	{
		if (!isP[i])continue;
		for (int j = i*i; j <= 100000; j+= i)
		{
			isP[j] = false;
		}
	}

	int testCases;
	scanf("%d\n", &testCases);

	for (int testNum = 1; testNum <= testCases; testNum++)
	{
		printf("Case #%d: ", testNum);
	
		ll a, b, n;
		cin >> a >> b >> n;

		vector <ll> dat;

		for (int i = 2; i <= 100000; i++)
		{
			if (!isP[i])continue;
			if (n % (ll)i == 0)dat.push_back((ll)i);

			while (n % (ll)i == 0)
			{
				n /= (ll)i;
			}
		}

		if (n != 1)dat.push_back((ll)n);

		int lim = 1 << dat.size();

		ll ans = 0;

		for (int i = 1; i < lim; i++)
		{
			vector <int> bs = getBit(i);

			ll x = 1;
			ll gcdn = dat[bs[0]];
			for (int j = 0; j < bs.size(); j++)
			{
				x *= dat[bs[j]];
				gcdn = gcd(gcdn, dat[bs[j]]);
			}

			if(bs.size() > 1)x /= gcdn;

			ll c = b / x - (a - 1) / x;

			if (bs.size() % 2)ans += c;
			else ans -= c;
		}

		printf("%lld\n", b - a + 1 - ans);
	}


	return 0;
}