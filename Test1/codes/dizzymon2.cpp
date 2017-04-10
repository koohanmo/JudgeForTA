#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lld;
 
int check[1000000];
 
vector<lld> sosu;
vector<lld> Nsosu;
 
void process1(lld mul, lld cnt, lld cnt2);
void process2(lld mul, lld cnt, lld cnt2);
lld sizer;
lld cnter_B, cnter_A;
lld A, B, N;
 
lld GCD(lld A, lld B){
    if (A%B == 0)
        return B;
    return GCD(B, A%B);
}
 
int main(){
 
    for (lld i = 2; i <= sqrt(1000000000); i++){
        if (check[i] == 0){
            sosu.push_back(i);
            for (lld j = i; j <= sqrt(1000000000); j += i){
                check[j] = 1;
            }
        }
    }
 
    lld T;
    cin >> T;
 
    for (lld tt = 1; tt <= T; tt++){
 
        cin >> A >> B >> N;
 
        while (!Nsosu.empty())
            Nsosu.pop_back();
        lld temp = N;
        for (lld i = 0; i < sosu.size(); i++){
            if (temp%sosu[i] == 0){
                Nsosu.push_back(sosu[i]);
                while (temp%sosu[i] == 0){
                    temp /= sosu[i];
                }
            }
        }
        if (temp != 1)
            Nsosu.push_back(temp);
        cnter_B = cnter_A = 0;
        sizer = Nsosu.size();
 
        process1(1, 0, 0);
        process2(1, 0, 0);
 
        lld answer = (B - cnter_B) - (A - cnter_A) + 1;
        if (GCD(A, N) !=1) answer--;
 
        printf("Case #%lld: %lld\n", tt, answer);
 
    }
}
 
void process1(lld mul, lld cnt, lld cnt2){
 
    if (cnt == sizer){
        if (cnt2 == 0)
            return;
        else if (cnt2 % 2 == 1){
            cnter_A += A / mul;
            return;
        }
        else{
            cnter_A -= A / mul;
            return;
        }
    }
    process1(mul*Nsosu[cnt], cnt + 1, cnt2 + 1);
    process1(mul, cnt + 1, cnt2);
}
void process2(lld mul, lld cnt, lld cnt2){
 
    if (cnt == sizer){
        if (cnt2 == 0)
            return;
        else if (cnt2 % 2 == 1){
            cnter_B += B / mul;
            return;
        }
        else{
            cnter_B -= B / mul;
            return;
        }
    }
    process2(mul*Nsosu[cnt], cnt + 1, cnt2 + 1);
    process2(mul, cnt + 1, cnt2);
}