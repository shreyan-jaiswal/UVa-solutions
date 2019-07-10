#include <cstdio>
using namespace std;

char grid[101][101];
int n, t;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int fill(int i, int j){
    int ans = grid[i][j] == 'x' ? 1 : 0;
    grid[i][j] = '.';
    for(int d = 0; d < 4; d++){
        int k = i + dr[d];
        int l = j + dc[d];
        if(0<=k && k<n && 0<=l && l<n && grid[k][l]!='.'){
            ans += fill(k, l);
        }
    }
    return ans;
}

int main(){
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%s", grid[i]);
        int ret = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] != '.')
                    ret += fill(i,j) > 0 ? 1 : 0;
        printf("Case %d: %d\n", tc, ret);
    }
}