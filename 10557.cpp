#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef vector<int> vi;

vi energy, dist;
vector<vi> g;
int n;

void dfs(int i){
    dist[i] = INF;
    for(int j : g[i]){
        if(dist[i] != INF){
            dfs(j);
        }
    }
}

int main(){
    while(cin >> n, n != -1){
        energy.resize(n+1);
        g.clear(); g.resize(n+1);
        for(int u = 1; u <= n; u++){
            cin >> energy[u];
            int m; cin >> m;
            while(m--){
                int v; cin >> v;
                g[u].push_back(v);
            }
        }
        dist.assign(n+1, -INF); dist[1] = 100;
        for(int k = 1; k <= n-1; k++){
            for(int u = 1; u <= n; u++){
                for(int v : g[u]){
                    if(dist[u] + energy[v] > 0 && dist[v] < dist[u] + energy[v]){
                        dist[v] = dist[u] + energy[v];
                    }
                }
            }
        }
        for(int u = 1; u <= n; u++){
            for(int v : g[u]){
                if(dist[u] + energy[v] > 0 && dist[v] < dist[u] + energy[v]){
                    dfs(v);
                }
            }
        }
        cout << (dist[n] > 0 ? "winnable\n" : "hopeless\n");
    }
}