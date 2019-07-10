#include <bits/stdc++.h>
using namespace std;

int m, n, b, e;
string s1, s2, s3;
map<string, int> lang_idx;
vector<string> words;
vector<pair<int, int>> word_langs;
vector<int> words_in_start_lang, words_in_finish_lang;
vector<vector<pair<int, int>>> g;

int idx(string s){
    if(lang_idx.count(s)) return lang_idx[s];
    else return lang_idx[s] = n++;
}

int main(){
    while(cin >> m, m){
        n = 0; lang_idx.clear(); words.resize(m); word_langs.resize(m); 
        words_in_start_lang.clear(); words_in_finish_lang.clear();
        cin >> s1 >> s2;
        b = idx(s1), e = idx(s2); // (b, e) = (0, 1)
        for(int i = 0; i < m; i++){
            cin >> s1 >> s2 >> s3;
            int x = idx(s1), y = idx(s2);
            word_langs[i] = make_pair(x, y);
            if(x == b || y == b) words_in_start_lang.push_back(i);
            if(x == e || y == e) words_in_finish_lang.push_back(i);
            words[i] = s3;
        }
        g.clear(); g.resize(m+2);
        for(int i = 0; i < m; i++){
            for(int j = i+1; j < m; j++){
                int xi = word_langs[i].first, yi = word_langs[i].second, xj = word_langs[j].first, yj = word_langs[j].second;
                if( (xi == xj || xi == yj || yi == xj || yi == yj) && (words[i][0] != words[j][0]) ){
                    g[i].push_back(make_pair(j, words[i].size()));
                    g[j].push_back(make_pair(i, words[j].size()));
                }
            }
        }
        int source = m, sink = m+1;
        for(int i : words_in_start_lang)
            g[source].push_back(make_pair(i, 0));
        for(int i : words_in_finish_lang)
            g[i].push_back(make_pair(sink, words[i].size()));

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, source));
        vector<int> dist(m+2, 0x3f3f3f3f); dist[source] = 0;
        while(!pq.empty()){
            int d = pq.top().first, u = pq.top().second; pq.pop();
            if(d > dist[u]) continue;
            for(pair<int, int> ne : g[u]){
                int v = ne.first, w = ne.second;
                if(dist[v] > d + w){
                    dist[v] = d + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        if(dist[sink] >= 0x3f3f3f3f) cout << "impossivel\n";
        else cout << dist[sink] << "\n";
    }
}