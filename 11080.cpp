#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> g[205];
int c[205], v, e, m, t;

int bfs(int s){
    queue<int> q;
    int tot[2] = {1,0};
    q.push(s);
    c[s] = 0;
    while(!q.empty()){
        int i = q.front(); q.pop();
        for(int j : g[i]){
            if(c[j] == -1){
                q.push(j);
                tot[c[j] = 1 - c[i]]++;
            }
            else if(c[i] == c[j]){
                return -1;
            }
        }
    }
    return min(tot[0], tot[1]);
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &v, &e);
        for(auto vec : g) vec.clear();
        memset(c, -1, sizeof c);
        while(e--){
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ret = 0;
        for(int i = 0; i < v; i++){
            if(c[i] == -1){
                int tmp = bfs(i);
                if(tmp == -1){
                    printf("-1\n");
                    goto LABEL;
                }
                else ret+=tmp;
            }
        }
        printf("%d\n", ret);
        LABEL:;
    }
}