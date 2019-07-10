#include <cstdio>
#include <algorithm>
#include <iterator>
using namespace std;

int n, m, l, u, q;
int H[505][505];

int main(){
    while(~scanf("%d %d", &n, &m) && n){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                scanf("%d", &H[i][j]);
            }
        scanf("%d", &q);
        while(q--){
            scanf("%d %d", &l, &u);
            int res = 0;
            for(int n1 = 0; n1 + 1 < max(n, m); n1++){
                int m1 = lower_bound(H[n1], H[n1]+m, l) - H[n1];
                if(m1 == m || H[n1][m1] > u) continue;

                int max_s = min(m - m1, n - n1);
                int s;
                for(s = 1; s <= max_s; s++){
                    if(s == max_s || H[n1+s][m1+s] > u) break;
                }
                res = max(s, res);
            }
            printf("%d\n", res);
        }

        printf("-\n");
    }
}