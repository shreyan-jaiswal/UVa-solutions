#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, d[20020], k[20020];

int main(){
    while(scanf("%d %d", &n, &m), n){
        for(int i = 0; i < n; i++) scanf("%d", d+i);
        for(int i = 0; i < m; i++) scanf("%d", k+i);
        sort(d, d+n);
        sort(k, k+m);
        int cost = 0;
        int di = 0, ki = 0;
        while(di < n && ki < m){
            if(d[di] <= k[ki]){
                cost += k[ki];
                di++; ki++;
            }
            else{
                ki++;
            }
        }
        if(di == n){
            printf("%d\n", cost);
        }
        else{
            printf("Loowater is doomed!\n");
        }
    }
}