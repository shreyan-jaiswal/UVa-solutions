#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

int findParent(int n, vector<int> &p, vector<int> &depth, int i){
    return p[i] == i ? i : p[i] = findParent(n, p, depth, p[i]);
}

void join(int n, vector<int> &p, vector<int> &depth, int i, int j){
    int x = findParent(n, p, depth, i), y = findParent(n, p, depth, j);
    if (depth[x] < depth[y]) {
        p[x] = y;
    }
    else{
        if(depth[x] == depth[y]) depth[x]++;
        p[y] = x;
    }
}

int main(){
    int t; cin >> t;
    while(t--){
        string s;
        int n, yes = 0, no = 0; cin >> n; getline(cin, s);
        vector<int> p(n+1, 0);
        for(int i = 1; i <= n; i++) p[i] = i;
        vector<int> depth(n+1,0);
        while(getline(cin, s), s!=""){
            stringstream ss(s);
            char type; int i,j;
            ss >> type >> i >> j;
            if(type == 'c') join(n, p, depth, i, j);
            else findParent(n, p, depth, i) == findParent(n, p, depth, j) ? yes++ : no++;
        }
        cout << yes << "," << no;
        if(t!=0) cout << endl;
    }
}

