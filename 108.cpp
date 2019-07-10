#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

int n, a[105][105], prefix[105][105], tmp, ans, dpi[105][105], dpj[105][105];

int get_rect(int i1, int j1, int i2, int j2){
    return prefix[i2][j2] - prefix[i1-1][j2] - prefix[i2][j1-1] + prefix[i1][j1-1];
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j<= n; j++)
            scanf("%d", &(a[i][j]));

    memset(prefix, 0, sizeof prefix);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];

    ans = INT_MIN;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            tmp = a[i][j];
            dpi[i][j] = i;
            dpj[i][j] = j;

            if(i > 1 && get_rect(dpi[i-1][j], dpj[i-1][j], i, j) > tmp){
                tmp = get_rect(dpi[i-1][j], dpj[i-1][j], i, j);
                dpi[i][j] = dpi[i-1][j];
                dpj[i][j] = dpj[i-1][j];
            }

            if(j > 1 && get_rect(dpi[i][j-1], dpj[i][j-1], i, j) > tmp){
                tmp = get_rect(dpi[i][j-1], dpj[i][j-1], i, j);
                dpi[i][j] = dpi[i][j-1];
                dpj[i][j] = dpj[i][j-1];
            }

            ans = max(ans, tmp);
        }
    
    printf("%d\n", ans);
    
    
}