#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k, dp[102][102];

int main(){
    while(~scanf("%d %d", &n, &k) && (n+k)){
        memset(dp, 0, sizeof dp);
        for(int j = 0; j <= k; j++)
            dp[0][j] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                for(int x = 0; x <=i; x++){
                    dp[i][j] += dp[i-x][j-1];
                }
                printf("debug %d %d %d\n", i, j, dp[i][j]);
            }
        }
        printf("%d\n", dp[n][k]);
    }
}