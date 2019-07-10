#include <cstdio>
using namespace std;
typedef unsigned long int uint;
uint n, l, u, m;

int main(){
    while(~scanf("%lu %lu %lu", &n, &l, &u)){
        m = 0;
        for(int i = 31; i >= 0; i--){
            if(n & (1<<i)){
                if((m | ((1<<i)-1)) < l)
                    m |= (1<<i);
            }
            else {
                if((m | (1<<i))<= u)
                    m |= (1<<i);
            }
        }
        printf("%lu\n", m);
    }
}