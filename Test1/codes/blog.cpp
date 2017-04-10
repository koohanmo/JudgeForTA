#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
const int MAX = 1e9 + 1;
vector<int> primes;

void fillPrimes(vector<int>& ps, int ub) {
    ub = (int)sqrt((double)ub);
    vector<bool> isPrime(ub+1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=ub; i++){
        if(isPrime[i]){
            ps.push_back(i);
            for(int j=i*i; j<=ub; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

ll recurse(vector<ll>& ps, int i, ll soFar, ll bnd) {
    if(i == ps.size() || ps[i] * soFar > bnd) return 0;
    ll ret = (bnd / ps[i]) / soFar;
    ret += recurse(ps, i+1, soFar, bnd);
    ret -= recurse(ps, i+1, ps[i] * soFar, bnd);
    return ret;
}

void solve(int test, ll a, ll b, ll n) {
    vector<ll> factors;
    for(int i=0; i<primes.size();){
        if(n % primes[i] == 0){
            factors.push_back(primes[i]);
            while(n % primes[i] == 0) n /= primes[i];
        }else{
            i++;
        }
    }
    if(n != 1) factors.push_back(n);

    ll notRelPrimes = recurse(factors, 0, 1, b) - recurse(factors, 0, 1, a-1);
    ll answer = b - a + 1 - notRelPrimes;
    cout << "Case #" << test << ": " << answer << endl;
}

int main() {
    fillPrimes(primes, MAX);

    int tests;
    cin >> tests;
    for(int i=1; i<=tests; i++){
        ll a,b,n;
        cin >> a >> b >> n;
        solve(i, a,b,n);
    }

    return 0;
}

