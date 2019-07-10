#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
typedef long long integer;
integer garbage[21][21][21], prefix[21][21][21];
int tc, a, b, c;

int main(){
    scanf("%d", &tc);
    while(tc--){
        scanf("%d %d %d", &a, &b, &c);
        for(int i = 0; i < a; i++)
            for(int j = 0; j < b; j++)
                for(int k = 0; k < c; k++)
                    scanf("%lld", &(garbage[i][j][k]));
        memset(prefix, 0, sizeof prefix);
        for(int i = 1; i <= a; i++){
            for(int j = 1; j <= b; j++){
                for(int k = 1; k <= c; k++){
                    prefix[i][j][k] = garbage[i-1][j-1][k-1] + prefix[i-1][j][k] + prefix[i][j-1][k] + prefix[i][j][k-1] - prefix[i-1][j-1][k] - prefix[i-1][j][k-1] - prefix[i][j-1][k-1] + prefix[i-1][j-1][k-1];
                }
            }
        }
        integer ans = ~__LONG_LONG_MAX__;
        integer tmp;
        for(int i1 = 0; i1 < a; i1++)
            for(int i2 = i1 + 1; i2 <= a; i2++)
                for(int j1 = 0; j1 < b; j1++)
                    for(int j2 = j1 + 1; j2 <= b; j2++)
                        for(int k1 = 0; k1 < c; k1++)
                            for(int k2 = k1 + 1; k2 <= c; k2++){
                                tmp = prefix[i2][j2][k2] - prefix[i1][j2][k2] - prefix[i2][j1][k2] - prefix[i2][j2][k1] + prefix[i1][j1][k2] + prefix[i1][j2][k1] + prefix[i2][j1][k1] - prefix[i1][j1][k1];
                                if(tmp > ans) ans = tmp;
                            }
        printf("%lld\n", ans);
    }
}