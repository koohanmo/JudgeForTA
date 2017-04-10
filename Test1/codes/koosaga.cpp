#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <functional>
#include <vector>
#include <numeric>
#include <deque>
#include <utility>
#include <bitset>
#include <iostream>
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

lint solve(int p, lint q){
	vector<int> ys;
	for(int i=2; i*i<=p; i++){
		if(p % i == 0){
			ys.push_back(i);
			while(p % i == 0) p /= i;
		}
	}
	if(p != 1) ys.push_back(p);
	lint ret = 0;
	for(int i=1; i<(1<<ys.size()); i++){
		int tmp = 1, cnt = 0;
		for(int j=0; j<ys.size(); j++){
			if((i >> j) & 1){
				tmp *= ys[j];
				cnt++;
			}
		}
		if(cnt % 2) ret += (q / tmp);
		else ret -= q / tmp;
	}
	return q - ret;
}

int main(){
	int t;
	cin >> t;
	for(int i=0; i<t; i++){
		lint a, b, n;
		cin >> a >> b >> n;
		printf("Case #%d: %lld\n",i+1, solve(n, b) - solve(n, a-1));
	}
}