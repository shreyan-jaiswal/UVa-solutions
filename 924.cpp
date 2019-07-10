#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
int e, n, t, vis[2500], boomsize[2500];
vector<int> g[2500];

int main(){
    cin >> e;
    for(int i = 0; i < e; i++){
        cin >> n;
        while(n--){
            int j; cin >> j;
            g[i].push_back(j);
        }
    }
    cin >> t;
    while(t--){
        int u, mdbs=0, fbd=0;
        cin >> u;
        queue<int> q; q.push(u);
        vector<int> d(e, INF); d[u] = 0;
        vector<int> bs(e, 0);
        while(!q.empty()){
            int u1 = q.front(); q.pop();
            for(int v : g[u1]){
                if(d[v] == INF) {
                    d[v] = d[u1]+1;
                    bs[d[v]]++;
                    q.push(v);
                }
            }
        }

        for(int i = 1; i < e; i++){
            if(bs[i] > mdbs){
                mdbs = bs[i];
                fbd = i;
            }
        }

        if(fbd == 0) cout << "0\n";
        else cout << mdbs << " " << fbd << '\n';
    }
}