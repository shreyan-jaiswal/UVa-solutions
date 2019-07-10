#include <iostream>
#include <set>

using namespace std;

int main(){
    int n;
    while(cin >> n, n){
        int total = 0;
        multiset<int> s;
        for(int i = 0; i < n; i++){
            int k, x;
            cin >> k;
            while(k--) {cin >> x; s.insert(x); }
            total += *(--s.end()) - *(s.begin());
            s.erase(--s.end()); s.erase(s.begin());
        }
        cout << total << endl;
    }
}