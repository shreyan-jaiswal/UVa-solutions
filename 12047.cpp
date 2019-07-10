#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int tcs, n, m, s, t, p;
vector<vii> g, G;

int main(){
    cin >> tcs;
    while(tcs--){
        cin >> n >> m >> s >> t >> p;
        g.clear(); g.resize(n+1);
        G.clear(); G.resize(n+1);
        while(m--){
            int u, v, c;
            cin >> u >> v >> c;
            g[u].push_back(ii(v, c));
            G[v].push_back(ii(u, c));
        }
        priority_queue<ii, vii, greater<ii>> pq;
        pq.push(ii(0, s));
        vi dist(n+1, INF); dist[s] = 0;
        while(!pq.empty()){
            int d = pq.top().first, u = pq.top().second; pq.pop();
            if(d > dist[u]) continue;
            for(ii ne : g[u]){
                int v = ne.first, w = ne.second;
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push(ii(dist[v], v));
                }
            }
        }
        pq.push(ii(0, t));
        vi rdist(n+1, INF); rdist[t] = 0;
        while(!pq.empty()){
            int d = pq.top().first, u = pq.top().second; pq.pop();
            if(d > rdist[u]) continue;
            for(ii ne : G[u]){
                int v = ne.first, w = ne.second;
                if(rdist[v] > d + w){
                    rdist[v] = d + w;
                    pq.push(ii(rdist[v], v));
                }
            }
        }
        int ans = -1;
        for(int u = 1; u <= n; u++){
            for(ii ne : g[u]){
                int v = ne.first, w = ne.second;
                if(dist[u] + w + rdist[v] <= p) ans = max(ans, w);
            }
        }
        cout << ans << "\n";
    }
}
