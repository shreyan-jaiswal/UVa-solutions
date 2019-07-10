#include <cstdio>
#include <algorithm>
using namespace std;

int n, d, r, morning[105], afternoon[105], ohours;

int main(){
    while(scanf("%d %d %d", &n, &d, &r), n){
        for(int i = 0; i < n; i++) scanf("%d", morning+i);
        for(int i = 0; i < n; i++) scanf("%d", afternoon+i);
        sort(morning, morning+n);
        sort(afternoon, afternoon+n, greater<int>());
        ohours = 0;
        for(int i = 0; i < n; i++) ohours += max(0, morning[i] + afternoon[i] - d);
        printf("%d\n", ohours * r);
    }
}