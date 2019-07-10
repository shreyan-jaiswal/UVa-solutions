#include <cstdio>
#include <cstring>
using namespace std;

int dp[40000][4];
int coinvals[4] = {25, 10, 5, 1};

int solve(int v, int c){
    if(c == 3) return 1;
    if(dp[v][c] != -1) return dp[v][c];
    int ret = 0;
    for(int i = 0; i <= v; i+=coinvals[c]) ret+=solve(v-i,c+1);
    return dp[v][c] = ret;
}

int main(){
    int v, out;
    while(~scanf("%d", &v)){
        memset(dp, -1, sizeof dp);
        out = solve(v, 0);
        if(out == 1) printf("There is only 1 way to produce %d cents change.\n", v);
        else printf("There are %d ways to produce %d cents change.\n", out, v);
    }
}