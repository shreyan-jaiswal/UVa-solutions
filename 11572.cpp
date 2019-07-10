#include <map>
#include <iostream>
using namespace std;

int main(){
    int t, n, mx, sf, currstreak;
    map<int, int> prev;
    
    cin >> t;
    while (t--){
        prev.clear();
        cin >> n;
        mx = 0;
        currstreak = 0;
        for(int i = 1; i <= n; i++){
            cin >> sf;
            currstreak = min(currstreak + 1, i - prev[sf]);
            mx = max(mx, currstreak);
            prev[sf] = i;
        }
        cout << mx << endl;
    }
}