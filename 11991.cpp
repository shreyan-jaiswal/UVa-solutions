#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int> > M;
    for(int i = 1; i <= n; i++){
        int v; cin >> v;
        M[v].push_back(i);
    }
    vector<int> output;
    while(m--){
        int k, v;
        cin >> k >> v;
        output.push_back(M.find(v) != M.end() && M[v].size() >= k ? M[v][k-1] : 0);
    }
    for(int o: output) cout << o << endl;
}