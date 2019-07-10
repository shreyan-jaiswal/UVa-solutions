#include <cstdio>

using namespace std;

int main(){
    int A[1005], t, n, ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", A+i);
            for(int j = 0; j < i; j++){
                if(A[j] <= A[i]) ans++;
            }
        }
        printf("%d\n", ans);
    }
    
}