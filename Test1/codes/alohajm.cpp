#include <cstdio>
#include <vector>
using namespace std;
typedef long long lld;
int check[1000000];
vector<lld> sosu, Nsosu;
lld sizer, cnter_B, cnter_A, A, B, N, T;
void process(lld mul, lld cnt, lld cnt2){
	if (cnt == sizer)
		if (cnt2 == 0) return;
		else if (cnt2 % 2 == 1){
			if (mul > B) return;
			cnter_B += B / mul;
			if (mul > A - 1) return;
			cnter_A += (A - 1) / mul; return;
		}
		else{
			cnter_A -= (A - 1) / mul;
			cnter_B -= B / mul;
			return;
		}
	else{
		process(mul*Nsosu[cnt], cnt + 1, cnt2 + 1);
		process(mul, cnt + 1, cnt2);
	}
}
int main(){
	for (lld i = 2; i <= 31623; i++)
		if (check[i] == 0){
			sosu.push_back(i);
			for (lld j = i; j <= 31623; j += i)
				check[j] = 1;
		}
	scanf("%lld", &T);
	for (lld t = 1; t <= T; t++){
		scanf("%lld %lld %lld", &A, &B, &N);
		Nsosu = vector<lld>(0);
		lld temp = N;
		for (lld i = 0; i < sosu.size(); i++){
			if (temp == 1) break;
			if (temp%sosu[i] == 0){
				Nsosu.push_back(sosu[i]);
				while (temp%sosu[i] == 0) temp /= sosu[i];
			}
		}
		if (temp != 1) Nsosu.push_back(temp);
		cnter_B = cnter_A = 0;
		sizer = Nsosu.size();
		process(1, 0, 0);
		printf("Case #%lld: %lld\n", t, (B - cnter_B) - (A - cnter_A) + 1);
	}
}