#include <cstdio>
using namespace std;

int n, m, vessels[1005];

bool f(int k){
    int c = 0, filled = 0;
    for(int v = 0; v < n; v++){
        if(filled + vessels[v] <= k) filled += vessels[v];
        else if (vessels[v] <= k){ filled = vessels[v]; c++; }
        else return false;
        if(c >= m) return false;
    }
    return true;
}

int main(){
    while(~scanf("%d %d", &n, &m)){
        for(int i = 0; i < n; i++) scanf("%d", vessels+i);
        int hi = n * 1100000, lo = 0, mid;
        while(hi - lo > 0){
            mid = lo + (hi - lo) / 2;
            if(f(mid)) hi = mid;
            else lo = mid + 1;
        }
        printf("%d\n", lo);
    }
}