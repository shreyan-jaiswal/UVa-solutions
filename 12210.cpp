#include <cstdio>
#include <algorithm>
using namespace std;

int B, S, yb, tmp, tc;

int main(){
    tc = 1;
    while(scanf("%d %d", &B, &S), B+S){
        yb = 0x7fffffff;
        for(int i = 0; i < B; i++){
            scanf("%d", &tmp); yb = min(yb, tmp);
        }
        for(int i = 0; i < S; i++) scanf("%d", &tmp);
        if(B > S)
            printf("Case %d: %d %d\n", tc++, B-S, yb);
        else
        {
            printf("Case %d: 0\n", tc++);
        }
        
    }
}