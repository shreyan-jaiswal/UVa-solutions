#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    int n,m;
    while(cin >> n >> m, n + m){
        unordered_set<int> s1;
        int ret = 0;
        int x;
        while(n--){cin >> x; s1.insert(x); }
        while(m--){
            cin >> x;
            if (s1.find(x) != s1.end()) ret++;
        }
        cout << ret << endl;
    }
}