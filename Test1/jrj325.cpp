#include<stdio.h>
int T, N, l[3500], lc, sosu[100],sc,n_sosu[100],nc;
long long int A, B;
int main(){
	int i, j, check = 0;
	for (i = 2; i < 32000; i++){
		check = 1;
		for (j = 0; j < lc; j++){
			if (i%l[j] == 0){
				check = 0;
				break;
			}
			else if (l[j] * l[j] > i)
				break;

		}
		if (check)
			l[lc++] = i;
	}
	scanf("%d", &T);
	int count = 1;
	while (T--){
		scanf("%lld %lld %d", &A, &B, &N);
		// N을 소인수분해
		nc = sc = 0;
		for (i = 0; i < lc; i++){
			if (N%l[i] == 0)
				sosu[sc++] = l[i];
			while (N%l[i] == 0)
				N /= l[i];
			if (l[i] * l[i] > N)
				break;
		}
		if (N != 1)
			sosu[sc++] = N;
		n_sosu[nc++] = 1;
		for (i = 0; i < sc; i++){
			int n_c = nc;
			for (j = 0; j < n_c; j++){
				n_sosu[nc++] = n_sosu[j] * sosu[i] * -1;
			}
		}
		long long int ans=0;
		for (i = 0; i < nc; i++){
			ans += (B / n_sosu[i]) - ((A - 1) / n_sosu[i]);
		}
		printf("Case #%d: %lld\n", count, ans);
		count++;
	}
	return 0;
}