#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int t,n,siz,prime[35000]={1,1,0,};
    long long int a,b,ans;
    vector<int> prime_v;
    vector<long long int> div;
    for(int i=2;i<200;i++)
        if(!prime[i])
            for(int j=i*i;j<35000;j+=i)
                prime[j]=1;
    for(int j=2;j<=35000;j++)
        if(!prime[j])
            prime_v.push_back(j);
    siz=(int)prime_v.size();
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        scanf("%lld %lld %d",&a,&b,&n);
        ans=0;
        div.clear();
        for(long long int j=0;j<siz;j++){
            if((n%prime_v[j])==0)
                div.push_back(prime_v[j]);
                while((n%prime_v[j])==0)
                    n/=prime_v[j];
            if(n==1)
                break;
        }
        if(n!=1)
            div.push_back(n);
        int siz2=(int)div.size();
        for(long long int j=1;j<(1<<siz2);j++){
            long long int tmp=j,po=0,mul=1,cnt=0;
            while(tmp){
                if(tmp&1){
                    mul*=div[po];
                    cnt++;
                }
                tmp/=2;
                po++;
            }
            long long int val=(b/mul)-((a-1)/mul);
            if(!(cnt&1))
                val*=-1;
            ans+=val;
        }
        printf("Case #%d: %lld\n",i,b-a+1-ans);
    }
}