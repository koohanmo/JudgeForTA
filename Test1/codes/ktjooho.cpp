#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

#define MAX_NUM 1000000000
using namespace std;

typedef unsigned long long ULL;
bool n_p[35000];
ULL t,a,b,n,s[50];
vector<int> p;

void make_set(ULL mul, int idx, int cnt,vector<int>& prime)
{
    if(idx >= prime.size())
        return ;
    make_set(mul, idx+1, cnt, prime);
    make_set(mul*prime[idx],idx+1,cnt+1,prime);
    ULL mod = mul*prime[idx];
    ULL d = (b/mod - (a-1)/mod);
    s[cnt] += d;
}
int main()
{
    for(ULL i=2; i * i<= MAX_NUM; ++i)
        if(!n_p[i])
            for(ULL j=i*i;j*j<MAX_NUM;j+=i)
                n_p[j] = true;

    for(int i=2;i*i<MAX_NUM;++i)
        if(!n_p[i]) p.push_back(i);
    
    cin>>t;
    for (int idx=1;idx<=t;++idx) {
        cin>>a>>b>>n;
        vector<int> prime_num;
        memset(s, 0, sizeof(s));
        
        for(auto d : p){
            if(d > n || n==1)
                break;
            if( (n%d) == 0){
                while ((n%d) == 0) {n=n/d;}
                prime_num.push_back(d);
            }
        }
        if(n!=1) prime_num.push_back(n);

        make_set(1, 0, 1, prime_num);
        
        ULL sum = b-a+1;

        for(int i=1;i<=prime_num.size();++i){
            if(i%2)
                sum -= s[i];
            else
                sum += s[i];
        }
        printf("Case #%d: %llu\n",idx,sum);
    }
    return 0;
}