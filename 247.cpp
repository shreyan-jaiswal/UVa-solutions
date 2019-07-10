#include <bits/stdc++.h>
using namespace std;

struct helper {
    int num, low, vis;
} d[26];
vector<int> s, g[26];
int n, m, t;
map<string, int> idx;
string name[26];

void scc(int u){
    d[u].num = d[u].low = t++;
    s.push_back(u);
    d[u].vis = 1;
    for(int v : g[u]){
        if(d[v].num == -1) scc(v);
        if(d[v].vis) d[u].low = min(d[u].low, d[v].low);
    }
    if(d[u].low == d[u].num){
        while(1){
            int v = s.back(); s.pop_back(); d[v].vis = 0;
            if(u == v){
                cout << name[v] << "\n";
                break;
            }
            cout << name[v] << ", ";
        }  
    } 
}

int main(){
    string from, to;
    int tc = 0;
    while(cin >> n >> m, n){
        for(auto &v : g) v.clear();
        idx.clear();
        int i = 0;
        while(m--){
            cin >> from >> to;
            if(idx.count(from) == 0) {idx[from] = i; name[i] = from; i++; }
            if(idx.count(to) == 0) {idx[to] = i; name[i] = to; i++; }
            g[idx[from]].push_back(idx[to]); }
        for(int i = 0; i < n; i++) d[i] = {-1, -1, 0};
        t = 0;
        cout << "Calling circles for data set " << ++tc << ":\n";
        for(int i = 0; i < n; i++){
            if(d[i].num == -1)
                scc(i);
        }
        cout << "\n";
    }
}