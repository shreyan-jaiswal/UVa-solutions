#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<int> g[205];
int n, l, c[205];

int main(){
    while(~scanf("%d %d", &n, &l)){
        for(auto &v : g) v.clear();
        while(l--){
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
        }
        queue<int> q;
        q.push(0);
        memset(c, -1, sizeof c);
        c[0] = 0;
        while(!q.empty()){
            int i = q.front(); q.pop();
            for(int j : g[i]){
                if(c[j] == -1){
                    c[j] = 1 - c[i];
                    q.push(j);
                }
                else if(c[j] == c[i]){
                    goto LABEL;
                }
            }
        }
        printf("yes\n");
        continue;
        LABEL:;
        printf("no\n");
    }
}