#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> pi;
typedef vector<pi> vpi;

int main(){
    int tcs; cin >> tcs;
    for(int tc = 1; tc <= tcs; tc++){
        cout << "Case #" << tc << ": ";
        int n, m, S, T; cin >> n >> m >> S >> T;
        if(S == T) { cout << "0\n"; continue; }
        vector<vpi> g(n);
        while(m--){
            int u, v, w; cin >> u >> v >> w;
            g[u].push_back(pi(v, w));
            g[v].push_back(pi(u, w));
        }
        priority_queue<pi, vector<pi>, greater<pi>> pq; pq.push(pi(0, S));
        vector<int> dist(n, INF); dist[S] = 0;
        while(!pq.empty()){
            int d, u; tie(d, u) = pq.top(); pq.pop();
            if(d > dist[u]) continue;
            for(pi ne : g[u]){
                int v = ne.first, w = ne.second;
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push(pi(dist[v], v));
                }
            }   
        }
        if(dist[T] == INF) cout << "unreachable\n";
        else cout << dist[T] << "\n";
    }

}