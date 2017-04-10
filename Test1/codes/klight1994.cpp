#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
int T;
ll A, B, N;
vector<ll> vec;
ll getVal(ll p,ll a,ll b)
{
	return (b / p) - ((a-1) / p);
}
ll solution(int pos,int &maxx, int state)
{
	ll ret = 0;
	if (pos == vec.size()) return 0;
	ll val = 1;
	state |= (1 << pos);
	int cnt = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (state & (1 << i))
		{
			cnt++;
			val *= vec[i];
		}
	}
	if (cnt == maxx) ret += getVal(val, A, B);
	else ret += solution(pos + 1,maxx, state);
	state &= ~(1 << pos);
	ret += solution(pos + 1, maxx,state);
	return ret;
}

int main()
{
	scanf("%d", &T);
	for(int t=1;t<=T;t++)
	{
		ll sol = 0;
		vec.clear();
		scanf("%lld %lld %lld", &A, &B, &N);
		sol = B - A + 1;
		for (ll i = 2; i*i <= N; i++)
			if (N%i == 0)
			{
				vec.push_back(i);
				while (N%i == 0) 
					N /= i;
			}
		if (N != 1) vec.push_back(N);
		for (int i = 1; i <= vec.size(); i++)
		{
			if (i % 2 == 1) sol -= solution(0, i,0);
			else sol += solution(0, i,0);
		}
		printf("Case #%d: %lld\n", t,sol);
	}
}