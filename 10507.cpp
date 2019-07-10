#include <vector>
#include <bitset>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    int m;
    string c;
    bitset<26> awake;
    vector<vector<int> > g(26);
    while(cin >> n){
        cin >> m;
        cin >> c;
        fill(g.begin(), g.end(), vector<int>());
        awake.reset();
        awake.set(c[0]-'A');
        awake.set(c[1]-'A');
        awake.set(c[2]-'A');
        while(m--){
            cin >> c;
            int a = c[0]-'A', b = c[1]-'A';
            g[a].push_back(b);
            g[b].push_back(a);
        }
        int years = 0;
        while(awake.count() < n){
            vector<int> update;
            for(int i = 0; i < 26; i++){
                if(awake[i]) continue;
                int awake_neighbors = 0;
                for(int j : g[i]){
                    if(awake[j]) awake_neighbors+=1;
                }
                if (awake_neighbors >= 3) update.push_back(i);
            }
            if(update.size() == 0){years = -1; break; }
            years++;
            for(int i : update) awake.set(i);
        }
        if(years == -1) cout << "THIS BRAIN NEVER WAKES UP\n";
        else cout << "WAKE UP IN, " << years << ", YEARS\n";
    }
}