#include <bits/stdc++.h>
using namespace std;

int n, s, p;
vector<pair<int, pair<int, int>>> edges;
complex<int> coords[101];

struct UFDS{
    vector<int> p, h;
    UFDS(int n){
        p.assign(n, 0);
        for(int i = 0; i < n; i++) p[i] = i;
        h.assign(n, 0);
    }
    int parent(int i){ return p[i]==i ? i : p[i] = parent(p[i]); }
    void join(int i, int j){
        int x = parent(i), y = parent(j);
        if(h[x] < h[y]){
            p[x] = y;
        } else {
            if(h[x] == h[y]) h[x]++;
            p[y] = x;
        }
    }
};

int main(){
    cin >> n;
    while(n--){
        cin >> s >> p;
        edges.clear();
        for(int i = 0; i < p; i++){
            int re, im;
            cin >> re >> im;
            coords[i] = {re, im};
        }
        for(int i = 0; i < p; i++){
            for(int j = i+1; j < p; j++){
                edges.push_back(make_pair(norm(coords[i]-coords[j]), make_pair(i, j)));
            }
        }
        sort(edges.begin(), edges.end());
        UFDS uf = UFDS(p);
        int d2 = 0;
        int mstsize = 0;
        for(auto e : edges){
            int w = e.first, u = e.second.first, v = e.second.second;
            if(uf.parent(u) != uf.parent(v)){
                uf.join(u,v);
                d2 = max(d2, w);
                mstsize++;
                if(mstsize + s  == p ) break;
            }

        }
        printf("%.2lf\n", sqrt(d2));
    }
}