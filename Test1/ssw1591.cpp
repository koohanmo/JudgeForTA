#include<stdio.h>
#include<math.h>
int T;
long long int sosu[4000];
int sc = 0,nc;
long long int n_sosu[4000];
long long int add[2000],ac=0;
int main(){
	scanf("%d", &T);
	int i, j;
	bool go;
	for (i = 2; i < 31666; i++){
		go = true;
		for (j = 0; j < sc; j++){
			if (i%sosu[j] == 0){
				go = false;
				break;
			}
		}
		if (go){
			sosu[sc++] = i;
		}
	}
	int count = 1;
	while (T--){
		long long int A, B;
		int N,now;
		scanf("%lld %lld %d", &A, &B, &N);
		sc = 0;
		now = 0;
		nc = 0;
		while (1){
			if (N%sosu[now] == 0)
				n_sosu[nc++] = sosu[now];
			while (N%sosu[now] == 0)
				N /= sosu[now];
			if (N < sosu[now] * sosu[now])
				break;
			now++;
		}
		if (N != 1){
			n_sosu[nc++] = N;
		}
		add[0] = 1;
		ac = 1; 
		int oac;
		for (i = 0; i < nc; i++){
			oac = ac;
			for (j = 0; j < oac; j++){
				add[ac++] = add[j] * n_sosu[i] * -1;
			}
		}
		long long int tot = B - A + 1;
		for (i = 1; i < ac; i++){
			tot = tot + B / add[i] - (A - 1) / add[i];
		}
		printf("Case #%d: %lld\n", count, tot);
		count++;

	}
	return 0;
}