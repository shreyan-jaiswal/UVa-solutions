#include <cstdio>
#include <cstring>
using namespace std;

int n, q, d, m, a[205], dp[205][25][25];

int backtrack(int nn, int mm, int dd){
    if(mm == m) return dd == 0 ? 1 : 0;
    if(nn == n) return 0;
    if(dp[nn][mm][dd] != -1) return dp[nn][mm][dd];
    int ans = backtrack(nn + 1, mm, dd) + backtrack(nn + 1, mm + 1, (dd + a[nn]) % d);
    return dp[nn][mm][dd] = ans;
}

int main(){
    int tc = 1;
    while(scanf("%d %d", &n, &q), n){
        printf("SET %d:\n", tc);
        for(int i = 0; i < n; i++) scanf("%d", a+i);
        for(int qq = 1; qq <= q; qq++){
            scanf("%d %d", &d, &m);
            memset(dp, -1, sizeof dp);
            printf("QUERY %d: %d\n", qq, backtrack(0, 0, 0));
        }
        tc++;
    }
}