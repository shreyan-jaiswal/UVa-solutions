#include <cstdio>
#include <vector>
using namespace std;

int A[20];
vector<int> subset;
int n, sum, t;
vector<vector<int> > solutions;

void printsubset(){
    for(int j = 0; j < subset.size(); j++){
        if(j) printf(" ");
        printf("%d", A[subset[j]]);
    }
    printf("\n");
}

int num1s(int s){
    int ret = 0;
    for(int ss = s; ss; ss >>= 1) ret += (ss & 1);
    return ret;
}

void backtrack(int i){
    if(i == n){
        if(sum == t){
            if(solutions.size() == 0) {solutions.push_back(subset); printsubset(); return;}
            vector<int> last_sol = solutions[solutions.size() - 1];
            if(last_sol.size() != subset.size()) {solutions.push_back(subset); printsubset(); return; }
            for(int j = 0; j < last_sol.size(); j++){
                if(A[subset[j]] != A[last_sol[j]]) {solutions.push_back(subset); printsubset(); return; }
            }

        }
        return;
    }
    if(sum > t) return;
    subset.push_back(i); sum+=A[i];
    backtrack(i+1);
    subset.pop_back(); sum-=A[i];
    backtrack(i+1);
}

int main(){
    while(scanf("%d %d", &t, &n), t){
        sum = 0; subset.clear(); solutions.clear();
        for(int i = 0; i < n; i++) scanf("%d", &A[i]);
        backtrack(0);
    }
}