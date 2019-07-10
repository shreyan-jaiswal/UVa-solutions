#include <bitset>
#include <cstdio>
#include <vector>
using namespace std;
bool num[10][7] = {
    {1,1,1,1,1,1,0}, //0
    {0,1,1,0,0,0,0}, //1
    {1,1,0,1,1,0,1}, //2
    {1,1,1,1,0,0,1}, //3
    {0,1,1,0,0,1,1}, //4
    {1,0,1,1,0,1,1}, //5
    {1,0,1,1,1,1,1}, //6
    {1,1,1,0,0,0,0}, //7
    {1,1,1,1,1,1,1}, //8
    {1,1,1,1,0,1,1}  //9
};

bool A[10][7];
int n;
bitset<7> off;
bitset<7> on;

bool backtrack(int i, int d){
    printf("debug %d %d ", i, d);
    for(int j = 0; j < 7; j++) printf("%d", (int) off[j]); printf("\n");
    if(i == n) return true;
    for(int nd = d-1; nd >= 0; nd--){
        vector<int> turnoff;
        for(int j = 0; j < 7; j++){
            if(A[i][j] && (off[j] || !num[nd][j])) goto cnt;
            if(!A[i][j] && num[nd][j] && !off[j]){
                turnoff.push_back(j);
            }
        }
        for(int j : turnoff) if(on[j]) goto cnt;
        for(int j : turnoff) off.set(j);
        if(backtrack(i+1, nd)) return true;
        for(int j : turnoff) off.reset(j);
        cnt:;
    }
    return false;
}

int main(){
    int cn = 0;
    while(scanf("%d\n", &n), n){
        ++cn;
        for(int i = 0; i < n; i++){
            char x;
            for(int j = 0; j < 7; j++) {scanf("%c", &x); A[i][j] = (x == 'Y');}
            scanf("\n");
        }
        off.reset(); on.reset();
        if(backtrack(0, 10)) printf("MATCH\n");
        else printf("MISMATCH\n");
        if(cn == 83){
            printf("%d\n", n);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < 7; j++) printf(A[i][j] ? "Y" : "N");
                printf("\n");
            }
        }
    }
}