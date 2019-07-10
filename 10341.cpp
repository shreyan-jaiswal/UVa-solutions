#include <cstdio>
#include <cmath>
using namespace std;

int p,q,r,s,t,u;

long double f(long double x){
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

int main(){
    while(~scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u)){
        long double lo = 0., hi = 1., mid;
        if(f(hi) > 0 || f(lo) < 0){ printf("No solution\n"); continue; }
        for(int iter = 0; iter < 100; iter++){
            mid = (lo+hi)/2.;
            if(f(mid) > 0) lo = mid;
            else hi = mid;
        }
        printf("%6.4Lf\n", mid);
    }
}