#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, S, dp[45][350][350], out, c[45][2];

int sqr(int x){ return x*x;}

int solve(int i, int x, int y){
    if(i == m) return (x*x+y*y==S*S) ? 0 : 1000000000;
    if(sqr(x)+sqr(y) > sqr(S)) return 1000000000;
    if(dp[i][x][y] != -1) return dp[i][x][y];
    int ans = 1000000000;
    for(int j = 0; sqr(x+j*c[i][0])+sqr(y+j*c[i][1]) <= sqr(S); j++){
        ans = min(ans, j + solve(i + 1, x+j*c[i][0], y+j*c[i][1]));
    }
    return dp[i][x][y] = ans;
}

int main(){
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &m, &S);
        for(int j = 0; j < m; j++) scanf("%d %d", c[j], c[j]+1);
        memset(dp, -1, sizeof dp);
        out = solve(0,0,0);
        if(out >= 1000000000) printf("no solution\n");
        else printf("%d\n", out);
    }
}