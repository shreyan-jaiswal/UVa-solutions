#include <bits/stdc++.h>
using namespace std;

string d[200], tmp;
map<string, int> idx;
vector<int> g[200];
int t, n, vis[200];

int main(){
    cin >> t; getline(cin, tmp); getline(cin, tmp);
    while(t--){
        n = 0;
        string tmp;
        idx.clear();
        while(getline(cin, tmp), tmp[0] != '*'){
            d[n] = tmp;
            idx[tmp] = n++;
        }
        for(auto &v : g) v.clear();
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(d[i].size() == d[j].size()){
                    int common = 0;
                    for(int k = 0; k < d[i].size(); k++) if(d[i][k] == d[j][k]) common++;
                    if(common + 1 >= d[i].size()){
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                }
            }
        }

        while(getline(cin, tmp)){
            stringstream ss(tmp);
            string s1, s2;
            ss >> s1 >> s2;
            int u = idx[s1], v = idx[s2];
            queue<pair<int, int>> q; q.push(make_pair(u, 0));
            memset(vis, 0, sizeof vis);
            while(!q.empty()){
                pair<int, int> front = q.front(); q.pop();
                if(front.first == v){
                    cout << s1 << " " << s2 << " " << front.second << '\n';
                    break;
                }
                for(int next : g[front.first]){
                    if(!vis[next]) q.push(make_pair(next, front.second+1));
                }
            }
        }
    }
}