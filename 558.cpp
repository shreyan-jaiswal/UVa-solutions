#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int tcs, n, m;

int main(){
    cin >> tcs;
    while(tcs--){
        cin >> n >> m;
        vector<vii> g(n);
        while(m--){
            int x, y, t;
            cin >> x >> y >> t;
            g[x].push_back(ii(y,t));
        }
        vi dist(n, INF); dist[0] = 0;
        for(int i = 0; i < n-1; i++){
            for(int u = 0; u < n; u++){
                for(auto v : g[u]){
                    dist[v.first] = min(dist[v.first], v.second + dist[u]);
                }
            }
        }
        bool neg_cycle = false;
        for(int u = 0; u < n; u++){
            for(auto v : g[u]){
                if(dist[v.first] > v.second + dist[u]){
                    neg_cycle = true;
                }
            }
        }
        cout << (neg_cycle ? "possible\n" : "not possible\n");
    }
}