#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string candidates, query;
    int q;

    vector<int> idxs[150];
    getline(cin, candidates);

    for(int i = 0; i < candidates.size(); i++){
        idxs[candidates[i]].push_back(i);
    }
    
    cin >> q;
    getline(cin, query);

    while(q--){
        getline(cin, query);
        int i = -1; int start;
        for(char c : query){
            auto lb = upper_bound(idxs[c].begin(), idxs[c].end(), i);
            if(lb == idxs[c].end()) {printf("Not matched\n"); goto cnt;}
            if(i == -1) start = *lb;
            i = *lb;
        }
        printf("Matched %d %d\n", start, i);
        cnt:;
    }
}
