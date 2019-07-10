#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int n, A[1005], m, q, ans;
    while(scanf("%d", &n), n){
        for(int i = 0; i < n; i++) scanf("%d", &A[i]);
        ans = A[0] + A[1];
        scanf("%d", &m);
        while(m--){
            scanf("%d", &q);
            for(int i = 0; i < n; i++)
                for(int j = 0; j < i; j++)
                    if(abs(q-ans) > abs(q-A[i]-A[j]))
                        ans = A[i] + A[j];
            printf("%d\n", ans);
        }
    }
}