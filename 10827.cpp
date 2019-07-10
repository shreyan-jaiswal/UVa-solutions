#include <cstdio>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;

int t, a[100][100], prefix[100][100], n;

int get_rect(int i1, int j1, int i2, int j2){
    if (i1 > i2)
        return get_rect(i1, j1, n, j2) + get_rect(1, j1, i2, j2);
    if (j1 > j2)
        return get_rect(i1, j1, i2, n) + get_rect(i1, 1, i2, j2);
    return prefix[i2][j2] - prefix[i1-1][j2] - prefix[i2][j1-1] + prefix[i1-1][j1-1];
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            for(int j =1; j <= n; j++)
                scanf("%d", &(a[i][j]));
        
        memset(prefix, 0, sizeof prefix);
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                prefix[i][j] = a[i][j] + prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
        
        int ans = INT_MIN;
        for(int i1 = 1; i1 <= n; i1++)
            for(int j1 = 1; j1 <= n; j1++)
                for(int i2 = 1; i2 <= n; i2++)
                    for(int j2 = 1; j2 <= n; j2++)
                        ans = max(ans, get_rect(i1, j1, i2, j2));

        printf("%d\n", ans);
    }
}