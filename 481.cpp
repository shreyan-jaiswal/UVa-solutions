#include <cstdio>
#include <vector>
using namespace std;

int main(){
    vector<int> a;
    int tmp, dpi[10005], dpv[10005], res;
    while(~scanf("%d", &tmp)) a.push_back(tmp);
    int n = a.size();
    res = -1000;
    int resi = -1;
    for(int i = 0; i < n; i++){
        dpv[i] = 1;
        dpi[i] = -1;
        for(int j = i-1; j >= 0; j--){
            if(a[j] >= a[i]) continue;
            if(dpv[j] + 1 > dpv[i]){
                dpv[i] = dpv[j] + 1;
                dpi[i] = j;
            }
        }
        if(dpv[i] >= res){
            res = dpv[i];
            resi = i;
        }
    }
    printf("%d\n-\n", res);
    vector<int> output;
    while(resi != -1){
        output.push_back(a[resi]);
        resi = dpi[resi];
    }
    for(int i = output.size() - 1; i >= 0; i--) printf("%d\n", output[i]);
}