#include<bits/stdc++.h>
using namespace std;
const int sz = 1<<15;
bool isp[sz];
vector<int> p,q;
int bcnt(int i)
{
    int r = 0;
    while(i)
    {
        r++;
        i -= i&-i;
    }
    return r;
}
int main()
{
    isp[2] = true;
    for(int i=3;i<sz;i+=2) isp[i] = true;
    for(int i=3;i*i<sz;i+=2)
    {
        if(!isp[i]) continue;
        for(int j=i*i;j<sz;j+=i) isp[j] = false;
    }
    p.push_back(2);
    for(int i=3;i<sz;i+=2) if(isp[i]) p.push_back(i);
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        long long a,b;
        int c;
        scanf("%lld%lld%d",&a,&b,&c);
        a--;
        q.clear();
        for(int i : p)
        {
            if(i>c) break;
            if(c%i) continue;
            q.push_back(i);
            while(c%i == 0) c /= i;
        }
        if(c>1) q.push_back(c);
        long long ans = b-a;
        for(int i=1;i<(1<<q.size());i++)
        {
            long long d = 1;
            int e = bcnt(i);
            for(int j=0;j<q.size();j++) if(i&(1<<j)) d *= q[j];
            long long f = b/d - a/d;
            ans += (e&1)?-f:f;
        }
        printf("Case #%d: %lld\n",t,ans);
    }
}