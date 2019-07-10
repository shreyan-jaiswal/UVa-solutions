#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

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

int t, n, m;
vector<pair<int, pair<int, int>>> edges;
vector<int> to_ignore;

int kruskal(int ignore){
    UFDS uf = UFDS(n+1);
    int ret = 0;
    for(int i = 0; i < edges.size(); i++){
        if(i == ignore) continue;
        int w = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
        if(uf.parent(u) != uf.parent(v)){
            ret += w;
            uf.join(u,v);
            if(ignore == -1) to_ignore.push_back(i);
        }
    }
    return ret;
}

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        edges.clear();
        to_ignore.clear();
        while(m--){
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back(make_pair(w, make_pair(u, v)));
        }
        sort(edges.begin(), edges.end());
        int s1 = kruskal(-1);
        int s2 = 0x3f3f3f3f;
        for(int i : to_ignore){
            s2 = min(s2, kruskal(i));
        }
        cout << s1 << " " << s2 << '\n';
    }
}