#include <iostream>
#include <vector>
using namespace std;
typedef pair<int, int> ii;

int main(){
    int n, m;
    cin >> n >> m;
    //cout << "n = " << n << " m = " << m << endl;
    vector< vector<ii> > t(m+1);
    for(int i = 1; i <= n; i++){
        vector<int> nonzeros;
        int k; cin >> k;
        //cout << "k = " << k << endl;
        for(int kk = 0; kk < k; kk++){
            int j; cin >> j; nonzeros.push_back(j);
            //cout << "j = " << j << endl;
        }
        for(int kk = 0; kk < k; kk++){
            int v; cin >> v;
            //cout << "v = " << v << endl;
            t[nonzeros[kk]-1].push_back(make_pair(i, v));
        }
    }
    //cout << "debug 1 \n";
    for(int j = 0; j < m; j++){
        cout << t[j].size();
        for(ii p : t[j]) cout << " " << p.first;
        cout << endl;
        for(int kk = 0; kk < t[j].size(); kk++){
            cout << t[j][kk].second << (kk + 1 != t[j].size() ? " " : "\n");
        }

    }
}