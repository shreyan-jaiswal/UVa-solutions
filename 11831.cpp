#include <cstdio>
using namespace std;

int n, m, s, next_row, next_col;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
char grid[101][101], instr[50100];

struct state_t{
    int row, col, dir;
};

state_t state;

int char_to_dir(char d){
    switch(d){
        case 'N': return 0;
        case 'L': return 1;
        case 'S': return 2;
        default: return 3;
    }
}

int main(){
    while(~scanf("%d %d %d", &n, &m, &s) && (n+m+s)){
        printf("%d %d %d\n", n, m, s);
        for(int i = 0; i < n; i++){
            char temp[101];
            scanf("%s", temp);
            for(int j = 0; j < m; j++){
                char tmp;
                tmp = temp[j];
                if(tmp == 'N' || tmp == 'L' || tmp == 'S' || tmp == 'O'){
                    state.row = i;
                    state.col = j;
                    state.dir= char_to_dir(tmp);
                    grid[i][j] = '.';
                }
                else{
                    grid[i][j] = tmp;
                }
            }
        }
        int ret = 0;
        scanf("%s", instr);
        for(int i = 0; i < s; i++){
            char tmp = instr[i];
            if(tmp == 'F'){
                next_row = state.row + dr[state.dir];
                next_col = state.col + dc[state.dir];
                if(0 <= next_row < n && 0 <= next_col < m && grid[next_row][next_col] != '#'){
                    state.row = next_row;
                    state.col = next_col;
                    if(grid[state.row][state.col] == '*'){
                        ret++;
                        grid[state.row][state.col] = '.';
                    }
                }
            }
            else if(tmp == 'D'){
                state.dir = (state.dir + 1) % 4;
            }
            else {
                state.dir = (state.dir + 3) % 4;
            }
            printf("%c %d %d %d\n", tmp, state.row, state.col, state.dir);
        }
        printf("%d\n", ret);
    }
}