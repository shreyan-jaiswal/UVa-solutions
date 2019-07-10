#include <cstdio>
#include <vector>
using namespace std;

int vis[101], n, m, u, v;
vector<int> res;
vector<int> g[101];

void solve(int i){
    vis[i] = 1;
    for(int j : g[i]){
        if(vis[j] == 0)
            solve(j);
    }
    res.push_back(i);
}

int main(){
    while(scanf("%d %d", &n, &m),n+m){
        res.clear();
        memset(vis, 0, sizeof vis);
        for(auto &v : g) v.clear();
        while(m--){
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
        }
        for(int i = 0; i < n; i++)
            if(vis[i] == 0)
                solve(i);
        for(int i = (int)res.size() - 1; i >= 1; i--) printf("%d ", res[i]);
        printf("\n");
    }
}