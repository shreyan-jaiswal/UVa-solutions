#include <bits/stdc++.h>
using namespace std;

int vis[100000];
vector<int> g[100000];
int t, m, n;


int main(){
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(auto &v: g) v.clear();
        memset(vis, 0, sizeof vis);
        while(m--){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }
    }
}