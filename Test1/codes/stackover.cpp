#include <cstdio>
#define ll long long

int solve(ll n){
    if(n==0) return 1;
    int e[10000];
    int f[10000];
    return 1*solve(n-1);
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        ll a,b,c; scanf("%lld %lld %lld",&a,&b,&c);
        int q=solve(c);
        printf("%lld\n",a);
    }
    return 0;
}
