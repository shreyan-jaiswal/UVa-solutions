#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<int> vi;

int main(){
    map<vi, int> m;
    int n;

    while(cin >> n, n){
        m.clear();
        for(int i = 0; i < n; i++){
            vi c(5);
            for(int j = 0; j < 5; j++) cin >> c[j];
            sort(c.begin(), c.end());
            m[c]++;
        }
        
        map<int, int> m2;
        int maxval= 0;
        for(map<vi, int>::iterator it = m.begin(); it != m.end(); ++it){
            maxval = max(maxval, it->second);
            m2[it->second]++;
        }
        cout << maxval * m2[maxval] << endl;
    }
}