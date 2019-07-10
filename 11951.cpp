#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long integer;

integer p[105][105], k, tmp, price, bp;
int t, n, m, ba, a;

int get_rect(int i1, int j1, int i2, int j2){
    i1--; j1--;
    return p[i2][j2] - p[i2][j1] - p[i1][j2] + p[i1][j1];
}

int main(){
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d %d %lld", &n, &m, &k);
        memset(p, 0, sizeof p);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++){
                scanf("%lld", &tmp);
                p[i][j] = tmp + p[i-1][j] + p[i][j-1] - p[i-1][j-1];
            }
        ba = 0;
        bp = 0;
        for(int i1 = 1; i1 <= n; i1++)
            for(int i2 = i1; i2 <= n; i2++){
                int j2 = 1;
                for(int j1 = 1; j1 <= m; j1++){
                    if(j2 < j1) j2 = j1;
                    while(get_rect(i1, j1, i2, j2) <= k && j2 <= m) j2++;
                    j2--;
                    a = (i2-i1+1) * (j2-j1+1);
                    price = get_rect(i1, j1, i2, j2);
                    if(a > ba || (a == ba && price < bp)){
                        bp = price;
                        ba = a;
                    }
                }
            }
        
        printf("Case #%d: %d %lld\n", tc, ba, bp);

    }
}

