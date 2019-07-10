#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> pi;

struct UFDS{
    vector<int> p, h;
    UFDS(int n){
        p.assign(n, 0);
        for(int i = 0; i < n; i++) p[i] = i;
        h.assign(n, 0);
    }
    int parent(int i){ return p[i]==i ? i : p[i] = parent(p[i]); }
    void join(int i, int j){
        int x = parent(i), y = parent(j);
        if(h[x] < h[y]){
            p[x] = y;
        } else {
            if(h[x] == h[y]) h[x]++;
            p[y] = x;
        }
    }
};

vector<pi> mst[102];
vector<pair<int, pi>> edges;
int c, s, q, vis[102];

int dfs(int from, int to, int m){
    if(from == to) return m;
    vis[from] = 1;
    int ans = INF;
    for(pi next : mst[from]){
        if(!vis[next.first])
            ans = min(ans, dfs(next.first, to, max(m, next.second)));
    }
    return ans;
}

int main(){
    int tc = 0;
    while(cin >> c >> s >> q, c){
        tc++;
        edges.clear();
        while(s--){
            int u, v, w; cin >> u >> v >> w; 
            edges.push_back(make_pair(w, make_pair(u,v)));
        }
        UFDS uf = UFDS(c+2);
        for(auto &v : mst) v.clear();
        sort(edges.begin(), edges.end());
        for(auto e: edges){
            int w = e.first, u = e.second.first, v = e.second.second;
            if(uf.parent(v) != uf.parent(u)){
                uf.join(u, v);
                mst[u].push_back(make_pair(v, w));
                mst[v].push_back(make_pair(u, w));
            }
        }

        cout << "Case #" << tc << '\n';
        while(q--){
            int u, v; cin >> u >> v;
            memset(vis, 0, sizeof vis);
            int ans = dfs(u, v, 0);
            if(ans >= INF) cout << "no path\n";
            else cout << ans << '\n';
        }
        cout << '\n';
    }
}