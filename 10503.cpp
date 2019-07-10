#include <cstdio>
using namespace std;

int i2, d1;
int D[14][2];
int used;
int n, m;

void backtrack(int i, int mat){
    if(i == n){
        if(mat == d1){printf("YES\n"); throw 0;}
        else return;
    }
    for(int d = 0; d < m; d++){
        if((used & (1 << d)) == 0){
            used |= (1 << d);
            if(mat == D[d][0]) backtrack(i + 1, D[d][1]);
            if(mat == D[d][1]) backtrack(i + 1, D[d][0]);
            used &= ~(1 << d);
        }
    }
}

int main(){
    while(scanf("%d %d %*d %d %d %*d", &n, &m, &i2, &d1), n){
        for(int d = 0; d < m; d++) scanf("%d %d", &D[d][0], &D[d][1]);
        used = 0;
        try{ backtrack(0, i2); printf("NO\n"); }
        catch (int e) {}
    }
}