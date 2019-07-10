#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << #x << " = " << x << endl;

vector<pair<int, pair<int, int>>> el;
int n, m, u, v, w;
vector<int> out;

struct UFDS{
    vector<int> p, h;
    UFDS(int n){
        p.assign(n, 0); for(int i = 0; i < n;i++) p[i] = i;
        h.assign(n, 0);
    }
    int parent(int i){
        return i == p[i] ? i : p[i] = parent(p[i]);
    }
    void join(int i, int j){
        int x = parent(i), y = parent(j);
        if(x != y){
            if(h[y] < h[x]){
                p[y] = x;
            }
            else{
                p[x] = y;
                if(h[x] == h[y]) h[x]++;
            }
        }
    }
};

int main(){
    while(cin >> n >> m, n){
        el.clear();
        while(m--){
            cin >> u >> v >> w;
            el.push_back(make_pair(w, make_pair(u,v)));
        }
        sort(el.begin(), el.end());
        UFDS uf = UFDS(n);
        out.clear();
        for(auto e : el){
            w = e.first; u = e.second.first; v = e.second.second;
            if(uf.parent(u) == uf.parent(v))
                out.push_back(w);
            else
                uf.join(u, v);   
        }
        if(out.size() == 0) cout << "forest\n";
        sort(out.begin(), out.end());
        for(int i = 0; i < out.size(); i++) cout << out[i] << " \n"[i==out.size()-1];
    }
}