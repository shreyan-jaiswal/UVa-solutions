#include <cstdio>
using namespace std;
int main(){
    int A[20], t, n, p;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%d", &p);
        for(int i = 0; i < p; i++) scanf("%d", A+i);
        for(int s = 0; s < (1<<p); s++){
            int sum = 0;
            for(int i = 0; i < p; i++) if(s & (1<<i)) sum+=A[i];
            if(sum == n) {printf("YES\n"); goto cnt;}
        }
        printf("NO\n");
        cnt:;
    }
}