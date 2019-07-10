#include <iostream>
#include <cstring>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

pair<int, double> dp[8][258];
int n;
int x[8], y[8];

double sqr(int x) {return ((double) (x)) * ((double) (x));}

double dist(int i, int j){
    return 16.+sqrt(sqr(x[j]-x[i]) + sqr(y[j]-y[i]));
}

pair<int, double> solve(int pos, int mask){
    if(mask == (1 << n) - 1) return dp[pos][mask] = make_pair(pos, 0.);
    pair<int, double> ans = make_pair(-1, 300000.);
    for(int nxt = 0; nxt < n; nxt++){
        if((mask & (1 << nxt)) == 0){
            double tmp = dist(pos, nxt) + solve(nxt, mask | (1 << nxt)).second;
            if(tmp < ans.second){
                ans.first = nxt;
                ans.second = tmp;
            }
        }
    }
    return dp[pos][mask] = ans;
}

int main(){
    while(cin >> n, n){
        for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 258; j++)
                dp[i][j] = make_pair(-1, -1.);
        double out = 30000.;
        int besti = -1;
        for(int i = 0; i < n; i++){
            double tmp = solve(i, 1<< i).second;
            if(out > tmp){
                out = tmp;
                besti = i;
            }
        }
        int curr = besti;
        int mask = 1 << curr;
        int next = dp[curr][mask].first;
        while(curr != next){
            cout << curr << " " << next << " " << dist(curr, next) << endl;
            curr = next;
            mask |= 1 << curr;
            next = dp[curr][mask].first;
        }
        cout << out << endl;
    }
}