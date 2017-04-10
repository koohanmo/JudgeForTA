#include <stdio.h>
#include <vector>

long long count(long long a,long long b,long long c)
{
	return b/c-(a-1)/c;
}

std::vector<int> prime;
long long a,b,ans;

void BT(int k,int gob,int cnt)
{
	if(k==prime.size())
	{
		if(cnt%2) ans-=count(a,b,gob);
		else ans+=count(a,b,gob);
		return;
	}
	
	BT(k+1,gob,cnt);
	BT(k+1,gob*prime[k],cnt+1);
}

int main()
{
	int i,t,n,p;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%lld %lld %d",&a,&b,&n);
		prime.clear();
		ans=0;
		
		if(n%2==0)
		{
			prime.push_back(2);
			while(n%2==0) n/=2;
		}
		
		for(p=3;p*p<=n;p+=2)
		{
			if(n%p==0)
			{
				prime.push_back(p);
				while(n%p==0) n/=p;
			}
		}
		if(n>1) prime.push_back(n);
		
		BT(0,1,0);
		
		printf("Case #%d: %lld\n",i,ans);
	}
}