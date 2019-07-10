#include <cstdio>
#include <cmath>

int main(){
    int t, d, k, n, deg;
    long long c[25], res;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &deg);
        for(int i = 0; i <= deg; i++) scanf("%lld", c+i);
        scanf("%d %d", &d, &k);
        for(n = 1; d * n * (n+1) < 2 * k; n++);
        res = 0;
        for(int i = 0; i <= deg; i++){
            res += c[i] * (long long) pow(n, i);
        }
        printf("%d\n", res);
    }
}