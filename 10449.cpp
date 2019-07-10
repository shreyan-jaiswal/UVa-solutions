#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef vector<int> vi;

int cube(int x) {return x*x*x; }

int main(){
    int n;
    int tc = 0;
    while(cin >> n){
        cout << "Set #" << ++tc << "\n";
        vi busyness(n+1);
        for(int i = 1; i<=n; i++) cin >> busyness[i];
        int m; cin >> m;
        vector<vi> g(n+1);
        while(m--){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
        vi dist(n+1, INF); dist[1] = 0;
        for(int i = 0; i < 2*n-1; i++){
            for(int u = 1; u <= n; u++){
                for(int v : g[u]){
                    int w = cube(busyness[v] - busyness[u]);
                    dist[v] = min(dist[v], dist[u] + w);
                }
            }
        }
        vi neg(n+1, 0);
        for(int u = 1; u <= n; u++){
            for(int v : g[u]){
                int w = cube(busyness[v] - busyness[u]);
                if(dist[v] > dist[u] + w){
                    stack<int> s; s.push(v);
                    neg[v] = 1;
                    while(!s.empty()){
                        int a = s.top(); s.pop();
                        for(int b : g[a]){
                            if(!neg[b]){
                                neg[b] = 1;
                                s.push(b);
                            }
                        }
                    }
                }
            }
        }
        int q; cin >> q;
        while(q--){
            int u; cin >> u;
            if(neg[u] || dist[u] < 3 || dist[u] >= INF/2) cout <<"?\n";
            else cout << dist[u] << "\n";
        }
    }
}