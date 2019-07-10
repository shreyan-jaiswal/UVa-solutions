#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
vi g[10005];
struct dfs_data {
    int id, pigeon, parent, start, low;
} d[10005];
int n, m, t;

bool operator< (const helper &a, const helper &b){
    return a.pigeon != b.pigeon ? a.pigeon > b.pigeon : a.id < b.id;
}

void dfs(int u){
    d[u].start = d[u].low = t++;
    int dfs_children = 0;
    for(int v : g[u]){
        if(d[v].start == -1){
            d[v].parent = u;
            dfs(v);
            if(d[v].low >= d[u].start) d[u].pigeon++;
            d[u].low = min(d[u].low, d[v].low);
            dfs_children++;
        }
        else if(d[u].parent != v){
            d[u].low = min(d[u].low, d[v].start);
        }
    }
    if(d[u].parent == -1) d[u].pigeon = dfs_children - 1;
}

int main(){
    while(~scanf("%d %d", &n, &m), n){
        for(auto &vec : g) vec.clear();
        for(int i = 0; i < n; i++)
            d[i] = (helper) {i, 1, -1, -1, -1};
        t = 0;
        int u, v;
        while(~scanf("%d %d", &u, &v), u != -1){
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int root = 0; root < n; root++){
            if(d[root].start == -1){
                dfs(root);
            }
        }
        sort(d, d+n);
        for(int i = 0; i < m; i++){
            printf("%d %d\n", d[i].id, d[i].pigeon);
        } 
        printf("\n");
    }
}