#include <cstdio>
using namespace std;

int t, n, sc;
char f[105];

int main(){
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d", &n);
        scanf("%s", f);
        sc = 0;
        for(int i = 1; i < n; i++){
            if(f[i-1] == '.' || (i == n-1 && f[i] == '.')){
                f[i-1] = f[i] = f[i+1] = '#';
                sc++;
            }
        }
        printf("Case %d: %d\n", tc, sc);
    }
}