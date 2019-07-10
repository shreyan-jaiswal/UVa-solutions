#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
typedef vector<int> vi;

class UFDS {
public:
    vi p, sizes, heights;
    int numSets;
    UFDS(int N){
        p.assign(N, 0); for(int i = 0; i < N; i++) p[i]=i;
        sizes.assign(N, 1);
        heights.assign(N, 0);
        numSets = N;
    }

    int findSet(int i){
        return (p[i]==i ? i : p[i] = findSet(p[i]));
    }

    void unionSet(int i, int j){
        int x = findSet(i);
        int y = findSet(j);
        if (x==y) return;
        numSets--;
        if(heights[x] > heights[y]){
            p[y]=x;
            sizes[x] += sizes[y];
        }
        else {
            p[x] = y;
            sizes[y] += sizes[x];
            if(heights[x] == heights[y]) heights[x]++;
        }
    }

    int sizeOf(int i){
        return sizes[findSet(i)];
    }
    int numDiscreteSets(){return numSets;}
};

void print(vi const &input){
    if(input.size() == 0) return;
    cout << input[0];
    for(int i = 1; i < input.size(); i++){
        cout << " " << input[i];
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int f; cin >> f;
        UFDS u = UFDS(2*f + 5);
        unordered_map<string, int> m;
        int next = 0;
        while(f--){
            string x, y;
            cin >> x >> y;
            if(m.find(x) == m.end()) {m[x] = next; next++; }
            if(m.find(y) == m.end()) {m[y] = next; next++; }
            u.unionSet(m[x], m[y]);
            cout << u.sizeOf(m[x]) << endl;
        }
    }
}
