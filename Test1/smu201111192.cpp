#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long gcd(long long a,long long b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}
long long getLcm(long long a,long long b){
    return a*b/gcd(a,b);
}
vector<long long> primes;
long long prime[200001];
int main(){
    long long n;
    cin>>n;
    for(long long i=1;i<=200000;i++)prime[i]=1;
    long long sqrtNN=sqrt(200000);
    for(long long i=2;i<=sqrtNN;i++){
        for(long long j=i*i;j<=200000;j+=i){
            prime[j]=0;
        }
    }
    for(long long i=2;i<=200000;i++){
        if(prime[i])primes.push_back(i);
    }
    vector<long long> div;
    for(long long k=0;k<n;k++){
        long long a,b,c;
        cin>>a>>b>>c;
        a--;
        div.clear();
        for(long long i=0;i<primes.size();i++){
            if(c<primes[i])break;
            if(c%primes[i]==0)
                div.push_back(primes[i]);
        }

        for(int i=0;i<div.size();i++)
            while(c%div[i]==0)
                c/=div[i];
        if(c!=1)div.push_back(c);
        long long ans=b-a;
        long long minus=0;
        for(long long i=1;i<((long long )1<<div.size());i++){
            long long cnt=0;
            long long lcm=1;
            for(long long j=0;j<div.size();j++){
                if(i&((long long)1<<j)){
                    lcm=getLcm(lcm,div[j]);
                    cnt++;
                }
            }
            if(cnt%2){
                minus+=(b/lcm-a/lcm);
            }
            else{
                minus-=(b/lcm-a/lcm);
            }
        }
        printf("Case #%lld: %lld\n",k+1,ans-minus);
    }
    return 0;
}
