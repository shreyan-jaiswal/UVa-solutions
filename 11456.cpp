#include <cstdio>
#include <algorithm>
using namespace std;

int t, n, ans, a[2005], lis[2005], lds[2005];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", a+i);
        }
        for(int i = n-1; i>=0; i--){
            lis[i] = 1;
            lds[i] = 1;
            for(int j = i+1;j < n; j++){
                if(a[j] >= a[i])
                    lis[i] = max(lis[i], lis[j] + 1);
                if(a[j] <= a[i])
                    lds[i] = max(lds[i], lds[j] + 1);
            }
            ans = max(ans, lis[i] + lds[i] - 1);
            
        }
        printf("%d\n", ans);
    }
}