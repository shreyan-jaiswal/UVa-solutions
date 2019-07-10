#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <climits>
using namespace std;

int dist(int i, int j){
    return abs(i/5-j/5)+abs(i%5-j%5);
}

int main(){
    int res[5], pop[25], m, r, c, t, D, minD, d, ans[5];
    scanf("%d", &t);
    while(t--){
        for(int i = 0; i < 25; i++) pop[i] = 0;
        scanf("%d", &m);
        while(m--){
            scanf("%d %d", &r, &c);
            scanf("%d", &pop[5*r+c]);
        }
        minD = INT_MAX;
        for(res[0] = 0; res[0] < 21; res[0]++)
            for(res[1] = res[0] + 1; res[1] < 22; res[1]++)
                for(res[2] = res[1] + 1; res[2] < 23; res[2]++)
                    for(res[3] = res[2] + 1; res[3] < 24; res[3]++)
                        for(res[4] = res[3] + 1; res[4] < 25; res[4]++){
                            D = 0;
                            for(int i = 0; i < 25; i++){
                                if(pop[i] == 0) continue;
                                d = dist(i, res[0]);
                                for(int o = 1; o < 5; o++) d = min(d, dist(i, res[o]));
                                D+=d*pop[i];
                            }
                            if(D < minD){
                                minD = D;
                                for(int o = 0; o < 5; o++) ans[o] = res[o];
                            }
                        }
        
        for(int o = 0; o < 5; o++){
            printf("%d", ans[o]);
            if(o == 4) printf("\n");
            else printf(" ");
        }
    }  
}