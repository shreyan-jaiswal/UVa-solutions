#include <cstdio>
using namespace std;

char grid[26][26];

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int m, n, x, y;

int floodfill(int i, int j){
    int ans = 1;
    grid[i][j] = 'w';
    for(int dir = 0; dir < 4; dir++){
        int ip = i + dr[dir], jp = j + dc[dir];
        if(0 <= ip && ip < m && 0 <= jp && jp < n && grid[ip][jp] == 'l') ans += floodfill(ip, jp);
    }
    return ans;
}

int main(){
    while(~scanf("%d %d", &m, &n)){
        for(int i = 0; i < m; i++)
            scanf("%s", grid[i]);
        scanf("%d %d\n", &x, &y);
        int ret = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'w') continue;
                bool ignore = grid[x][y] == 'l';
                int tmp = floodfill(i, j);
                ignore &= grid[x][y] == 'w';
                if(tmp > ret && !ignore) ret = tmp;
            }
        }
        printf("%d\n", ret);
    }
}