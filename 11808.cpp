#include <bits/stdc++.h>
using namespace std;

struct helper {
    int num, low, vis;
} d[2005];
vector<int> s;
int t, m, n, v, w, dir;
vector<int> g[2005];

int sc(int i){
    d[i].num = d[i].low = t++;
    s.push_back(i); d[i].vis = 1;
    for(int j : g[i]){
        if(d[j].num == -1) sc(j);
        if(d[j].vis) d[i].low = min(d[i].low, d[j].low);
    }
    if(d[i].num == d[i].num){
        while(1){
            int j = s.back(); s.pop_back(); d[i].vis = 0;
            if(i == j) break;
        }
    }
}

int main(){
    while(cin >> n >> m, n){
        for(auto &vec : g) vec.clear();
        while(m--){
            cin >> v >> w >> dir;
            g[v].push_back(w);
            if(dir == 2) g[w].push_back(v);
        }
        for(int i = 0; i < n; i++) d[i] = {-1, -1, 0};
        s.clear();
        t = 0;
        sc(0);
        int ans = 1;
        for(int i = 1; i < n; i++) if(d[i].num == -1) ans = 0;
        cout << ans << '\n';
    }
}