#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int t, n;
vi bck[50010];
int fwd[50010], visited[50010], dp[50010], depth[50100];

int UNVISITED = 0;
int VISITING = 1;
int VISITED = 2;

void traverse_forward(int i, int dep){
    if(visited[i] == VISITING){
        dp[i] = dep - depth[i];
        visited[i] = VISITED;
        for(int j = fwd[i]; j != i; j = fwd[j]){
            visited[j] = VISITED;
            dp[j] = dp[i];
        }
    }
    else if(visited[i] == UNVISITED){
        visited[i] = VISITING;
        depth[i] = dep;
        traverse_forward(fwd[i], dep+1);
        if(visited[i] != VISITED) dp[i] = dp[fwd[i]] + 1;
        visited[i] = VISITED;
    }

}

int main(){
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++) bck[i].clear();
        memset(visited, 0, sizeof visited);
        memset(dp, 0, sizeof dp);
        memset(depth, 0, sizeof depth);
        for(int i = 0; i < n; i++){
            int u, v;
            scanf("%d %d", &u, &v); u--; v--;
            fwd[u] = v;
            bck[v].push_back(u);
        }
        for(int i = 0; i < n; i++)
            traverse_forward(i, 1);
        int res = 0;
        for(int i = 0; i < n; i++)
            if(dp[i] > dp[res])
                res = i;
        printf("Case %d: %d\n", tc, res+1);
    }
}