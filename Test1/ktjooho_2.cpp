#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>

#define MAX_NUM 1000000000
#define SQRT_NUM 50000

//1000000000
using namespace std;

typedef unsigned long long ULL;
bool non_prime[SQRT_NUM];
ULL t,a,b,n,s[500];
vector<int> prime;

int cnt;

void makeset(int idx,ULL mul,vector<int>&p)
{
    if(idx >= p.size())
        return ;
    cout<<"MUL:"<<mul*p[idx]<<endl;;
    makeset(idx+1, mul*p[idx], p);
    makeset(idx+1, mul, p);
    
}
void make_set(ULL mul, int idx, int cnt,vector<int>& prime)
{
    if(idx >= prime.size())
        return ;
    make_set(mul, idx+1, cnt, prime);
    make_set(mul*prime[idx],idx+1,cnt+1,prime);
    
    ULL mod = mul*prime[idx];
    ULL d = (b/mod - (a-1)/mod);
//    cout<<"CNT:"<<cnt<<",idx:"<<idx<<",D:"<<d<<",MUL:"<<mod<<endl;
    s[cnt] += d;
    
    
   
    
}


int main()
{
    for(ULL i=2; i * i<= MAX_NUM; ++i){
        if(!non_prime[i]){
            for(ULL j=i*i;j*j<MAX_NUM;j+=i){
                non_prime[j] = true;
            }
        }
    }
    for(int i=2;i*i<MAX_NUM;++i)
        if(!non_prime[i]) prime.push_back(i);
    
//    cout<<prime.size()<<endl;
    
    /*
    for(int i=2; i<SQRT_NUM;++i)
        if(!non_prime[i])
            ++cnt;
*/
//    cout<<cnt<<endl;
    
    cin>>t;
    for (int idx=1;idx<=t;++idx) {
        cin>>a>>b>>n;
//        cout<<n<<endl;
        vector<int> prime_vec;
        memset(s, 0, sizeof(s));
        
        for(auto p : prime){
            if(p > n || n==1)
                break;
            if( (n%p) == 0){
                while ((n%p) == 0) {n = n / p;}
                prime_vec.push_back(p);
            }
        }
        if(n!=1) prime_vec.push_back(n);
        /*
        for(auto k : prime_vec)
            cout<<k<<endl;
        cout<<prime_vec.size()<<endl;
        
         */
        make_set(1, 0, 1, prime_vec);
//        make_set(1, 0, 0, prime_vec);
        ULL sum = b-a+1;
//        cout<<"pre sum:"<<sum<<endl;
        for(int i=1;i<=prime_vec.size();++i){
            if(i%2)
                sum -= s[i];
            else
                sum += s[i];
//            cout<<i<<","<<s[i]<<endl;
            
        }
        printf("Case #%d: %llu\n",idx,sum);
        //U - N(S)
        //Si i의 배수의 집합.
        //U = b-a+1
        //
        
        
    }
    
    return 0;
}