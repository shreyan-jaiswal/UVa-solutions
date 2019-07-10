#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
    long long a,b,c,d, b_max, c_max;
    for(a = 1; a < 212; a++){
        b_max = max((long long) cbrt((double) 2000/a), (2000-a)/3) + 1;
        for(b = a; b < b_max; b++){
            c_max = max((long long) sqrt((double) 200000/(a*b)), (2000-a-b)/2) + 1;
            for(c = b; c < c_max; c++){
                if( (a*b*c-1000000) == 0 || 1000000*(a+b+c) % (a*b*c-1000000) != 0) continue;
                d = 1000000*(a+b+c) / (a*b*c-1000000);
                if(d < c || a+b+c+d > 2000) continue;
                printf("%.2f %.2f %.2f %.2f\n", (double)a/100, (double)b/100, (double)c/100, (double)d/100);
            }
        }
    }
}