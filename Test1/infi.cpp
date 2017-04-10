#include <cstdio>

int main(){
    int T; scanf("%d",&T);
    while(T--){
        long long a,b,c; scanf("%lld %lld %lld",&a,&b,&c);
        int ans=0;
        for(long long d=a; d<=b;++d){
            if(d%c==0)ans++;
        }
        printf("%d\n",ans);
    }


    return 0;
}
