#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 0x3f3f3f3f
#define watch(x) #x << "=" << x << ", "

int n, k;
string S;
vi T, tmp;
vector<vi> floors;
vector<vi> elevators(100);

int main(){
    while(cin >> n >> k){
        T.resize(n);
        for(int i = 0; i < n; i++) cin >> T[i];
        getline(cin, S);

        floors.clear(); floors.resize(n);
        for(auto &v : elevators) v.clear();
        for(int i = 0; i < n; i++){
            getline(cin, S);
            stringstream ss(S);
            tmp.clear();
            int x;
            while(ss >> x){
                floors[i].push_back(x);
                elevators[x].push_back(i);
            }
        }
        priority_queue<ii, vii, greater<ii>> q; q.push(ii(0,0));
        vector<int> dist(100, INF); dist[0] = 0;
        while(!q.empty()){
            int d, u; tie(d, u) = q.top(); q.pop();
            if(d > dist[u]) continue;
            for(int i : elevators[u]){
                for(int v : floors[i]){
                    int w = T[i] * abs(u-v) + (u == 0 ? 0 : 60);
                    if(dist[v] > d+w){
                        dist[v] = d+w;
                        q.push(ii(dist[v], v));
                    }
                }
            }
        }
        if(dist[k] >= INF) cout << "IMPOSSIBLE\n";
        else cout << dist[k] << "\n";
    }
}