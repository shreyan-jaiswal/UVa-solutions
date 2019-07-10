#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int A, B, C, t, x, y, z, maxx, maxy;
    scanf("%d", &t);
    for(int tt = 0; tt < t; tt++){
        scanf("%d %d %d", &A, &B, &C);
        int maxx = ((int) cbrt((double) B)) + 1;
        for(x = 1; x < maxx; x++){
            for(y = x; y < 10000; y++){
                z = A - y - x;
                if(z > y && x*y*z == B && x*x+y*y+z*z == C){
                    printf("%d %d %d\n", x, y, z);
                    goto cnt;
                }
            }
        }
        printf("No solution.\n");
        cnt:;
    }
}