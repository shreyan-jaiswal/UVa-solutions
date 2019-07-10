#include <cstdio>
#include <iterator>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n, m;
    vector<int> p(100005);
    while(~scanf("%d", &n) && n){
        for(int i = 0; i < n; i++) scanf("%d", &p[i]);
        scanf("%d", &m);

        sort(p.begin(), p.begin() + n);

        int min_dist = 0x7fffffff;
        int dist;
        int book1 = 0, book2 = 0;

        for(int i = 0; i < n; i++){
            auto best_book = upper_bound(p.begin(), p.begin()+n, m-p[i]);
            if(best_book == p.begin()) continue;
            if(best_book - i == p.begin()) best_book--;
            if(best_book == p.begin()) continue;
            best_book--;
            dist = m - (p[i] + *best_book);
            if(dist < min_dist || (dist == min_dist && (abs(p[i]-*best_book) < book2 - book1))){
                min_dist = dist;
                book1 = min(p[i], *best_book);
                book2 = max(p[i], *best_book);
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", book1, book2);
    }
}