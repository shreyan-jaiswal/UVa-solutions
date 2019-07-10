#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int c[101][101];

int main(){
    int u, v, tc=0;
    cin >> u >> v;
    while(u && v){
        cout << "Case " << ++tc << ": average length between pages = ";
        memset(c, 0x3f, sizeof c);
        set<int> nodes;
        while(u && v){
            nodes.insert(u); nodes.insert(v);
            c[u][v] = 1;
            cin >> u >> v;
        }
        for(int k : nodes)
            for(int i : nodes)
                for(int j : nodes)
                    c[i][j] = min(c[i][j], c[i][k] + c[k][j]);

        int sum = 0;    
        for(int i : nodes)
            for(int j : nodes)
                if(i != j) sum += c[i][j];
        printf("%.3lf clicks\n", (double) sum / (nodes.size() * (nodes.size()-1)));
        cin >> u >> v;
    }
}