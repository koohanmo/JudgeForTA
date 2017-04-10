#include<cstdio>
#include<vector>

using namespace std;

vector<int> p;
long long n, a, b, result;

void dfs(int idx, bool add, int state)
{
	if(idx == p.size())
	{
		if(state == 0)	return;
		long long val = 1;
		for(int i = 0; i < p.size(); i++)
			if(state & (1<<i))
				val *= p[i];
		
		long long add_val = (b/val) - ((a-1)/val);
		if(add)
			result += add_val;
		else
			result -= add_val;
		return;
	}

	dfs(idx+1, !add, state + (1<<idx));
	dfs(idx+1, add, state);
}

int main()
{
	int tcc, t=1;
	scanf("%d", &tcc);
	while(tcc--)
	{
		p.clear();
		scanf("%lld %lld %lld", &a, &b, &n);
		if(n == 1)
		{
			printf("Case #%d: %lld\n", t++, b - a + 1);
			continue;
		}
		for(int i = 2; i*i <= n; i++)
		{
			if(n % i == 0)
			{
				p.push_back(i);
				while(n != 1 && n%i == 0)
					n /= i;
			}
		}
		if(n != 1)
			p.push_back(n);

		result = 0; // 서로소 아닌것 갯수
		dfs(0, 0, 0);
		printf("Case #%d: %lld\n", t++, b - a - result + 1);
	}
}
