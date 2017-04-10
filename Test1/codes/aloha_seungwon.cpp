#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
#define MN 1000000000
#define ll long long
vector<int> prime;
ll A, B, N;
ll counting(vector<ll>& facotrs, int i, ll acc, ll upper){
    if(i==facotrs.size() || facotrs[i]*acc > upper) return 0;
    ll ret = (upper/facotrs[i])/acc;
    ret += counting(facotrs, i+1, acc, upper);
    ret -= counting(facotrs, i+1, facotrs[i]*acc, upper);
    return ret;
}
ll main2(){
    cin >> A >> B >> N;
    vector<ll> factors;
    for(auto&p:prime){
        if(N%p==0) {
            factors.push_back(p);
            while(N%p==0) N/=p;
        }
    }
    if(N!=1)factors.push_back(N);
    return B-A+1 - (counting(factors, 0, 1, B)-counting(factors, 0, 1, A-1));
}
int main () {
    int SN = (int)sqrt(MN);
    vector<bool> isPrime = vector<bool>(SN, true);
    isPrime[1]=0;
    for(int i=2;i<=SN;i++){
        if(isPrime[i]) {
            prime.push_back(i);
            for(int j=2; i*j<= SN; j++){
                isPrime[i*j]=false;
            }
        }
    }
    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        printf("Case #%d: %lld\n", t, main2());
    }
    while(T--) main2();
    return 0;
}