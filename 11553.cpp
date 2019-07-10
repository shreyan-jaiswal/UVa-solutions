#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int board[8][8];
    int t;
    int n;
    scanf("%d", &t);
    while(t--){
        int pb[8] = {0,1,2,3,4,5,6,7};
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                scanf("%d", &board[i][j]);
        int bestsum = INT_MAX;
        do{
            int sum = 0;
            for(int i = 0; i < n; i++) sum += board[i][pb[i]];
            //printf("debug %d\n", sum);
            bestsum = min(bestsum, sum);
        } while (next_permutation(pb, pb+n));
        printf("%d\n", bestsum);
        
    }
}