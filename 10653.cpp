#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
typedef vector<int> vi;

int R, C, bomb[1000][1000], d[1000][1000];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int main(){
    while(cin >> R >> C, R){
        memset(bomb, 0, sizeof bomb);
        int rows; cin >> rows;
        while(rows--){
            int i; cin >> i;
            int m; cin >> m;
            while(m--){
                int j; cin >> j;
                bomb[i][j] = 1;
            }
        }
        int si, sj, di, dj;
        cin >> si >> sj >> di >> dj;
        memset(d, 0x3f, sizeof d); d[si][sj] = 0;
        queue<pair<int, int>> q; q.push(make_pair(si, sj));
        while(!q.empty()){
            int i = q.front().first, j = q.front().second; q.pop();
            for(int dir = 0; dir < 4; dir++){
                int ip = i + dr[dir], jp = j + dc[dir];
                if(0 <= ip && ip < R && 0 <= jp && jp < C && !bomb[ip][jp] && d[ip][jp] == INF){
                    d[ip][jp] = 1 + d[i][j];
                    q.push(make_pair(ip, jp));
                }
            }
        }
        cout << d[di][dj] << "\n";
    }
}