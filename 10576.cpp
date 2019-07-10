#include <cstdio>
#include <climits>
using namespace std;

long long total, max_total, s, d;
int surplus;

void backtrack(int m){
    if (m >= 5){
        long long last5 = 0;
        for(int i = m-5; i < m; i++){
            if(surplus & (1 << i)) last5 += s;
            else last5 -= d;
        }
        if(last5 > 0) return;
    }
    if(m == 12){
        max_total = max_total  < total ? total : max_total;
        return;
    }

    surplus |= (1 << m);
    total += s;
    backtrack(m+1);

    surplus &= ~(1<<m);
    total -= s + d;
    backtrack(m+1);

    total += d;
}

int main(){
    while(~scanf("%lld %lld", &s, &d)){
        surplus = 0;
        total = 0;
        max_total = -999999999999;
        backtrack(0);
        if (max_total >= 0) printf("%lld\n", max_total);
        else printf("Deficit\n");
    }
}