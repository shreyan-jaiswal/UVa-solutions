#include <cstdio>
using namespace std;

long rw, d1, d2; //bitsets
int N = 8;
int row[14];

void backtrack(int c){
    if(c==N){
        printf("{");
        for(int i = 0; i < N; i++){
            printf("%d", row[i]+1);
            if(i != N-1) printf(",");
        }
        printf("},\n");
        return;
    }
    for(int r = 0; r < N; r++){
        if( ((rw & (1 << r)) | (d1 & (1 << (N-1+r-c))) | (d2 & (1 << (r+c)))) == 0){
            rw |= (1 << r); d1 |= (1 << (N-1+r-c)); d2 |= (1 << (r+c));
            row[c] = r; backtrack(c+1);
            rw &= ~(1 << r); d1 &= ~(1 << (N-1+r-c)); d2 &= ~(1 << (r+c));
        }
    }
}

int main(){
    backtrack(0);
}