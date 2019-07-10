#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int t, n, x[11], y[11], dp[11][5000], X, Y;

int dist(int i, int j) {return abs(y[i]-y[j]) + abs(x[i]-x[j]);}

int tsp(int pos, int mask){
    if(mask == (1 << (n+1))-1) return dist(0, pos);
    if(dp[pos][mask] != -1) return dp[pos][mask];
    int ans = 100000000;
    for(int nxt = 1; nxt <= n; nxt++)
        if((mask & (1 << nxt)) == 0)
            ans = min(ans, dist(pos, nxt) + tsp(nxt, mask | (1 << nxt)));
    return dp[pos][mask] = ans;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %d", &X, &Y, x, y, &n);
        for(int i = 1; i <= n; i++) scanf("%d %d", x+i, y+i);
        memset(dp, -1, sizeof dp);
        printf("%d\n", tsp(0, 1));
    }
}