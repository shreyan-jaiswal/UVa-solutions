#include <cstdio>
#include <vector>
using namespace std;

int n, b, m, csa_pop[10], pop[20], csa_temp, x, subsetsize, sum, best_s, best_pop;
vector<int> csa[10];

int main(){
    int case_number = 0;
    while(scanf("%d %d", &n, &b), n){
        if(case_number != 0) printf("\n");
        for(int i = 0; i < n; i++) scanf("%d", &pop[i]);
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            csa[j].clear();
            scanf("%d", &csa_temp);
            while(csa_temp--){
                scanf("%d", &x);
                csa[j].push_back(x-1);
            }
            scanf("%d", &csa_pop[j]);
        }
        best_pop = 0;
        best_s = (1 << b) - 1;
        for(int s = 0; s < (1<<n); s++){
            subsetsize = 0;
            for(int ss = s; ss; ss >>= 1) subsetsize += ss & 1;
            if(subsetsize != b) continue;
            sum = 0;
            for(int gu = 0; gu < n; gu++) if(s & (1 << gu)) sum += pop[gu];
            for(int gu = 0; gu < m; gu++){
                bool start_subtracting = false;
                for(int building : csa[gu]){
                    if(s & (1 << building)){
                        if(start_subtracting) sum -= csa_pop[gu];
                        else start_subtracting = true;
                    }
                }
            }
            if(sum > best_pop){best_pop = sum; best_s = s;}
        }
        printf("Case Number %d\n", ++case_number);
        printf("Number of Customers: %d\n", best_pop);
        printf("Locations Recommended:");
        for(int gu = 0; gu < n; gu++) if(best_s & (1 << gu)) printf(" %d", 1+gu);
        printf("\n");
    }
}