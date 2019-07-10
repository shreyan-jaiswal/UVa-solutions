#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 1e9;

int n, x, dp[1100][10], winds[1100][10];

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d", &x); x /= 100;

        for(int alt = 9; alt >= 0; alt--)
            for(int i = 0; i <  x; i++)
                scanf("%d", &winds[i][alt]);

        dp[0][0] = 0;
        for(int alt = 1; alt < 10; alt++)
            dp[0][alt] = INF;
        for(int i = 1; i <= x; i++){
            for(int alt = 0; alt < 10; alt++){
                dp[i][alt] = INF;
                if(alt > 0) dp[i][alt] = min(dp[i][alt], 60 - winds[i-1][alt-1] + dp[i-1][alt-1]);
                dp[i][alt] = min(dp[i][alt], 30 - winds[i-1][alt] + dp[i-1][alt]);
                if(alt < 9) dp[i][alt] = min(dp[i][alt], 20 - winds[i-1][alt+1] + dp[i-1][alt+1]);
                //printf("debug %d %d %d\n", i, alt, dp[i][alt]);
            }
        }
        printf("%d\n", dp[x][0]);
    }
}