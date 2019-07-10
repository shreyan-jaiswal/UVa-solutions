#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int t, n, k;
bitset<105> noblack;
vi sol, bestsol;
vvi g;
int blacks, bestblacks;

void printsol(){
    for(int i = 0; i < sol.size(); i++){
        if(i) printf(" ");
        printf("%d", sol[i]);
    } printf("\n");
}

void backtrack(int v){
    if(v == n){
        if(blacks > bestblacks){
            bestblacks = blacks;
            bestsol = sol;
        }
        return;
    }

    if(noblack[v]) {backtrack(v+1); return;}

    sol.push_back(v);
    noblack.set(v);
    for(auto w : g[v]) noblack.set(w);
    blacks++;
    backtrack(v + 1);

    sol.pop_back();
    noblack.reset(v);
    for(auto w : g[v]) noblack.reset(w);
    blacks--;
    backtrack(v + 1);
}


int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        g.clear(); g.resize(n);
        for(int i = 0; i < k; i++){
            int x,y;
            scanf("%d %d", &x, &y); x--; y--;
            g[x].push_back(y); g[y].push_back(x);
            noblack.reset();
            sol.clear();
            bestsol.clear();
            blacks = 0;
            bestblacks = 0;
            backtrack(0);
        }
        printf("%d\n", bestblacks);
        for(int i = 0; i < bestsol.size(); i++){
            if(i) printf(" ");
            printf("%d", bestsol[i]+1);
        }
        printf("\n");
    }
}