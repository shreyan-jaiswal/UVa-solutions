#include <cstdio>
#include <vector>
#include <bitset>
using namespace std;

int n, m, A[20], cds, sum=0, bestcds, bestsum;

void backtrack(int c){
    if(sum > n) return;
    if(sum > bestsum) {bestsum = sum; bestcds = cds; }
    if(c == m) return;
    cds |= 1 << c;
    sum += A[c];
    backtrack(c+1);
    cds &= ~(1 << c);
    sum -= A[c];
    backtrack(c+1);
}

int main(){
    while(~scanf("%d %d", &n, &m)){
        for(int i = 0; i < m; i++) scanf("%d", A+i);
        cds = 0; sum = 0; bestcds = 0; bestsum = 0;
        backtrack(0);
        for(int i = 0; i < m; i++) if(bestcds & (1 << i)) printf("%d ", A[i]);
        printf("sum:%d\n", bestsum);
    }
}