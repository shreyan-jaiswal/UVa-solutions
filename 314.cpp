#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define watch(x) cerr << #x << " " << x << endl
int M, N, obs[50][50], d[50][50][4];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
map<string, int> directions = {{"north", 0}, {"east", 1}, {"south", 2}, {"west", 3}};

int main(){
    cin >> M >> N;
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            cin >> obs[i][j];
    int bi, bj, ei, ej, bd;
    cin >> bi >> bj >> ei >> ej;
    string tmp; cin >> tmp; bd = directions[tmp];
    memset(d, 0x3f, sizeof d); d[bi][bj][bd] = 0;
    queue<tuple<int,int,int>> q; q.emplace(bi,bj,bd);
    while(!q.empty()){
        int i,j,dir;
        tie(i,j,dir) = q.front(); q.pop();
        for(int f = 1; f <= 3; f++){
            int ip = i+f*dr[dir], jp = j+f*dc[dir];
            if(ip >= 0 && ip < M-1 && jp >= 0 && jp < N-1 && !obs[ip][jp] && !obs[ip][jp-1] && !obs[ip-1][jp] && !obs[ip-1][jp-1]){
                if(d[ip][jp][dir] == INF){
                    d[ip][jp][dir] = d[i][j][dir] + 1;
                    if(ip == ei && jp == ej){
                        cout << d[ip][jp][dir] << '\n';
                        exit(0);
                    }
                    q.emplace(ip, jp, dir);
                }
            } else break;
        }
        if(d[i][j][(dir+1)%4] == INF){
            d[i][j][(dir+1)%4] = d[i][j][dir] + 1;
            q.emplace(i, j, (dir+1)%4);
        }
        if(d[i][j][(dir+3)%4] == INF){
            d[i][j][(dir+3)%4] = d[i][j][dir] + 1;
            q.emplace(i, j, (dir+3)%4);
        }
    }
    cout << "-1\n";
}