#include <bits/stdc++.h>
using namespace std;
#define watch(x) cerr << #x << "=" << x << ", "

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<iii> viii;

viii es;
int n, m, x, y, z;

struct UFDS{
    vi p, h;
    UFDS(int n){
        p.assign(n, 0); for(int i = 0; i < n; i++) p[i] = i;
        h.assign(n, 0);
    }
    int parent(int i){
        return p[i] == i ? i : p[i] = parent(p[i]);
    }
    void join(int i, int j){
        int x = parent(i), y = parent(j);
        if(x != y){
            if(h[x] > h[y]){
                p[y] = x;
            } else{
                if(h[x] == h[y]) h[y]++;
                p[x] = y;
            }
        }
    }
};

int main(){
    while(cin >> n >> m, n){
        while(m--){
            cin >> x >> y >> z;
            es.push_back(make_pair(z, make_pair(x, y)));
        }
        sort(es.begin(), es.end());
        UFDS uf = UFDS(n);
        int mst_cost = 0;
        int total_cost = 0;
        for(auto e : es){
            z = e.first; x = e.second.first; y = e.second.second;
            if(uf.parent(x) != uf.parent(y)){
                uf.join(x, y);
                mst_cost += z;
            }
            total_cost += z;
        }
        cout << total_cost - mst_cost << "\n";
    }
}
