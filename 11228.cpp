#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << #x << " = " << x << endl;
#define mp make_pair

typedef complex<int> ci;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

ci coords[1000];
priority_queue<pi> pq;
vi vis;
int t, n, r;

void process(int u){
    vis[u] = 1;
    for(int v = 0; v < n; v++)
        if(!vis[v])
            pq.push(mp(-norm(coords[v]-coords[u]), -v));
}

int main(){
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n >> r;
        for(int i = 0; i < n; i++){
            int re, im;
            cin >> re >> im;
            coords[i] = {re, im};
        }
        double rr_cost = 0.0;
        double r_cost = 0.0;
        vis.assign(n, 0);
        process(0);
        int cities = 1;
        while(!pq.empty()){
            pi top = pq.top(); pq.pop();
            int u = -top.second; int w = -top.first;
            if(!vis[u]){
                process(u);
                if(w > r * r) rr_cost += sqrt(w), cities++;
                else r_cost += sqrt(w);
            }
        }
        cout << "Case #" << tc << ": " << cities << " "  << (int) round(r_cost) << " " << (int) round(rr_cost) << "\n";
    }
}