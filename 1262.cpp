#include <cstdio>
#include <set>
using namespace std;

set<char> one[5], two[5];
char pass[5];
int counter, n;

bool backtrack(int j){
    if(j == 5){
        counter++;
        if(counter == n){
            printf("%s\n", pass);
            return true;
        }
        return false;
    }   

    for (char x : one[j]){
        if(two[j].count(x)){
            pass[j] = x;
            if(backtrack(j + 1)) return true;
        }
    }
    return false;
}

int main(){
    int t; scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int j = 0; j < 5; j++){
            one[j].clear(); two[j].clear();
        }
        char x[5];
        for(int i = 0; i < 6; i++){
            scanf("%s", &x);
            for(int j = 0; j < 5; j++) one[j].insert(x[j]);
        }
        for(int i = 0; i < 6; i++){
            scanf("%s", &x);
            for(int j = 0; j < 5; j++) two[j].insert(x[j]);
        }
        counter = 0;
        if(!backtrack(0)) printf("NO\n");
    }
}