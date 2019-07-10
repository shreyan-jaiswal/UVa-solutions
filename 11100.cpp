#include <cstdio>
#include <map>
using namespace std;

int n, bags[10010];
map<int, int> freq;

int main(){
    while(~scanf("%d", &n), n){
        for(int i = 0; i < n; i++){
            int x;
            scanf("%d", &x);
            freq[x]++;
        }

        int k = 0;
        for(auto x : freq) k = max(k, x.second);
        printf("%d\n", k);
        while(k--){
            for(auto x : freq){
                if(freq[x.first] > 0){
                    printf("%d ", x.first);
                    freq[x.first]--;
                }
            }
            printf("\n");
        }
    }
}