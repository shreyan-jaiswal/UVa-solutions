#include <cstdio>
using namespace std;
typedef long long integer;

integer total, coins[1005];
int n, res, t;

int main(){
    scanf("%d", &t);
    while(~scanf("%d", &n)){
        for(int c = 0; c < n; c++) scanf("%lld", &coins[c]);
        res = 0; total = 0;
        for(int c = 0; c < n; c++){
            if(c == n-1 || total + coins[c] < coins[c+1]){
                res++;
                total += coins[c];
            }
        }
        printf("%d\n", res);
    }
}
