#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

unordered_map<string, int> idx;
string strs[106];
set<int> g[105], G[105];
int n, m;

int main(){
    while(cin >> n){
        string tmp, tmp2;
        for(int i =0;i < n;i++){
            cin >> tmp;
            idx[tmp] = i;
            strs[i] = tmp;
        }
        for(auto &v : g) v.clear();
        for(auto &v : G) v.clear();
        scanf("%d", &m);
        while(m--){
            cin >> tmp >> tmp2;
            g[idx[tmp]].insert(idx[tmp2]);
            G[idx[tmp2]].insert(idx[tmp]);
        }

        priority_queue<int, vector<int>, greater<int> > S;
        vector<int> L;
        for(int i = 0; i < n; i++){
            if(G[i].empty()) S.push(i);
        }

        while(!S.empty()){
            int i = S.top(); S.pop();
            L.push_back(i);
            for(int j : g[i]){
                G[j].erase(i);
                if(G[j].empty()) S.push(j);
            }
            g[i].clear();
        }
        for(int i : L) printf("%s ", strs[i].c_str());
        printf("\n");

    }
}