#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> ii;
typedef vector<ii> vii;

int t, m, n, e, tcs;

int main(){
    cin >> tcs;
    while(tcs--){
        cin >> n >> e >> t >> m;
        vector<vii> g(n+1);
        while(m--){
            int a, b, w;
            cin >> a >> b >> w;
            g[b].push_back(ii(w, a));
        }
        priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push(ii(0, e));
        vector<int> vis; vis.assign(n+1, INF); vis[e] = 0;
        while(!pq.empty()){
            ii fr = pq.top(); pq.pop();
            int d = fr.first, u = fr.second;
            if(d > vis[u]) continue;
            for(auto ed : g[u]){
                int w = ed.first, v = ed.second;
                if (vis[u] + w < vis[v]){
                    vis[v] = vis[u] + w;
                    pq.push(ii(vis[v], v));
                }
            }
        }
        int ret = 0;
        for(int i = 1; i <= n; i++){
            if(vis[i] <= t) ret++;
        }
        cout << ret << '\n';
    }
}