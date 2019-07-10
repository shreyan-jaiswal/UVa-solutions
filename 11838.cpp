#include <bits/stdc++.h>
using namespace std;
#define watch(x) #x << "=" << x << ", "

struct helper {
    int num, low, vis, scc;
} d[2005];
vector<int> s;
int ans;
int t, m, n, v, w, dir;
vector<int> g[2005];

void sc(int i){
    d[i].num = d[i].low = t++;
    s.push_back(i); d[i].vis = 1;
    for(int j : g[i]){
        if(d[j].num == -1) sc(j);
        if(d[j].vis) d[i].low = min(d[i].low, d[j].low);
    }
    if(d[i].num == d[i].low){
        while(1){
            int j = s.back(); s.pop_back(); d[j].vis = 0;
            if(i == j) break;
        }
        ans++;
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
        for(int i = 1; i <= n; i++) d[i] = {-1, -1, 0, 0};
        s.clear();
        t = 0; ans = 0;
        for(int i = 1; i <= n; i++)
            if(d[i].num == -1)
                sc(i);
        cout << (int) (ans <= 1) << '\n';
    }
}