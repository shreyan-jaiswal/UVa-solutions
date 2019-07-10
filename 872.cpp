#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int idx[257];
int letter[20];
int mask, n, t;
string s;
vector<int> gt[20];
vector<int> all_chars;
vector<int> order;

void solve(int i, int mask){
    if(mask == (1 << n) - 1){
        for(int i = 0; i < n; i++)
            printf("%c ", letter[order[i]]);
        printf("\n");
    }
    for(int x : gt[i])
        if((mask&(1<<x)) == 0)
            return;
    for(int j = 0; j < n; j++)
        if((mask&(1<<j)) == 0){
            order.push_back(j);
            solve(j,mask|(1<<j));
            order.pop_back();
        }
}

int main(){
    ios_base::sync_with_stdio(true);
    cin >> t;
    getline(cin, s);
    getline(cin, s);
    while(t--){
        getline(cin, s);
        stringstream ss1(s);
        char l;
        n=0;
        while(ss1 >> l){
            letter[n] = l;
            idx[l] = n;
            n++;
        }
        for(int i = 0; i < n; i++) gt[i].clear();
        getline(cin, s);
        stringstream ss2(s);
        string tmp;
        while(ss2 >> tmp){
            char ltc = tmp[0];
            char gtc = tmp[2];
            gt[idx[gtc]].push_back(idx[ltc]);
        }
        order.clear();
        for(int i = 0; i < n; i++){
            printf("solving %d\n", i);
            order.push_back(i);
            solve(i, 1<<i);
            order.pop_back();
        }
    }
}