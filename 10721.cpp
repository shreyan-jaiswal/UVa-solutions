#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, k, m, dp[101][101];
int main(){
    while(~scanf("%d %d %d", &n, &k, &m)){
        memset(dp, 0, sizeof dp);
        for(int i = 1; i <= n; i++){
            if(i <= m) dp[i][1] = 1;
            for(int j = 1; j <= min(i, k); j++)
                for(int l = 1; l <= min(m, i); l++)
                    dp[i][j] += dp[i-l][j-1];
        }
        printf("%d\n", dp[n][k]);
    }
}