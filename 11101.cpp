#include <bits/stdc++.h>
using namespace std;
#define watch(x) #x << "=" << x << ", "

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int p1, p2, dest[2001][2001], vis[2001][2001],x,y;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(){
    while(cin >> p1, p1){
        queue<iii> q; memset(vis, 0, sizeof vis);
        for(int i = 0; i < p1; i++){
            cin >> x >> y;
            q.push(iii(0,ii(x,y)));
            vis[x][y] = 1;
        }
        cin >> p2;
        memset(dest, 0, sizeof dest);
        for(int i = 0;i < p2; i++){
            cin >> x >> y;
            dest[x][y] = 1;
        }
        while(!q.empty()){
            iii fr = q.front(); q.pop();
            int d = fr.first, x = fr.second.first, y = fr.second.second;
            if(dest[x][y]){
                cout << d << '\n';
                break;
            }
            for(int dir = 0; dir < 4; dir++){
                int nx = x+dx[dir], ny = y+dy[dir];
                if(0 <= nx && nx <= 2000 && 0 <= ny && ny <= 2000 && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    q.push(iii(d+1, ii(nx, ny)));
                }
            }
        }
    }
}