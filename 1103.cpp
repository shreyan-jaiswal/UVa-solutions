#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int BLACK = 1;
const int WHITE = 0;
const int VIS = -1;

char convert[6] = {'W', 'A', 'K', 'J', 'S', 'D'};

int grid[210][210];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int h, w, w4;

vector<char> out;

int hex_to_dec(char hex){
    if(hex >= 97) return (int) hex - 87;
    return (int) hex - 48;
}

void fillwhite(int i, int j){
    grid[i][j] = VIS;
    for(int d = 0; d < 4; d++){
        int ip = i + dr[d];
        int jp = j + dc[d];
        if(0 <= ip && ip < h && 0 <= jp && jp < w && grid[ip][jp] == WHITE) fillwhite(ip, jp);
    }
}

int identify(int i, int j){
    int holes = 0;
    grid[i][j] = VIS;
    for(int d = 0; d < 4; d++){
        int ip = i + dr[d];
        int jp = j + dc[d];
        if(0 <= ip && ip < h && 0 <= jp && jp < w){
            if(grid[ip][jp] == WHITE){
                fillwhite(ip, jp);
                holes++;
            }
            else if(grid[ip][jp] == BLACK){
                holes += identify(ip, jp);
            }
        }
    }
    return holes;
}

int main(){
    int tc = 0;

    while(~scanf("%d %d", &h, &w4) && (h + w4)){
        w = 4 * w4;
        memset(grid, 0, sizeof grid); //WHITE
        for(int i = 0; i < h; i++){
            char tmp[55];
            scanf("%s", tmp);
            for(int j4 = 0; j4 < w4; j4++){
                int gu = hex_to_dec(tmp[j4]);
                for(int jr = 0; jr < 4; jr++){
                    grid[i][4*j4+jr] = (gu >> (3-jr)) & 1;
                }
            }
        }
        
        out.clear();
        
        for(int j = 0; j < w; j++){
            if(grid[0][j] == WHITE)
                fillwhite(0, j);
            if(grid[h-1][j] == WHITE)
                fillwhite(h-1, j);
        }

        for(int i = 0; i < h; i++){
            if(grid[i][0] == WHITE)
                fillwhite(i, 0);
            if(grid[i][w-1] == WHITE)
                fillwhite(i, w-1);
        };

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(grid[i][j] == BLACK){
                    out.push_back(convert[identify(i, j)]);
                }
            }
        }

        sort(out.begin(), out.end());

        printf("Case %d: ", ++tc);
        for(char letter : out)
            printf("%c", letter);
        printf("\n");
    }
}