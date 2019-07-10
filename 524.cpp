#include <cmath>
#include <cstdio>
using namespace std;

bool prime(int p){
    if(p <= 3) return p > 1;
    for(int d = 2; d < sqrt((double) p) + 1; d++) if(p % d == 0) return false;
    return true;
}

int A[20], n, taken;

void backtrack(int i){
    if(i == n && prime(A[n-1] + 1)){
        for(int j = 0; j < n; j++) printf("%d ", A[j]);
        printf("\n");
        return;
    }

    for(int k = 2; k <= n; k++){
        if((taken & (1 << k)) == 0 && prime(k + A[i-1])){
            taken |= (1 << k); A[i] = k;
            backtrack(i+1);
            taken &= ~(1 << k);
        }
    }
}

int main(){
    A[0] = 1;
    int c = 0;
    while(~scanf("%d", &n)){
        if(c) printf("\n");
        printf("Case %d:\n", ++c);
        backtrack(1);
    }
}
