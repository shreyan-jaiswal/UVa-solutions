#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct payment {
    int coins;
    int value;
};

int t, n, s, c[101];
payment dp[101][10500];

payment backtrack(int i, int m){
    if(m >= s){ return {0, m}; }
    if(i == n){ return {-1, 1000000000}; }
    if(dp[i][m].coins != -1) return dp[i][m];
    payment ans = {-1, 1000000000}; 
    payment tmp;
    for(int j = 0; m + (j-1)*c[i] <= s; j++){
        tmp = backtrack(i + 1, m + j * c[i]);
        if(tmp.value < ans.value || (tmp.value == ans.value && tmp.coins < ans.coins)){
            ans.coins = tmp.coins + j;
            ans.value = tmp.value;
        }
    }
    return dp[i][m] = ans;
}

int main(){
    cin >> t;
    while(t--){
        cin >> s >> n;
        for(int i = 0; i < n; i++) cin >> c[i];
        sort(c, c+n, greater<int>());
        memset(dp, -1, sizeof dp);
        payment out = backtrack(0,0);
        printf("%d %d\n", out.value, out.coins);
    }
}