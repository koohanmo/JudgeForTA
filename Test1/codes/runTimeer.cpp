#include <cstdio>

int main(){
    int T; scanf("%d",&T);
    while(T--){
        int a,b,c; scanf("%d %d %d",&a,&b,&c);
        int A[100];
        A[101]=a;
        printf("%d",A[a+100]);
    }

    return 0;
}
