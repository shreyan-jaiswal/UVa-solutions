#include <cstdio>
#include <algorithm>
using namespace std;

int x, tmp, ans, n;

int main(){
    while(scanf("%d", &n), n){
        tmp = ans = 0;
        while(n--){
            scanf("%d", &x);
            tmp = max(0, tmp + x);
            ans = max(ans, tmp);
        }
        if(ans) printf("The maximum winning streak is %d.\n", ans);
        else printf("Losing streak.\n");
    }
}