#include <vector>
#include <cstdio>
using namespace std;

typedef vector<int> vi;

vi g[105], start, low, parent;
int n, ans, tim;

void bridges(int u){
    start[u] = low[u] = tim++;
    for(int v : g[u]){
        if(start[v] == -1){
            parent[v] = u;
            bridges(v);
            if(low[v] > start[u]){
                printf("%d - %d\n", u, v);
                ans++;
            }
            low[u] = min(low[u], low[v]);
        }
        else if(parent[u] != v){
            low[u] = min(low[u], start[v]);
        }
    }
    
}

int main(){
    while(~scanf("%d", &n)){
        for(int i = 0; i < n ; i++){
            int u; scanf("%d", &u);
            int m; scanf(" (%d) ", &m);
            while(m--){
                int v;
                scanf("%d", &v);
                g[u].push_back(v);
            }
        }
        ans = 0; tim = 0;
        start.assign(n, -1);
        low.assign(n, -1);
        parent.assign(n, -1);
        for(int u = 0; u < n; u++)
            if(start[u] == -1)
                bridges(u);
        printf("%d\n", ans);
    }
}