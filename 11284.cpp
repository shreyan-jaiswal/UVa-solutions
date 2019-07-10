#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define INF 1000000.

int t, n, m, p, u, v;
double w;
int dvd_pos[12];
double dvd_savings[12];
double dist[51][51];
double dp[51][4100];

double tsp(int pos, int mask){
    if(dp[pos][mask] != -INF) return dp[pos][mask];
    double ans = -dist[0][pos];
    for(int nxt_dvd = 0; nxt_dvd < p; nxt_dvd++)
        if((mask & (1 << nxt_dvd)) == 0)
            ans = max(ans, tsp(dvd_pos[nxt_dvd], mask | (1 << nxt_dvd)) + dvd_savings[nxt_dvd] - dist[pos][dvd_pos[nxt_dvd]]);
    return dp[pos][mask] = ans;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);

        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                dist[i][j] = INF;
        for(int i = 0; i <= n; i++)
            dist[i][i] = 0.;

        while(m--){
            scanf("%d %d %lf", &u, &v, &w);
            dist[u][v] = dist[v][u] = w;
        }
        scanf("%d", &p);
        for(int i = 0; i < p; i++)
            scanf("%d %lf", dvd_pos + i, dvd_savings + i);

        for(int k = 0; k <= n; k++)
            for(int i = 0; i <= n; i++)
                for(int j = 0; j <= n; j++)
                    if(dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
        
        for(int pos = 0; pos <= n; pos++)
            for(int mask = 0; mask < (1 << p); mask++)
                dp[pos][mask] = -INF;
        
        printf("%lf\n", tsp(0, 0));
    }
}