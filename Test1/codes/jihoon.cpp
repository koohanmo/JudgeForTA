#include<cstdio>
long long int dap;
int bae[100];
int baep=0;
long long int a,b;
	
void dorec(int gop,int i,int cnt){
	long long int cal1,cal2;
	if(i==baep){
		cal1=b;
		cal2=a-1;
		cal1=cal1/gop;
		cal2=cal2/gop;
		cal1=cal1-cal2;
		if(cnt%2){
			dap-=cal1;
		}else{
			dap+=cal1;
		}
	}else{
		dorec(gop,i+1,cnt);
		dorec(gop*bae[i],i+1,cnt+1);
	}
}

int main(){
	int i,t,turn;int n;
	scanf("%d",&turn);
	for(t=1;t<=turn;t++){
		scanf("%lld %lld %d",&a,&b,&n);
		dap=0;baep=0;
		for(i=2;i*i<=n;i++){
			if(n%i==0){
				bae[baep++]=i;
				while(n%i==0){
					n/=i;
				}
			}
		}
		if(n>=2) bae[baep++]=n;
		dorec(1,0,0);
		printf("Case #%d: %lld\n",t,dap);
	}
}