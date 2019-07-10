#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int m, n, p[101], f[101], dp[101][4005];

int backtrack(int i, int c){
    if(c > m) return -100000000;
    if(i == n) return 0;
    if(dp[i][c] != -1) return dp[i][c];
    return dp[i][c] = max(backtrack(i+1, c), f[i]+backtrack(i+1,c+p[i]));
}

int main(){
    while(~scanf("%d %d", &m, &n)){
        for(int j = 0; j < n; j++)
            scanf("%d %d", p+j, f+j);
        memset(dp, -1, sizeof dp);
        if (m > 2000) m+=200;
        printf("%d\n", backtrack(0, 0));
    }
}

