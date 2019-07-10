#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int f, r, F[20], R[20];
double ans;

int main(){
    while(scanf("%d", &f), f){
        scanf("%d", &r);
        printf("%d %d\n", f, r);
        for(int i = 0; i < f; i++) scanf("%d", F+i);
        for(int i = 0; i < r; i++) scanf("%d", R+i);
        vector<double> res;
        for(int i = 0; i < f; i++){
            for(int j = 0; j < r; j++){
                printf("%.2lf\n", (double) F[i] / (double) R[j]);
                res.push_back((double) F[i] / (double) R[j]);
            }
        }
        sort(res.begin(), res.end());
        ans = 0.;
        for(int i = 0; i < res.size()-1; i++) ans = max(ans, res[i+1]-res[i]);
        printf("solution: %.2lf\n", ans);
    }
}