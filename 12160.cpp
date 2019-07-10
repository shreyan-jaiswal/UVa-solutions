#include <bits/stdc++.h>
using namespace std;

int l, u, r, rv[10];

int madd(int a, int b){
    return a + b >= 10000 ? a+b-10000 : a+b;
}

int main(){
    int tc = 0;
    while(cin >> l >> u >> r, l || u || r){
        cout << "Case " << ++tc << ": ";
        if(l == u) {cout << "0\n"; continue; }
        for(int i = 0; i < r; i++){
            cin >> rv[i];
        }
        queue<pair<int, int>> q; q.push(make_pair(0, l));
        int vis[10000]; memset(vis, 0, sizeof vis); vis[l] = 1;
        while(!q.empty()){
            auto fr = q.front(); q.pop();
            int d = fr.first, x = fr.second;
            for(int i = 0; i < r; i++){
                int nx = madd(x, rv[i]);
                if(nx == u){
                    cout << d+1 << '\n';
                    goto LABEL;
                }
                if(!vis[nx]){
                    q.push(make_pair(d+1, nx));
                    vis[nx] = 1;
                }
            }
        }
        cout << "Permanently Locked\n";
        LABEL:;
    }
}