#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<int> vi;

vi dfs_num, dfs_low, dfs_parent, g[105];
vector<bool> articulation_point;
int n, dfs_counter, dfs_root_children, dfs_root;

void dfs(int u){
    dfs_num[u] = dfs_low[u] = dfs_counter++;
    for(int v : g[u]){
        if(dfs_num[v] == -1){
            dfs_parent[v] = u;
            if(u == dfs_root) dfs_root_children++;
            dfs(v);
            if(dfs_low[v] >= dfs_num[u]){
                articulation_point[u] = true;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(dfs_num[v] != dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main(){
    string tmp;
    while(cin >> n, n){
        getline(cin, tmp);
        dfs_num.assign(n, -1); dfs_low.assign(n, -1); dfs_parent.assign(n, -1); articulation_point.assign(n, false);
        for(auto &v : g) v.clear();
        dfs_counter = 0;
        while(1){
            getline(cin, tmp);
            stringstream ss(tmp);
            int u; ss >> u;
            if(u == 0) break;
            u--;
            int v;
            while(ss >> v){
                v--;
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        for(int i =0;i < n; i++){
            if(dfs_num[i] == -1){
                dfs_root = i;
                dfs_root_children = 0;
                dfs(i);
                articulation_point[i] = dfs_root_children > 1;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(articulation_point[i]) ans++;
        } cout << ans << "\n";
    }
}