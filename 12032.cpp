#include <cstdio>
using namespace std;

int t, n, r[10007];

bool f(int k){
    for(int i = 0; i < n - 1; i++){
        if(r[i+1]-r[i] > k) return false;
        if(r[i+1]-r[i] == k) k--;
    }
    return true;
}

int main(){
    scanf("%d", &t);
    for(int tc = 1; tc <= t; tc++){
        scanf("%d", &n);
        for(int i =0;i < n; i++) scanf("%d", r+i);
        int lo = 0, hi = r[n-1], mid;
        while(hi-lo){
            mid = lo + (hi - lo)/2;
            if(f(mid)) hi = mid;
            else lo = mid + 1;
        }
        printf("Case %d: %d\n", tc, lo);
    }
}