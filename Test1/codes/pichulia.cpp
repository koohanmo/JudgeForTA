#include<stdio.h>
#include<vector>
using namespace std;
int p[100000];
int pa[100000];
int pl;
int n;
vector<int> pn;
int m;
long long int a,b;
long long int get(long long int x)
{
	if(x==0)return 0;
	if(n==1)return x;

	long long int res=0;
	res = (x/n) * m;
	x%=n;
	int i, j, k,l;
	j = pn.size();
	j = 1<<j;
	long long int y;
	for(i=0;i<j;i++)
	{
		y=1;
		l=1;
		for(k=0;k<pn.size();k++)
			if(i&(1<<k))
			{
				y *= pn[k];
				l*=-1;
			}
		res += l*(x/y);
	}
	return res;
}
void inil()
{
	int i, j;
	p[0] = 2;
	pl=1;
	for(i=3;i<100000;i+=2)
	{
		if(pa[i]==0)
		{
			for(j=i*2;j<100000;j+=i)
				pa[j]=1;
			p[pl++]=i;
		}
	}
}
void build()
{
	int i, j;
	j=n;
	pn.clear();
	for(i=0;j>1 && i<pl;i++)
	{
		if(j%p[i]==0)
		{
			pn.push_back(p[i]);
			while(j%p[i]==0)
				j/=p[i];
		}
	}
	if(j>1)
		pn.push_back(j);
	m = n;
	for(i=0;i<pn.size();i++)
	{
		m /= pn[i];
		m *= (pn[i] - 1);
	}
}
int main()
{
	inil();
	int t,v;
	scanf("%d",&t);
	for(v=1;v<=t;v++)
	{
		scanf("%lld %lld %d",&a,&b,&n);
		build();
		long long int res = get(b);
		res -= get(a-1);
		printf("Case #%d: %lld\n",v,res);
	}
}