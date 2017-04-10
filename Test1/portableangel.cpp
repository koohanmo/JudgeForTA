#include <stdio.h>
#include <vector>

using namespace std;

typedef long long lli;

vector<lli> v;

int bitc(int k) {
	int r=0;
	while(k) {
		k-=k&-k;
		++r;
	}
	return r;
}

lli f(lli n) {
	if(n==0) return 0;
	lli res=0;
	int k=v.size();
	for(int i=1;i<(1<<k);i++) {
		lli mul=1;
		for(int j=0;j<k&&mul<=n;j++) if(i&(1<<j)) {
			mul*=v[j];
		}
		if(bitc(i)&1) res+=n/mul;
		else res-=n/mul;
	}
	return res;
}

int main() {
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++) {
		lli a, b, n;
		scanf("%lld %lld %lld",&a,&b,&n);
		v.clear();
		lli cur=2;
		while(cur*cur<=n) {
			if(n%cur==0) {
				v.push_back(cur);
				while(n%cur==0) n/=cur;
			}
			cur++;
		}
		if(n>1) v.push_back(n);
		printf("Case #%d: %lld\n",tc,(b-a+1)-(f(b)-f(a-1)));
	}
}