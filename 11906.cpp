#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int even[105][105], odd[105][105], water[105][105], vis[105][105];
vector<int> dr;
vector<int> dc;
int r, c, m, n, t, w;

void dfs(int i, int j){
    vis[i][j] = 1;
    int parity = 0;
    for(int dir = 0; dir < 8; dir++){
        int ip = i + dr[dir];
        int jp = j + dc[dir];
        if(0 <= ip && ip < r && 0 <= jp && jp < c && !water[ip][jp]){
            parity++;
            if(!vis[ip][jp]){
                dfs(ip, jp);
                even[i][j] += even[ip][jp];
                odd[i][j] += odd[ip][jp];
            }
        }
    }
    if(n == 0 || m == 0 || n == m) parity /= 2;
    if(parity % 2) odd[i][j]++;
    else even[i][j]++;
}

int main(){
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
        memset(even, 0, sizeof even);
        memset(odd, 0, sizeof odd);
        memset(water, 0, sizeof water);
        memset(vis, 0, sizeof vis);
        scanf("%d %d %d %d %d", &r, &c, &m, &n, &w);
        int drtmp[8] = {m, m, -m, -m, n, n, -n, -n}; dr.clear(); dr.insert(dr.end(), drtmp, drtmp + 8);
        int dctmp[8] = {n, -n, n, -n, m, -m, m, -m}; dc.clear(); dc.insert(dc.end(), dctmp, dctmp + 8);
        while(w--){
            int i, j;
            scanf("%d %d", &i, &j);
            water[i][j] = 1;
        }
        dfs(0,0);
        printf("Case %d: %d %d\n", tc, even[0][0], odd[0][0]);
    }
}